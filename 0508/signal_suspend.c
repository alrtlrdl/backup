#include <stdio.h>
#include <unistd.h>
#include <signal.h>
sigset_t new;
struct sigaction new;

void sig_handler() {
	printf("aaa\n");
}


int main(void) {
	new.sa_handler = sig_handler;
	sigfillset(&new.sa_mask);

	sigaction(SIGINT, &new, NULL);

	printf("pid : %d, asdasd\n", getpid());

	sigsuspend(&new);
	return 0;
}
