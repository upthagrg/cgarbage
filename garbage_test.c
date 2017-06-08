#include "./garbage.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
	int i=0;
	int** temp;
	temp = gmalloc(sizeof(int*)*16);
	for(i; i<16; i++){
		temp[i] = gmalloc(sizeof(int));
		temp[i][0] = i;
	}
	i=0;
	for(i; i<16; i++){
		printf("temp[%d}[0]: %d\n", i, temp[i][0]);
	}

	gclear();
	return 0;
}
