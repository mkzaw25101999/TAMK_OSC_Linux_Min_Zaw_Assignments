#include <stdio.h>
#include <stdlib.h>

int main() {
	int *array;
	int size = 10;

	array = (int *) malloc(size * sizeof(int));

	if (array == NULL){
		printf("Memory Allocation failed.\n");
		return 1;
	}

	for (int i = 0; i < size; i++){
		array[i] = i + 1;
	}

	printf("Array contents:\n");
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	
	free(array);
	array = NULL;

	return 0;
	
}
