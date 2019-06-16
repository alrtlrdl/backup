#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#define keynum 3319
#define msize 1024

int main () {
	int id;
	void *addr;
	int count = 0;
	char x[1024];
	if ( (id = shmget((key_t)keynum, msize, IPC_CREAT | 0660)) == -1){
		perror("shmget");
		exit(1);
	}

	if ((addr = shmat(id, (void *) 0, 0)) == (void *)-1){
		perror("shmat");
		exit(1);
	}

	while (1) {
		printf("보낼 문자열 : ");
		scanf("%s", x);
		sprintf((char *)addr, "%s", x);
		sleep(1);
	}
}

