#include "./garbage.h"
#include <stdio.h>
#include <stdlib.h>

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



int main(){
	int stop = 0; 
	int selection = 0;
	int size = 0;
	while(!stop){
		printf("Which test would you like to run?\n");
		printf("0: Exit\n");
		printf("1: General Test 1, allocates an array of integer pointers of a user defined size, then allocates one integer for each bucket and gives it a number. Uses gmalloc and gclear.\n");
		scanf("%d", &selection);
		switch(selection){
			case 0 :
				stop = 1;
				break;
			case 1:
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
