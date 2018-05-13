//Acá tenemos lo escabezados de las funciones a ocupar


void cortar(char* palabraNueva,char* palaraAntigua,int inicio,int final);
int operadoresYSimbolos(char palabra);
int numero (char numero);
int palabraReservada(char* palabra);
int revisar (char* palabra, int pc, int* respuesta,FILE* archivoSalida);
void analizadoLexico(char* nombre, char* nombreS);
int contarNumeros(char* palabra, int pc);
int letraMinuscula(char letra);
int letraMayuscula(char letra);
int letra (char letra);
int contarLetras(char* palabra, int pc);
void escribirEnArchivo(FILE *archivoSalida, int respuesta, char* palabra, char caracter);
int validarEntradas(int argc, char** argv);
int existeArchivo(char* nombre);
int finalDePalabra(char *palabra,int pc);
int reconocerPalabraReservada(char *palabra, int pc);
int verificarCaracter( char caracter ) ;