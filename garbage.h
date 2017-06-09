/***************************************************************************
 * Author: Glenn Upthagrove
 * Date: 06/08/2017
 * Title: garbage.h
 * Description: A simple API that allows the user to push all memory 
 * management down to this subsystem. To use, replace malloc(int) with 
 * gmalloc(int), and call gclear() before any point at which the program 
 * can terminate, such as a return in main or an exit(int) call. If the 
 * user desires to manually free(void*), they should use gfree(void*). 
***************************************************************************/
#ifndef GARBAGE
#define GARBAGE
//#define malloc gmalloc
//this is an idea to improve the API at a later date by replaceing all mallocs with gmalloc
//and possible main return with a greturn? that may not be possible but I shall work on this
//at some later date
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int inited = 0;
struct garbage_handler{
	void** handle;
	int size;
	int cap;
};
struct garbage_handler gh;
void _init_gh(){
	int i=0;
//	printf("in _init_gh\n");
	gh.handle = malloc(sizeof(void*)*8);
	for(i; i<8; i++){
		gh.handle[i] = NULL;
	}
	gh.size = 0;
	gh.cap = 8;
	inited = 1;
}
void _grow_gh(){
	void** temp;
	int i=0;
	temp = malloc(sizeof(void*)*gh.cap*2);
	for(i; i<gh.size; i++){
		temp[i] = gh.handle[i];
	}
	free(gh.handle);
	gh.handle = temp;
	gh.cap = gh.cap*2;
}
void _shrink_gh(){
	void** temp;
	int i=0;
	temp = malloc(sizeof(void*)*(gh.cap)/2);
	for(i; i<gh.size; i++){
		temp[i] = gh.handle[i];
	}
	free(gh.handle);
	gh.handle = temp;
	gh.cap = gh.cap/2;
}
void* gmalloc(int in){
	void* temp; 
//	printf("in gmalloc\n");
	if(inited == 0){
		_init_gh();
	}
	temp = malloc(in);
	gh.handle[gh.size] = temp;
	gh.size++;
	if(gh.size == gh.cap){
		_grow_gh();
	}
	return temp;
}
void gfree(void* in){
	int i=gh.size;
//	printf("in gfree\n");
	for(i; i>=0; i--){
		if(gh.handle[i] == in){
			break;
		}
		continue;
	}
	free(gh.handle[i]);
	if(i < gh.size){
		gh.handle[i] = gh.handle[gh.size];
	}
	gh.handle[gh.size] = NULL;
	gh.size--;
	if(gh.size == (gh.cap/4)){
		_shrink_gh();
	}
}
void gclear(){
	int i = gh.size;
//	printf("in gclear\n");
	if(gh.size > 0){
		for(i; i>=0; i--){
			gfree(gh.handle[i]);
		}
		free(gh.handle);
		gh.size = 0;
		gh.cap = 0;
		inited = 0;
	}
}
#endif
