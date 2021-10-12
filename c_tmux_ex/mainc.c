#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
		int index = atoi( argv[1] );

		printHelloWorld();
		printf( "%d\n", fibonacci( index ) );

		return 0;
}	
