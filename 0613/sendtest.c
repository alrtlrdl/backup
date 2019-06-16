#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFF_SIZE 1024

typedef struct {
	long data_type;
	int data_num;
	char data_buff[BUFF_SIZE];
}msg_t;

int main () {
	int msqid[2];
	int i, ndx = 0;
	msg_t data[2];
	
	for (i = 0; i < 2; i++) {
		if ((msqid[1] = msgget((key_t)1164, IPC_CREAT | 0666)) == -1) {
			perror("msgget");
			exit(1);
		}
	}

	while(1) {
		data[0].data_type = data[1].data_type = (ndx++ % 3) + 1;
		data[0].data_num = ndx;
		data[1].data_num = ndx + 10;
		
		for (i = 0; i < 2; i++) {
			sprintf(data[i].data_buff, "type=%ld, ndx=%d", data[i].data_type, ndx);
			if (msgsnd(msqid[i], &data[i], sizeof(msg_t) - sizeof(long), 0) == -1 ) {
				perror("msgsnd");
				exit(1);
			}
		}	
	}
}
