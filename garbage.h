#ifndef GARBAGE
#define GARBAGE
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
	gh.handle = malloc(sizeof(void*)*8);
	for(i; i<8; i++){
		gh.handle[i] = NULL;
	}
	gh.size = 0;
	gh.cap = 8;
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
	inited = 1;
}
void* gmalloc(int in){
	void* temp; 
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
}
void gclear(){
	int i = gh.size;
	for(i; i>=0; i--){
		gfree(gh.handle[i];
	}
	free(gh.handle);
	gh.size = 0;
	gh.cap = 0;
	inited = 0;
}
#endif
