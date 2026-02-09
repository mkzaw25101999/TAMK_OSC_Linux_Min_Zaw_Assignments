#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
	int fd;
	char buffer[1];

	fd = open("task3file.txt", O_RDONLY);
	if(fd == -1){
		perror("Open File Failed!");
		_exit(1);
	}

	if(read(fd, buffer,1) == -1){
		perror("Read File Failed!");
		_exit(2);
	}
	
	printf("Byte read: '%c' (ASCII: %d)\n", buffer[0], buffer[0]);

	if(close(fd) == -1){
		perror("Close File Failed!");
		_exit(3);
	}

	return 0;
}

