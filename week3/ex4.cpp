#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>

int main(int argc, char* argv[]){
	
	if(argc < 2){
		return 1;
	}
	
	pid_t pid = fork();
	
	if(pid < 0 ){
		return 1;
	}
	
	if(pid == 0){
		execvp(argv[1], argv + 1);
	exit(1);
	}
	else{
		int status;
		waitpid(pid, &status, 0);
		return 0;
	}
}
