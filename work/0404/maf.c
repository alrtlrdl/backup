#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int glob=42;


int main(void) {
	int var;
	pid_t pid;
	var = 88;
	if ((pid=fork()) < 0) {
		exit(1);
	}
	else if (pid == 0) {
		printf("childe pid : %d\n", getpid());
		glob++;
		var++;
	}
	else {
		printf("parent pid : %d\n", getpid());
		sleep(1);
	}
	printf("pid = %d, glob %d, var %d\n\n", getpid(), glob, var);
}
