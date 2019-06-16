#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction alarmhandler;

int count = 0;

void sig_handler() {
	printf("알람발생 %d\n", count++);
}

int main () {
	int i;
	
	alarmhandler.sa_handler = sig_handler;
	sigemptyset(&alarmhandler.sa_mask);

	sigaction(SIGALRM, &alarmhandler, NULL);
	alarm(5);

	for (i = 0; i < 10; i++) {
		printf("%d\n", i);
		sleep(1);
	}

	return 0;
}
