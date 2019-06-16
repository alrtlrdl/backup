//실행시 리시브할 데이터 타입 argv로 입력받기

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

int main (int argc, char *argv[]) {
	int msqid;
	int ndx = 0;
	msg_t data;

	if (argc < 2) {
		perror("plz more parameter");
		exit(1);
	}

	if ((msqid = msgget((key_t)1164, IPC_CREAT | 0666)) == -1) {
		perror("msgget");
		exit(1);
	}

	while(1) {
		if (msgrcv(msqid, &data, sizeof(msg_t) - sizeof(long), atoi(argv[1]), 0) == -1 ) {
			perror("msgrcv");
			exit(1);
		}

		printf("%d - %s\n", data.data_num, data.data_buff);
	}

}
