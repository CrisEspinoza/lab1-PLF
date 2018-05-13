#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "function.h"

void cortar(char* palabraNueva,char* palaraAntigua,int inicio,int final)
{
    int i=0;
    while(i<final-inicio){
        palabraNueva[i] = palaraAntigua[inicio+i]; 
        i++;
    }
    palabraNueva[i] = '\0';
    return;
}

int operadoresYSimbolos(char palabra)
{
	switch(palabra){
		case '.':
            return 1;
        case ':':
            return 1;
        case ',':
            return 1;
        case ';':
            return 1;
        case '(':
            return 1;
        case ')':
            return 1;
        case '>':
            return 1;
        case '<':
            return 1;
        case '=':
            return 1;
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 1;
        case '/':
            return 1;
        default:
            return 0;
        }
}

int palabraReservada(char* palabra)
{
	if (strcmp(palabra,"const") == 0)
		return 1;
	if(strcmp(palabra,"var")== 0)
		return 1;
	if(strcmp(palabra,"procedure")== 0)
		return 1;
	if(strcmp(palabra,"instruccion")== 0)
		return 1;
	if(strcmp(palabra,"expresion")== 0)
		return 1;
	if(strcmp(palabra,"call")== 0)
		return 1;
	if(strcmp(palabra,"begin")== 0)
		return 1;
	if(strcmp(palabra,"end")== 0)
		return 1;
	if(strcmp(palabra,"if")== 0)
		return 1;
	if(strcmp(palabra,"then")== 0)
		return 1;
	if(strcmp(palabra,"while")== 0)
		return 1;
	if(strcmp(palabra,"do")== 0)
		return 1;
	if(strcmp(palabra,"add")== 0)
		return 1;
	return 0;
}

int letraMinuscula(char letra)
{
    if(letra>=97 && letra<=122)
    {
        return 1;
    }
    if (letra==-15) //Buscamos la letra ñ minuscula
    { 
        return 1;
    }
    return 0;
}

int letraMayuscula(char letra)
{
    if(letra>=65 && letra<=90)
    {
        return 1;
    }
    if(letra == -47) //Buscamos la letra ñ mayuscula
    {
        return 1;
    }
    return 0;
}

int letra (char letra)
{
    //printf("%c\n", letra );
    if ( letraMayuscula(letra) == 1 || letraMinuscula(letra) == 1)
    {
        return 1;
    }
    return 0;
}

int contarLetras(char* palabra, int pc)
{
    //printf("ENTRE ACA NLETRAS\n");
    int i = pc, cont = 0; 
    while(i < strlen(palabra))
    {
        if (letra(palabra[i]) == 1)
        {   
            //printf("letra :\n");
            cont++;
            i++;
        }
        else if(numero(palabra[i]) == 1)
        {
            cont++;
            i++;
        }
        else if (operadoresYSimbolos(palabra[i]) == 1)
        {
            return pc+cont;
        }
        else
        {
            //printf("palabra contados %d\n", cont+pc );
            return pc+cont; 
        }
    }
    //printf("palabra contados %d\n", cont );
    return pc+cont;
}

int numero (char numero)
{
    if(numero>=48 && numero<=57)
    {
        return 1;
    }        
    return 0;
}

int contarNumeros(char* palabra, int pc)
{
    //printf("ENTRE ACA NUMERS\n");
    int i = pc, cont = 0; 

    while(i < strlen(palabra))
    {
        if (numero(palabra[i]) == 1)
        {   
            cont++;
            i++;
        }
        else if (operadoresYSimbolos(palabra[i]))
        {
            return pc+cont;
        }
        else
            return pc;
    }
    if (palabra[i] == '\0')
        return pc + cont;
    else
        return pc;
}

int verificarCaracter( char caracter ) 
{
    if ( numero (caracter) == 1  )
    {
        return 0;
    }

    else if ( letra (caracter) == 1 ) 
    {   
        return 0;
    }

    else
        return 1;
}

int finalDePalabra(char *palabra,int pc)
{
    int cont = pc;
    while(cont <= strlen(palabra))
    {
        printf("%c - %d \n", palabra[cont] ,cont);
        if( verificarCaracter (palabra[cont]) == 1 || palabra[cont] == ' ' || operadoresYSimbolos(palabra[cont]) == 1 ) 
        {
            printf("Me sacaron\n");
            return cont;
        }
        cont++;
    }
    return -1;

}

