#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Get_Dato.h"
int getInt(char mensaje[]){
    int numero;
    printf("Ingrese %s: ", mensaje);
    scanf("%d", &numero);
    return numero;
}
char getChar(char mensaje[]){
    char letter;
    printf("Ingrese %s: ", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    return letter;
}
void getString(char mensaje[], char cadena[]){
    char auxCadena[200];
    printf("Ingrese %s: ", mensaje);
    fflush(stdin);
    scanf("%[^\n]", auxCadena);
    strcpy(cadena, auxCadena);

}
int getFloat(char mensaje[]){
    float numero;
    printf("Ingrese %s: ", mensaje);
    scanf("%f", &numero);
    return numero;
}
int getIntConRango(int* valor, char mensaje[], char mensajeError[], int min, int max){
    int retorno = 0;
    printf("%s", mensaje);
    scanf("%d", valor);
    while(*valor<min || *valor>max){
        printf("Error, %s\a\a", mensajeError);
        scanf("%d", valor);
        retorno = 1;
    }
    return retorno;
}
int getFloatConRango(float* valor, char mensaje[], char mensajeError[], float min, float max){
    float retorno = 0;
    printf("%s", mensaje);
    scanf("%f", valor);
    while(*valor<min || *valor>max){
        printf("Error, %s\a\a", mensajeError);
        scanf("%f", valor);
        retorno = 1;
    }
    return retorno;
}
int getStringLetras(char cadena[]){
    int i;
    int flag = 0;
    int tam = strlen(cadena);
    for(i=0;i<tam;i++){
        if(cadena[i] != '\0'){
            if ((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A'||cadena[i]>'Z') && cadena[i]!=' '){
                flag = 1; //si es menor a 'a' en ASCII o mayor a 'z' en ASCII y si en la cadena hay un espacio
            }
        }
    }
    return flag;
}


