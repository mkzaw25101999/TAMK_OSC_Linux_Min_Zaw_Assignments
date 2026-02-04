#include <unistd.h>
#include <sys/types.h>

int main() {
	char *argv[] = { (char*)"/bin/ls", NULL};
	extern char **environ;

	execve("/bin/ls", argv, environ);

	return 1;

}
