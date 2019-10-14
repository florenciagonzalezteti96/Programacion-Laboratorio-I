#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "string.h"
#include "ctype.h"
//recibe le array
int mostrarMaximaEdadYLegajo(int edades[], int legajo[], int tam){
    int max = calcularMaximo(edades, tam);
    int i;
    printf("Mayores edades:\n");
    for(i=0;i<tam;i++){
        if(edades[i]==max){
            printf("%d\t%d\t%d\t\n", edades[i], legajo[i], i+1);
        }
    }

}
void mostrarDatos(int vectorDeLegajo[], int tam, int edades[]){
    int i;
    printf("Sillas\tLegajos\tEdades\t\n\n");
    for(i=0;i<tam;i++){

        printf("%d\t%d\t%d\t\n",i+1, vectorDeLegajo[i], edades[i]);
    }

}
int encontrarPrimeraPosicionLibre(int vectorDeEnteros[], int tam, int valorInicial){
    int i;
    int retorno = -1;
    for(i=0;i<tam;i++){
        if(vectorDeEnteros[i]==valorInicial){
            retorno = i;
            break;
        }
    }
    return retorno;
}
int cantidadLugaresOcupados(int vectorDeEnteros[], int tam, int valorInicial){
    int i;
    int contador = 0;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]!=valorInicial){
            contador++;
        }
    }
    return contador;
}
int cantidadLugaresLibres(int vectorDeEnteros[], int tam, int valorInicial){
    int i;
    int contador = 0;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]==valorInicial){
            contador++;
        }
    }
    return contador;
}

void cargarVector(int vectorDeEnteros[], int tam, char mensajeDeIngreso[]){
    int i;
    printf("%s", mensajeDeIngreso);
    for(i=0; i<tam; i++){
        scanf("%d", &vectorDeEnteros[i]);
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

void cargarVectorNombresYApellidos(char cadena[],char mensajeDeIngresoNombre[], char mensajeDeIngresoApellido[])
{

    char auxNombre[30];
    char auxApellido[30];
    pedirCadena(mensajeDeIngresoNombre, auxNombre, 30);
    pedirCadena(mensajeDeIngresoApellido, auxApellido, 30);
    strcat(auxApellido, ", ");
    strcpy(auxApellido, auxNombre);
    cadena = auxApellido;

}

void pedirCadena (char mensaje[], char cadena[], int tam)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    validarTamCadena(mensaje, cadena, tam);
    firstToUpper(cadena);
}

void validarTamCadena (char mensajeError[], char cadena[], int tam)
{
    while (strlen(cadena)>tam)
    {
        printf("%s", mensajeError);
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

int estaOcupadoConEdad(int vectorDeEnteros[], int tam, int posicion, int legajo, int edad, int edades[], int valorInicial){
    int retorno = -1;
    if(posicion<tam){
        if(estaLibre(vectorDeEnteros, tam, posicion,valorInicial)==1){
            edades[posicion]=edad;
            vectorDeEnteros[posicion]=legajo;
            retorno = 0;
        }
    }
    return retorno;
}

int estaOcupado(int vectorDeEnteros[], int tam, int posicion, int nuevoValor, int valorInicial){
    int retorno = -1;
    if(posicion<tam){
        if(estaLibre(vectorDeEnteros, tam, posicion,valorInicial)==1){
            vectorDeEnteros[posicion]=nuevoValor;
            retorno = 0;
        }
    }
    return retorno;
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

void hardcodearVector(int vectorDeEnteros[], int tam){
    int vectorAux[]={55, 11, 33, 22, 44};
    int i;
    for(i=0; i<tam; i++){
        vectorDeEnteros[i] = vectorAux[i];
    }
}

void hardcodearVectorEdades(int vectorDeEnteros[], int tam){
    int vectorAux[]={98,19,81,91,98};
    int i;
    for(i=0; i<tam; i++){
        vectorDeEnteros[i] = vectorAux[i];
    }
}

int calcularMaximo (int vectorDeEnteros[], int tam){
    int i;
    int max;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]>max || i == 0){
            max=vectorDeEnteros[i];
        }
    }
    return max;
}

int calcularMinimo(int vectorDeEnteros[], int tam){
    int i;
    int min;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]<min || i == 0){
            min=vectorDeEnteros[i];
        }
    }
 return min;
}
void getString(char mensaje[], char cadena[]){
    char auxCadena[200];
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", auxCadena);
    strcpy(cadena, auxCadena);
}
