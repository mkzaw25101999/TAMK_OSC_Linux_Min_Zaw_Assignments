#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	const long size = 100000000;
	int silent = 0;

	for(int i =1; i < argc; i++) {
		if(strcmp(argv[i], "-s")==0) {
			silent = 1;
		}
	}

	long *table = malloc(size * sizeof(long));
	
	if(table == NULL) {
		printf("Memory allocation is failed!");
		return 1;
	}
	
	
	for(long i =0; i< size; i++){
		table[i] = i;
	}
	
	if(!silent){
		printf("Last 100 elements:\n");
		for(long i = size - 100; i < size; i++) {
			printf("Index: %ld Value: %ld\n:", i , table[i]);
		}
	}
	
	free(table);
	return 0;
}

