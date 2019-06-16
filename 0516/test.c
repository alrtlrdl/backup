#include <stdio.h>
#include <unistd.h>


int main () {
	int x, y;
	pid_t pid;

	if ((pid = fork()) < 0)
		perror("fork");
	else if (pid == 0) {
		printf("child \t\t%d\n", getpid());
		printf("child pid\t%d\n", pid);
	}
	else {
		sleep(5);
		printf("parents \t%d\n", getpid());
		printf("parents pid\t%d\n", pid);
	}

	return 0;
}
