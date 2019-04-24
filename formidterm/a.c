#include <stdlib.h>
#include <unistd.h>
#include "helpers.h"
int main ( void ) {
	if ( write (42 , " hello 42\n " , 9) != 9)
	//	err_sys ( " write error on FD 42\n " ) ;
	if ( write (43 , " hello 43\n " , 9) != 9)
	//	err_sys ( " write error on FD 43\n " ) ;
	exit ( EXIT_SUCCESS ) ;
} 
