#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction new;
struct sigaction old;

void sig_block() {
	printf("누름\n");
	sigaction
}

int main () {
	block.sa_handler = sig_block;

