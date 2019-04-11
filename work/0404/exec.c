#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

char *env_init[] = {"USER=unknown", "TERM=xterm", NULL};
int main(void) {
	pid_t pid;
	if ((pid = fork()) < 0) {
		exit(1);
	}else if (pid == 0) {
		if (execle("/tmp/echoall", "echoall", "foo", "bar", NULL, env_init) < 0)
			exit(1);
	}
	if (wait(NULL)<0)
		exit(1);
	if ((pid=fork()) <0)
		exit(1);
	else if (pid == 0){
		if (execlp("echoall", "echoall", "only 1 arg", NULL) < 0)
			exit(1);
	}
	exit(1);
}
