#include <stdio.h>
#include <unistd.h>

int main() {

	char cwd[1024];

	if(getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Current working directory: %s\n", cwd);
	} else {
		printf("Error getting current directory\n");
		return 1;
	}
	
	return 0;

}
