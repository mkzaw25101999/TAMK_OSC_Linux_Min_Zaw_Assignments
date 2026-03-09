#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define size 100000000
#define THREADS 10

long *table;

typedef struct {
	long start;
	long end;
} ThreadData;

void *fill_table(void *arg) {
	ThreadData *data = (ThreadData *) arg;
	
	for(long i = data -> start; i < data ->end; i++){
		table[i] = i;
	}
	
	return NULL;
}
	
int main(int argc, char *argv[]) {
	int silent = 0;

	for(int i = 1; i < argc; i++) {
		if(strcmp(argv[i], "-s")  == 0) {
			silent = 1;
		}
	}

	table = malloc(size * sizeof(long));
	if(table == NULL) {
		printf("Memory allocation is failed!");
		return 1;
	}
	
	pthread_t threads[THREADS];
	ThreadData threadData[THREADS];


	long chunk = size / THREADS;
	
	for(int i = 0; i < THREADS; i++) {
		threadData[i].start = i * chunk;
		threadData[i].end = (i== THREADS-1) ? size : (i+1) * chunk;
	
		pthread_create(&threads[i], NULL, fill_table, &threadData[i]);
	}
	
	for(int i = 0; i< THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	
	if(!silent) {
		printf("last 100 elements:\n");
		for(long i = size - 100; i < size; i++) {
			printf("Index: %ld Value: %ld\n", i, table[i]);
		}
	}
	
	free(table);

	return 0;
}
