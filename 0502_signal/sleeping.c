#include <stdio.h>
#include <unistd.h>
int main() {
	int i;
	for (i = 0; i < 1000; i++) {
		printf("%d, sleeping\n", getpid());
		sleep(1);
	}
}
