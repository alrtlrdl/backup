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
	int ndx = 0;
	msg_t data1;
	msg_t data2;
	if ((msqid[0] = msgget((key_t)1164, IPC_CREAT | 0666)) == -1) {
		perror("msgget");
		exit(1);
	}
	if ((msqid[1] = msgget((key_t)1163, IPC_CREAT | 0666)) == -1) {
		perror("msgget");
		exit(1);
	}

	while(1) {
		data2.data_type = data1.data_type = (ndx++ % 3) + 1;
		data1.data_num = ndx;
		data2.data_num = ndx + 10;

		sprintf(data1.data_buff, "type=%ld, ndx=%d", data1.data_type, ndx);
		sprintf(data2.data_buff, "type=%ld, ndx=%d", data2.data_type, ndx);	

		if (msgsnd(msqid[0], &data1, sizeof(msg_t) - sizeof(long), 0) == -1 ) {
			perror("msgsnd");
			exit(1);
		}
		if (msgsnd(msqid[1], &data2, sizeof(msg_t) - sizeof(long), 0) == -1 ) {
			perror("msgsnd");
			exit(1);
		}


	}

}
