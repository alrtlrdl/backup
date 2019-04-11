#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(void) {
	pid_t pid=fork();
	printf("\n\n\n");

	printf("before foek (%d)\n",getpid());
	if (pid <0 ){
		exit(EXIT_SUCCESS);
	}else if (pid == 0) {
		printf("from child (%d -> %d)\n",getpid(), getppid());
	}else {
		printf("from parent (%d)\n",getpid());
	}
	printf("bye (%d)\n", getpid());
	exit(EXIT_SUCCESS);
}
