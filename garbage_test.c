/**************************************************
Title: garbage_test.c
Author: Glenn Upthagrove
Date: 12/1/2018
Description: Testing suite for the cgarbage system.
**************************************************/
#include "./garbage.h"
#include <stdio.h>
#include <stdlib.h>

extern int debug;

void _general_test_1(int in){
	int i=0;
	int** temp;
	if (in < 1){
		printf("Size must be greater than 0\n");
		exit(12);
	}
	temp = gmalloc(sizeof(int*)*in);
	for(i; i<in; i++){
		temp[i] = gmalloc(sizeof(int));
		temp[i][0] = i;
	}
	i=0;
	for(i; i<in; i++){
		printf("temp[%d}[0]: %d\n", i, temp[i][0]);
	}
	gclear();
}
void _set_init(int in){
	set_initial(in);
	return;
}
void _debug(){
	toggle_debug();
	return;
}

int main(){
	int stop = 0; 
	int selection = 0;
	int size = 0;
	while(!stop){
		printf("Which test would you like to run?\n");
		printf("-1: Utilities\n");
		printf("0: Exit\n");
		printf("1: General Test 1, allocates an array of integer pointers of a user defined size, then allocates one integer for each bucket and gives it a number. Uses gmalloc and gclear.\n");
		printf("2: General Test 2, sets the initial capacity then runst general test 1\n");
		scanf("%d", &selection);
		switch(selection){
			case -1:
				printf("which utility would you like to use?\n");
				printf("1: Toggle debug: toggles the debug state, starts as false\n");
				printf("2: Set initial: changes the initial capacity, can only use once before a clear\n");
				scanf("%d", &selection);
				switch(selection){
					case 1: 
						_debug();
						if(debug){
							printf("Debug turned on\n");
						}
						else{
							printf("Debug turned off\n");
						}
						break;
					case 2:
						printf("Enter desired initial capacity\n");
						scanf("%d", &size);
						_set_init(size);
						break;
					default:
						printf("selection %d not recognized\n", selection);
						exit(1);
						break;
				}
				break;
			case 0 :
				stop = 1;
				break;
			case 1:
				printf("Enter desired number of integers to allocate\n");
				scanf("%d", &size);
				_general_test_1(size);
				break;
			case 2:
				printf("Enter desired initial capacity\n");
				scanf("%d", &size);
				_set_init(size);
				printf("Enter desired number of integers to allocate\n");
				scanf("%d", &size);
				_general_test_1(size);
				break;
			default: 
				printf("ERROR: %d does not match a test case as described\n", selection);
				exit(1);
				break;
		}
	}
	return 0;
}
