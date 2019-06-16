#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction newhandler;

void sig_handle () {
	int i;
	printf("crtl_c");
	
	for(i = 10; i > 0; i--) {
		printf("%d초 대기\n", i);
		sleep(1);
	}
}

int main() {

	newhandler.sa_handler = sig_handle;		
	sigfillset(&newhandler.sa_mask);

	sigaction(SIGINT, &newhandler, NULL);


	while(1) {
		printf("@@@@@@@@@@@@@@@\n");
		sleep(1);
	}
	return 0;
}
