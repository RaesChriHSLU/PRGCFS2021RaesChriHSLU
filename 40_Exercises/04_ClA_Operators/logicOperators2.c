#include <stdio.h>

int main(int argc, char *argv[] )

{
	if( argc != 3){
	//input not valid
	printf("Usage\n");
	printf("logicOperators Input1 Input2\n");
	}
	else
	{ //Input is valid


	printf("Number of input arguments: %d\n", argc );

	for( int i = 0; i < argc; i++ )
	{
		printf("Argument %d was %s\n", i, argv[i]);
	}
 }
	return 0;
}

/* 
	double e=2.718281828;
	
	printf("%0.15f", e);
*/
