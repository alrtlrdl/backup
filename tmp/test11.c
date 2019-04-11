#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int i, a[3];

void *thread1(){
	for (i = 0; i < 3; i++)
		a[i] = i;
}
void *thread2(){
	for (i = 0; i < 3; i++)
		a[i] = i;
}

int main () {
	while(1) { 
		pthread_t th1;
		pthread_t th2;

		pthread_create(&th1, NULL, thread1, NULL);
		pthread_create(&th1, NULL, thread1, NULL);


		pthread_join(th1,NULL);
		pthread_join(th1,NULL);

		for (i = 0; i<3; i++)
			printf("%d", a[i]);
		printf("\n");

		sleep(0.5);
	}
	return 0;
}
