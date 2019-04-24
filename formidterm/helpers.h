#include <stdio.h>
#include <stdlib.h>
void err_msg (const char *msg) {
	perror (msg) ;
}
void err_quit ( const char *msg) {
	printf ("%s\n" , msg) ;
	exit ( EXIT_FAILURE ) ;
}
