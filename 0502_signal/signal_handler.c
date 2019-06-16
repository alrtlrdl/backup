#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void (*handler)(int);

void bysignal () {
	printf("crtl_c");
	signal(SIGINT, handler);
	// 기존의 sigint값에 기존의 값을 저장해두었던 handler를 다시 붙임 -> 이제 다시 ctrl+c하면 죽음
	// 이거 대신에 signal(_, SIG_DFL);로 해도됨 -> 초기값으로 저장
}

int main() {

	handler = signal(SIGINT, bysignal);		
	//sigint값을 넣으면 두번째 파라미터 실행되게 만들고 handler에는 기존의 시그널 값을 저장시키는 거임

	while(1) {
		printf("@@@@@@@@@@@@@@@\n");
		sleep(1);
	}
	return 0;
}
