#include <stdio.h>

int main(int argc, char* argv[]){
	printf("You have entered %d arguments:\n", argc);

	if(argc < 2 ){
		printf("Usage: %s <name>\n", argv[0]);
		return 1;
	}
	
	printf("Hello %s!\n", argv[1]);
	return 0;
}

