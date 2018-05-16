#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.c"

int main(int argc, char** argv)
{
    if(validarEntradas(argc,argv) == 0)
    {
        return 0;
    }
    //printf("%s\n", argv[1]);
	analizadoLexico(argv[1],argv[2]);
	return 0;
}