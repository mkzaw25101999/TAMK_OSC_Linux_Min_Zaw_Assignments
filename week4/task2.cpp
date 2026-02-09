#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main() {
	int fd = open("fake.txt", O_RDONLY);

	if(fd == -1) {
		printf("errno: %d\n", errno);
		perror("Open Failed");
	}
	
	return 0;

}
