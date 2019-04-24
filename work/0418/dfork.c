#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main () {
	pid_t pid = fork();

	if (pid < 0)
		printf("error");
	else if (pid == 0){
		printf(" child pid = \t\t%d\n", getpid());
		pid = fork();
		if (pid  < 0)
			printf("error");
		else if  (pid == 0) {
			sleep(3);
			printf(" child's child pid = \t%d\n", getpid());
			printf(" child's child ppid = \t%d\n", getppid());
		}
		else
			printf(" chlid's parents pid = \t%d\n", getpid());
		exit(0);
	}
	else {
		printf(" parent pid = \t\t%d\n", getpid());
	}
	return 0;
}

