#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main (void) {
	pid_t pid;
	int i;
	for (i=0;i<5;i++){
		if ((pid=fork())<0)
			exit(1);
		else if (pid==0) {
			printf("bye from child %d : %d \n", i, getpid());
			exit(1);
		}
	}
	sleep(60);
	printf("bye from parent\n");
	exit(1);

}
