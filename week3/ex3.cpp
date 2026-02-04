#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>

int main() {

	pid_t pid = fork();

	if(pid < 0){
		return 1;
	}
	
	if(pid == 0){
		char *argv[] = {(char*)"/bin/ls", NULL};
		extern char **environ;

		execve("/bin/ls", argv, environ);

		exit(1);
	}
	else{
		int status;
		waitpid(pid, &status, 0);
	return 0;
	}

}
