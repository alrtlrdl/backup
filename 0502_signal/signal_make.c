#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){
	if (argc < 3)
		printf("사용법 : ./signal_make [SIGNAL NUM] [PID]\n");
	else 
		kill(atoi(argv[2]), atoi(argv[1]));

	return 0;

}