int reconocerPalabraReservada(char *palabra, int pc)
{
    printf("%d\n", pc);
    int final = finalDePalabra(palabra,pc);
    printf("%d\n", pc);
    char palabraaux[100];
    if(final != -1)
    {
        printf("Inicio : %d - Final: %d \n", pc , final);
        cortar(palabraaux,palabra,pc,final);
        printf("%s\n",palabraaux );
        if(palabraReservada(palabraaux))
        {
            return final;
        }
    }
    return pc;
}

int revisar (char* palabra,int pc, int* respuesta,FILE* archivoSalida)
{
    int auxiliar = pc;
    int maximo = 0;
    char palabraaux[100];
    maximo = reconocerPalabraReservada(palabra,pc);
    if (auxiliar < maximo )  
    {
        printf("El valor del cont es: %d \n",maximo);
        *respuesta = 1;
        cortar(palabraaux,palabra,pc,maximo);
        escribirEnArchivo(archivoSalida,*respuesta,palabraaux,'n');
        return maximo;
    }
    if (operadoresYSimbolos(palabra[pc]) == 1)
    {
        *respuesta = 2;
        escribirEnArchivo(archivoSalida,*respuesta,"nada",palabra[pc]);
        return (auxiliar+1);
    }       
    //printf("PASE LA PRIMERA PARTE :O \n");
    maximo = contarNumeros(palabra,pc);
    if (auxiliar < maximo)
    {
        *respuesta = 3;
        escribirEnArchivo(archivoSalida,*respuesta,palabra,'n');
        //printf("Entre aca\n");
        auxiliar = maximo;   
        //printf("%d\n",  auxiliar);
    }
    maximo = contarLetras(palabra,pc);
    if (auxiliar < maximo)
    {
        *respuesta = 4;
        escribirEnArchivo(archivoSalida,*respuesta,palabra,'n');
        //printf("Entre aca 1 \n");
        auxiliar = maximo;
        //printf("%d\n", auxiliar );
    }
    if (maximo == pc)
    {
        *respuesta = -1;
        auxiliar++;
    }
    //printf("el nuevro pc es : ---- %d\n", auxiliar+pc );
    return auxiliar;
}

void escribirEnArchivo(FILE *archivoSalida, int respuesta,char* palabra,char caracter)
{
    switch(respuesta)
    {
        case 1:
            fprintf(archivoSalida,"%s\n",palabra);
            break;
        case 2:
            fprintf(archivoSalida,"%c\n",caracter);
            break;
        case 3:
            fprintf(archivoSalida,"NUMERO\n");
            break;
        case 4:
            fprintf(archivoSalida,"IDENTIFICADOR\n");
            break;
        default:
            break;
    }
}

void analizadoLexico(char* nombre, char* nombreS)
{
	FILE* archivo = fopen(nombre,"r");
    FILE *archivoSalida = fopen(nombreS,"w");
    int pc = 0;
    char palabra[100];
    char palabraaux[100];
    int respuesta = 0;
    while (!feof(archivo))
    {
		fscanf(archivo,"%s\n",&palabra);   
        //printf("Frase analizar: %s - largo de la palabra %d \n", palabra , strlen(palabra) );
        while ( pc < strlen(palabra) ) 
        {
            //printf("pc : %d - respuesta : %d \n", pc , respuesta );
            //cortar(palabraaux,palabra,pc,strlen(palabra));
            //printf("%s\n", palabraaux);
            pc = revisar(palabra,pc,&respuesta,archivoSalida);   
            //printf("MODIFICADO\n");
            //printf("pc : %d - respuesta : %d \n", pc , respuesta );
            //printf("-----------\n");
        }
        pc = 0;
    }    
    fclose(archivo);
}

int existeArchivo(char* nombre) 
{
    FILE* archivo = NULL;
    archivo = fopen(nombre,"r");
    if (archivo == NULL)
        return 0;
    else {
        fclose(archivo);
        return 1;
    }
    return 0;
}

int validarEntradas(int argc, char** argv)
{
    //Caso 1
    if (argc == 1)
    {
        printf("Error: Faltan par%cmetros en la l%cnea de comandos.\n",160,161);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    //Caso 2
    if (argc == 2)
    {
        printf("Error: Falta par%cmetro en la l%cnea de comandos.\n",160,161);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    //Caso 3 
    if( argc > 3 )
    {
        printf("Error: Demasiados par%cmetros en la l%cnea de comandos.\n",160,161);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    //Caso 4
    if (existeArchivo(argv[1]) == 0)
    {
        printf("Error: El archivo de entrada no existe.\n");
        return 0;
    }
    //Caso 5
    if (existeArchivo(argv[2]) == 1)
    {
        printf("Error: El archivo de salida ya existe.\n");
        return 0;
    }
    return 1;
}