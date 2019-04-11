#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(void) {
	pid_t pid;
	int status;
	if ((pid=fork()) <0)
		exit(1);
	else if (pid ==0) {
		printf("from child\n");
		
	sleep(10000000);
		exit(7);
	
	}
	
	else {
		if (wait(&status) != pid)
			exit(1);
		printf("from parent\n");
		if (WIFEXITED(status))
			printf("normal termination, exit status = %d\n",WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("abnormal termination, signal number = %d\n", WTERMSIG(status));
	}
	exit(1);
}
