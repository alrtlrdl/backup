#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "helpers.h"

void pr_exit ( int status ) {
	if (WIFEXITED ( status ) )
		printf ( " normal termination , exitstatus = %d\n " ,
				WEXITSTATUS ( status ) ) ;
	else if (WIFSIGNALED ( status ) )
		printf ( " abnormal termination , signal number = %d\n " ,
				WTERMSIG ( status ) ) ;
}

int main ( void )
{
	pid_t pid ;
	int status ;
	if ( ( pid = fork ( ) ) < 0)
		err_sys ( " fork error " ) ;
	else if ( pid == 0) /* child */
		exit (7);
	if ( wait (&status ) != pid ) /* wait for child */
		err_sys ( "wait error " ) ;
	pr_exit ( status ) ; /* and prin t i t s status */
	if ( ( pid = fork ( ) ) < 0)
		err_sys ( " fork error " ) ;
	else if ( pid == 0) /* child */
		abort ( ) ; /* generates SIGABRT */
	if ( wait (&status ) != pid ) /* wait for child */
		err_sys ( "wait error " ) ;
	pr_exit ( status ) ; /* and prin t i t s status */
	if ( ( pid = fork ( ) ) < 0)
		err_sys ( " fork error " ) ;
	else if ( pid == 0) /* child */
		status /= 0; /* divide by 0 generates SIGFPE */
	if ( wait (&status ) != pid ) /* wait for child */
		err_sys ( "wait error " ) ;
	pr_exit ( status ) ; /* and prin t i t s status */
	exit ( EXIT_SUCCESS ) ;
}
