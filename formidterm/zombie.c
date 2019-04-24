#include <stdio.h>
#include <unistd.h>
#include "helpers.h"
int main ( void ) {
	pid_t pid ;
	int i ;
	for ( i = 0; i <5; i ++) {
		if ( ( pid = fork ( ) ) < 0) {
		//	err_sys ( " fork error " ) ;
		} else if ( pid == 0) { /* ith child */
			printf ( " bye from child %d : %d\n " , i , getpid ( ) ) ;
			exit ( EXIT_SUCCESS ) ;
		}
		/* parent does nothing */
	}
	sleep (60); /* time window to observe zombies */
	printf ( "bye from parent\n" ) ;
	exit ( EXIT_SUCCESS ) ;
}

