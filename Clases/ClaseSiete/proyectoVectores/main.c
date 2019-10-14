/*
Este programa muestra un menu en pantalla para asignar a un total de 5 sillas en un aula:
1. un numero de legajo
2. la edad del estudiante con ese legajo
3. el nombre y apellido del alumno
y muestra:
1.    a. Todos los legajos
      b. El numero de legajo de una silla especifica.
2.    a. La mayor edad del grupo y el nombre del estudiante
      b. La menor edad del grupo y el nombre del estudiante
3.    a. Los estudiantes sentados ordenados por mayor edad
      b. Los estudiantes sentados ordenados por mayor edad
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

//void cargarVectorNombresYApellidos(char cadena[],char mensajeDeIngresoNombre[], char mensajeDeIngresoApellido[]);
void mostrarVector(int vectorDeEnteros[], int tam);
void mostrarVectorCaracteres(char vectorDeEnteros[], int tam);
void inicializarVector(int vectorDeEnteros[], int tam, int valorDeInicializacion);
void cargarVectorInicializado(int vectorDeEnteros[], int tam, char mensajeDeIngreso[], int valorDeInicializacion);
void firstToUpper(char cadena[]);
void cargarVectorNombresYApellidos(char cadena[],char mensajeDeIngresoNombre[], char mensajeDeIngresoApellido[]);
void pedirCadena (char mensaje[], char cadena[], int tam);
void validarTamCadena (char mensajeError[], char cadena[], int tam);
int estaLibre(int vectorDeEnteros[], int tam, int posicionAValidar, int valorInicializado);

int main()
{
    int legajos[5];
    int edades[5];
    char nombres[5][30];
    char apellidos[5][30];
    int i;

    inicializarVector(legajos,5,0);
    inicializarVector(edades,5,0);

    for(i=0;i<5;i++){
        pedirCadena("Ingrese un nombre: ", nombres[i], 30);
        firstToUpper(nombres[i]);
        pedirCadena("Ingrese un apellido: ", apellidos[i], 30);
        firstToUpper(apellidos[i]);
    }

    /*for(i=0;i<5;i++){

    }*/

    for(i=0;i<5;i++){
        printf("1.%s, %s.\n", apellidos[i], nombres[i]);
    }


    return 0;
}

void inicializarVector(int vectorDeEnteros[], int tam, int valorDeInicializacion){
    int i;
    for(i=0;i<tam;i++){
        vectorDeEnteros[i]=valorDeInicializacion;
    }
}

void cargarVectorInicializado(int vectorDeEnteros[], int tam, char mensajeDeIngreso[], int valorDeInicializacion){
    int i;
    printf("%s", mensajeDeIngreso);
    for(i=0; i<tam; i++){
        if(estaLibre(vectorDeEnteros, tam, i, valorDeInicializacion)==1){
            scanf("%d", &vectorDeEnteros[i]); //si esta libre se guarda un valor.
        }
    }
    printf("\n");
}

void mostrarVector(int vectorDeEnteros[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n", vectorDeEnteros[i]);
    }
    printf("\n");
}
void mostrarVectorCaracteres(char vectorDeEnteros[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%s\n", &vectorDeEnteros[i]);
    }
    printf("\n");
}

void firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(i=0;i<tam;i++){
        if(cadena[i]!='\0'){
            if(isspace(cadena[i])){
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}

void pedirCadena (char mensaje[], char cadena[], int tam)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    validarTamCadena(mensaje, cadena, tam);
}

void validarTamCadena (char mensajeError[], char cadena[], int tam)
{
    while (strlen(cadena)>tam)
    {
        printf(" ERROR .%s", mensajeError);
        fflush(stdin);
        scanf ("%[^\n]", cadena);
    }
}
int estaLibre(int vectorDeEnteros[], int tam, int posicionAValidar, int valorInicializado){
    int retorno = 0;
    if(vectorDeEnteros[posicionAValidar] == valorInicializado){
        retorno = 1;
    }
    return retorno;
}
