#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction newhandler;
struct sigaction oldhandler;

void sig_handle () {
	printf("crtl_c");
	sigaction(SIGINT, &oldhandler, NULL);
}

int main() {

	newhandler.sa_handler = sig_handle;		
	sigemptyset(&newhandler.sa_mask);

	sigaction(SIGINT, &newhandler, &oldhandler);


	while(1) {
		printf("@@@@@@@@@@@@@@@\n");
		sleep(1);
	}
	return 0;
}
