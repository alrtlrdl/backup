#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char buf[] = "wirte to stdout\n";
int main(void) {
	pid_t pid;
	if (write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf))
		exit(1);
	printf("printf by %d : before fork\n", getpid());
	if ((pid =fork()) <0){
		exit(1);
	}
	else if (pid == 0)
		printf("printf by %d : from child\n", getpid());
	else 
		printf("printf by %d : from parent\n", getpid());
	printf("printf by %d: bye\n", getpid());

	exit(1);
	}

