#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "string.h"
#include "ctype.h"

int getInt(char mensaje[]){
    int numero;
    printf("%s", mensaje);
    scanf("%d", &numero);
    return numero;
}
char getChar(char mensaje[]){
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    return letter;
}
void getString(char mensaje[], char cadena[]){
    char auxCadena[200];
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", auxCadena);
    strcpy(cadena, auxCadena);
}
float getFloat(char mensaje[]){
    float numero;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &numero);
    return numero;
}
