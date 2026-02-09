#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>

using namespace std;

int main() {
	int fd;
	char byteWrite;

	cout << "Enter a character to write to file: ";
	cin >> byteWrite;

	fd = creat("task3file.txt", 0644);

	if(fd == -1) {
	 	perror("Error creating file");
		_exit(1);
	}

	cout <<"File created successfully fd = " << fd << ")\n";

	ssize_t byteWite = write(fd, &byteWrite, 1);

	if(byteWrite == -1){
		perror("Error writing to file");
		_exit(2);
	}

	cout << "Successfully wrote " << byteWrite << " byte to file\n";

	if(close(fd) == -1){
		perror("Error closing file");
		_exit(3);
	}

	cout << "File is closed successfully\n";

	return 0;

}
