#include <signal.h>
#include <stdio.h>

int main() {
	sigset_t s;

	sigemptyset(&s);
	sigaddset(&s, SIGINT);

	switch(sigismember(&s, SIGINT)) {
		case 0 : printf("SIGINT는 포함되어 있지 않습니다.\n");
				 break;

		case 1 : printf("SIGINT가 포함되어 있습니다.\n");
				 break;

		default : printf("sigismember() 호출에 실패했습니다.\n");

		}
	switch(sigismember(&s, SIGSYS)) {
	case 0 : printf("SIGSYS는 포함되어 있지 않습니다.\n");
			 break;

	case 1 : printf("SIGSYS가 포함되어 있습니다.\n");
			 break;

	default : printf("sigismember() 호출에 실패했습니다.\n");

	}
}
