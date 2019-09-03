#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void cargarVector(int vectorDeEnteros[], int tam);
void mostrarVector(int vectorDeEnteros[], int tam);
void mostrarNumerosNegativos(int vectorDeEnteros[], int tam);
void mostrarPromedioDePositivos(int vectorDeEnteros[], int tam);
int calcularMaximo (int vectorDeEnteros[], int tam);
void mostrarPosicionMaximo (int vectorDeEnteros[], int tam);
void mostrarMinimo(int vectorDeEnteros[], int tam);
void mostrarPosicionMinimo(int vectorDeEnteros[], int tam);
int show_option_menu(int vector[], int tam);

void cargarVector(int vectorDeEnteros[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("Ingrese un numero: \n");
        scanf("%d", &vectorDeEnteros[i]);
    }
    printf("\n\n");
}

void mostrarVector(int vectorDeEnteros[], int tam){
    printf("Estos son los numeros:\n");
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n", vectorDeEnteros[i]);
    }
    printf("\n\n");
}

void mostrarNumerosNegativos(int vectorDeEnteros[], int tam){
    printf("Estos son los numeros negativos:\n");
    int i;
    int flagNo_Negatives = 0;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]<0){
            printf("%d\n",vectorDeEnteros[i]);
        }
        else{
            flagNo_Negatives = 1;
        }
    }
    if(flagNo_Negatives == 1){
        printf("No hay numeros negativos\n\a\a");
    }
    printf("\n\n");
}

void mostrarPromedioDePositivos(int vectorDeEnteros[], int tam){
    int i;
    int acumuladorPositivos = 0;
    int contadorPositivos = 0;
    float promedioPositivos;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]>0){
            acumuladorPositivos = acumuladorPositivos + vectorDeEnteros[i];
            contadorPositivos++;
        }
    }
    promedioPositivos = (float) acumuladorPositivos / contadorPositivos;
    printf("Promedio de positivos: %.2f\n", promedioPositivos);
    printf("\n\n");
}
//calcularMaximo, mostrarMaximo, calcularPosicionMaximo, mostrarPosicionMaximo.

int calcularMaximo (int vectorDeEnteros[], int tam){
    int i;
    int flagMax = 0;
    int max;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]>max || flagMax == 0){
            max=vectorDeEnteros[i];
        }
        flagMax = 1;
    }
    return max;
}

void mostrarMaximo(int vectorDeEnteros[], int tam){
    int max = calcularMaximo(vectorDeEnteros, tam);
    printf("El max es: %d\n", max);
}

void mostrarPosicionMaximo (int vectorDeEnteros[], int tam){
    int i;
    int max = calcularMaximo(vectorDeEnteros, tam);
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]==max){
            printf("\nLa/s posicion/es del maximo es/son:");
            printf("%d\n", i);
        }
    }
    printf("\n\n");
}

int calcularMinimo(int vectorDeEnteros[], int tam){
    int i;
    int min;
    int flagMin = 0;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]<min || flagMin == 0){
            min=vectorDeEnteros[i];
        }
        flagMin=1;
    }
 return min;
}

void mostrar_Minimo_O_Maximo(int vectorDeEnteros[], int tam){
    int min = calcularMinimo(vectorDeEnteros, tam);
    int max = calcularMaximo(vectorDeEnteros, tam);
    int option;
    char option_continue='s';
    do{
        printf("\nIngrese 1 para mostrar minimo o 2 para mostrar maximo:\nPresione 3 para volver al menu principal.\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("El minimo es: %d.\n", min);
            mostrarPosicionMinimo(vectorDeEnteros, tam);
            break;
        case 2:
            printf("El maximo es: %d.\nPresione 3 para volver al menu principal.", max);
            mostrarPosicionMaximo(vectorDeEnteros, tam);
            break;
        default:
            option_continue='n';
            break;
        }
    }
    while(option_continue=='s');
    printf("\n\n");
}

void mostrarPosicionMinimo(int vectorDeEnteros[], int tam){
    int i;
    int min = calcularMinimo(vectorDeEnteros, tam);
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]==min){
            printf("\nLa/s posicion/es del maximo es/son:");
            printf("%d\n", i);
        }
    }
}

int show_option_menu(int vector[], int tam)
{
    int option;
    int option_continue = 's';
    do
    {
        printf("Elija una opcion: \n1.Cargar numeros.\n2.Mostrar todo.\n3.Mostrar negativos.\n4.Mostrar promedio de numeros positivos.\n5.Mostrar maximo numero y su posicion o minimo numero y su posicion.\n6.Salir.\n");//se puede crear una funcion que cree el menu, o un printf para cada option o que quede asi
        fflush(stdin);
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            cargarVector(vector, tam);
            break;
        case 2:
            mostrarVector(vector, tam);
            break;
        case 3:
            mostrarNumerosNegativos(vector, tam);
            break;
        case 4:
            mostrarPromedioDePositivos(vector, tam);
            break;
        case 5:
            mostrar_Minimo_O_Maximo(vector, tam);
            break;
        case 6:
            printf("Usted ha salido de la computadora.");
            option_continue ='n';
            break;
        default:
            printf("Dato invalido.\n");
            break;
        }
    }
    while(option_continue=='s');

    system("pause");
    system("cls");

    return 0;
}
