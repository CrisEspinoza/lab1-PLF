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
        case '=':
        	return 1;
        case ',':
        	return 1;
        case ';':
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

void revisar (char* palabra)
{
	char palabraaux[100];
	printf("%s\n", palabra);
	int palabraR = palabraReservada(palabra);
	if (palabraR == 1)
		printf("palabra reservada\n");
	int i = 0;
	while(palabraR == 0 && i < strlen(palabra))
	{
		
	}
}


void analizadoLexico(char* nombre)
{

	strcat(nombre,".txt");
	printf("%s\n", nombre);
	FILE* archivo = fopen(nombre,"r");
    int numero;
    char palabra[100];
    while (!feof(archivo))
    {
		fscanf(archivo,"%s\n",&palabra);   		  
		revisar(palabra);
    }    
    fclose(archivo);
}