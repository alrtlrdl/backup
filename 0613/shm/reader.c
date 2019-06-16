#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define keynum 77357735
#define msize 1024

int main () {
	int id;
	void *addr;

	if ( (id = shmget((key_t)keynum, msize, IPC_CREAT | 0660)) == -1){
		perror("shmget");
		exit(1);
	}

	if ((addr = shmat(id, (void *) 0, 0)) == (void *)-1){
		perror("shmat");
		exit(1);
	}

	while (1) {
		printf("%s\n", (char *)addr);
		sleep(1);
	}
}

