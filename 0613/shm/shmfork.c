#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define keynum 9802
#define msize 1024

int main () {
	int id;
	void *addr;
	int *x;
	int pid;

	if ( (id = shmget((key_t)keynum, msize, IPC_CREAT | 0660)) == -1){
		perror("shmget");
		exit(1);
	}

	if ((addr = shmat(id, (void *) 0, 0)) == (void *)-1){
		perror("shmat");
		exit(1);
	}
	
	x = (int *)addr;
	pid = fork();

	if (pid == 0) {
		*x = 1;
		while(1) {
			*x = *x + 1;
			printf("child: %d\n", *x);
			sleep(1);
		}
	}

	else if (pid > 0) {
		while(1) {
			sleep(1);
			printf("parents: %d\n", *x);
		}
	}
}

