#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define SOCK_PATH "/tmp/s1521164_socket"

struct math {
	char x[10];
	int a, b, c;
};

struct math str;

void *fun(void *data) {
	if (!strcmp(str.x,"+")) 
		str.c = str.a + str.b;
	if (!strcmp(str.x,"-"))
		str.c = str.a - str.b;
	if (!strcmp(str.x,"*"))
		str.c = str.a * str.b;
	if (!strcmp(str.x,"/"))
		str.c = str.a / str.b;
}


int main () {
	int s, s2, len, a, status;
	unsigned t;
	struct sockaddr_un local, remote;
	pthread_t p_thread;
	
	a = 0;

	if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	local.sun_family = AF_UNIX;
	strcpy(local.sun_path, SOCK_PATH);
	unlink(local.sun_path);
	len = strlen(local.sun_path) + sizeof(local.sun_family);

	if (bind(s, (struct sockaddr *)&local, len) == -1) {
		perror("bind");
		exit(1);
	}

	if (listen(s, 5) == -1) {
		perror("listen");
		exit(1);
	}

	for (;;) {
		int done, n;
		printf("Waiting for a connection...\n");
		t = sizeof(remote);

		if ((s2 = accept(s, (struct sockaddr *)&remote, &t)) == -1) {
			perror("accept");
			exit(1);
		}

		printf("Connected.\n");

		done = 0;

		do {
			n = recv(s2, &str, sizeof(str), 0);
			if (n < 0) {
				done = 1;
			}
			
			if (pthread_create(&p_thread, NULL, fun, (void *)&a) < 0 )
				perror("thread");
						
			pthread_join(p_thread, (void **)&status);

			if (!done) {
				if(send(s2, &str, sizeof(str), 0) <0) {
					perror("send");
					done = 1;
				}
			}

			if (!strcmp(str.x,"q")||!strcmp(str.x,"qq")) {
				printf("클라이언트 연결 종료\n");
				break;
			}

		}while (!done);
		
		if (!strcmp(str.x, "qq")){
			printf("서버종료\n");
			break;
		}

		close(s2);
	}
	return 0;
}
