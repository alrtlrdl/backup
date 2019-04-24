#include "helpers.h "
#define BUFFSIZE 4096
int main ( void ) {
	char buf [ BUFFSIZE ] ;
	while ( fgets ( buf , BUFFSIZE , s tdin ) )
		if ( fputs ( buf , stdout ) == EOF )
			err_sys ( " fputs error " ) ;
	exit ( EXIT_SUCCESS ) ;
}

