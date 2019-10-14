#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void inicializarVector(int vectorDeEnteros[], int tam, int valorDeInicializacion);
void cargarVector(int vectorDeEnteros[], int tam, char mensajeDeIngreso[]);
void mostrarVector(int vectorDeEnteros[], int tam);
void mostrarNumerosNegativos(int vectorDeEnteros[], int tam);
void mostrarPromedioDePositivos(int vectorDeEnteros[], int tam);
int calcularMaximo (int vectorDeEnteros[], int tam);
void mostrarMaximo(int vectorDeEnteros[], int tam);
void mostrarPosicionMaximo (int vectorDeEnteros[], int tam);
int calcularMinimo(int vectorDeEnteros[], int tam);
void mostrar_Minimo_O_Maximo(int vectorDeEnteros[], int tam);
void mostrarMinimo(int vectorDeEnteros[], int tam);
void mostrarPosicionMinimo(int vectorDeEnteros[], int tam);
int show_option_menu(int vector[], int tam);
void ordenarDeMayorAMenor(int vectorDeEnteros[], int tam);
void ordenarDeMenorAMayor(int vectorDeEnteros[], int tam);
void menu_Ordenar_Vector(int vectorDeEnteros[], int tam);

void inicializarVector(int vectorDeEnteros[], int tam, int valorDeInicializacion){
    int i;
    for(i=0;i<tam;i++){
        vectorDeEnteros[i]=valorDeInicializacion;
    }
}

void cargarVector(int vectorDeEnteros[], int tam, char mensajeDeIngreso[]){
    int i;
    printf("%s", mensajeDeIngreso);
    for(i=0; i<tam; i++){
        scanf("%d", &vectorDeEnteros[i]);
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

void mostrarNumerosNegativos(int vectorDeEnteros[], int tam){
    printf("Estos son los numeros negativos:\n");
    int i;
    int flagNo_Negatives = 0;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]<0){
            printf("%d\n",vectorDeEnteros[i]);
            flagNo_Negatives = 1;
        }
    }
    if(flagNo_Negatives == 0){
        printf("No hay numeros negativos.\n");
    }
    printf("\n");
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
    printf("\n");
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

void mostrarMaximo(int vectorDeEnteros[], int tam){
    int max = calcularMaximo(vectorDeEnteros, tam);
    printf("El max es: %d\n", max);
}

void mostrarPosicionMaximo (int vectorDeEnteros[], int tam){
    int i;
    int max = calcularMaximo(vectorDeEnteros, tam);
    printf("\nLa/s posicion/es del maximo es/son:");
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]==max){
            printf("%d\n", i);
        }
    }
    printf("\n");
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
            printf("El maximo es: %d.\n", max);
            mostrarPosicionMaximo(vectorDeEnteros, tam);
            break;
        default:
            option_continue='n';
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}

void mostrarMinimo(int vectorDeEnteros[], int tam){
    int min = calcularMinimo(vectorDeEnteros, tam);
    printf("El min es: %d\n", min);
}

void mostrarPosicionMinimo(int vectorDeEnteros[], int tam){
    int i;
    int min = calcularMinimo(vectorDeEnteros, tam);
    printf("\nLa/s posicion/es del minimo es/son:");
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]==min){
            printf("%d\n", i);
        }
    }
}

int show_option_menu(int vector[], int tam){
    int option;
    int option_continue = 's';
    inicializarVector(vector, tam, 0);
    printf("Los elementos del vector se han inicializado en 0 automaticamente. Presione 1 para cambiar su valor.\n\n");
    do{
        printf("Elija una opcion:\n1.Cargar numeros.\n2.Mostrar todo.\n3.Mostrar negativos.\n4.Mostrar promedio de numeros positivos.\n5.Mostrar maximo numero y su posicion o minimo numero y su posicion.\n6.Ordenar vector.\n7.Salir.\n");//se puede crear una funcion que cree el menu, o un printf para cada option o que quede asi
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            cargarVector(vector, tam, "Ingrese los numeros: \n");
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
            menu_Ordenar_Vector(vector, tam);
            break;
        case 7:
            printf("Usted ha salido de la computadora.\n");
            option_continue ='n';
            break;
        default:
            printf("Dato invalido.\n");
            break;
        }
    }while(option_continue=='s');
    system("pause");
    system("cls");
    return 0;
}

void ordenarDeMenorAMayor(int vectorDeEnteros[], int tam){
    //quick sort
    //burbujeo ->
    int indicePrimerVector;
    int indiceSegundoVector;
    int aux;
    for(indicePrimerVector=0;indicePrimerVector<tam-1;indicePrimerVector++){
        for(indiceSegundoVector=indicePrimerVector+1;indiceSegundoVector<tam;indiceSegundoVector++){
            if(vectorDeEnteros[indicePrimerVector]>vectorDeEnteros[indiceSegundoVector]){
                /*C = A
                A = B criterio de ordenamiento
                B = C */
                aux = vectorDeEnteros[indicePrimerVector];
                vectorDeEnteros[indicePrimerVector] = vectorDeEnteros[indiceSegundoVector];
                vectorDeEnteros[indiceSegundoVector] = aux;
            }
        }
    }
    mostrarVector(vectorDeEnteros, tam);
}

void ordenarDeMayorAMenor(int vectorDeEnteros[], int tam){
    int indicePrimerVector;
    int indiceSegundoVector;
    int aux;
    for(indicePrimerVector=0;indicePrimerVector<tam-1;indicePrimerVector++){
        for(indiceSegundoVector=indicePrimerVector+1;indiceSegundoVector<tam;indiceSegundoVector++){
            if(vectorDeEnteros[indicePrimerVector]<vectorDeEnteros[indiceSegundoVector]){
                /*C = A
                A = B criterio de ordenamiento
                B = C */
                aux = vectorDeEnteros[indicePrimerVector];
                vectorDeEnteros[indicePrimerVector] = vectorDeEnteros[indiceSegundoVector];
                vectorDeEnteros[indiceSegundoVector] = aux;
            }
        }
    }
    mostrarVector(vectorDeEnteros, tam);
}

void menu_Ordenar_Vector(int vectorDeEnteros[], int tam){
    int option;
    char option_continue='s';
    do{
        printf("\nIngrese 1 para ordenar de menor a mayor o 2 para ordenar de mayor a menor:\nPresione 3 para volver al menu principal.\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("El vector ordenado de menor a mayor es: \n");
            ordenarDeMenorAMayor(vectorDeEnteros, tam);
            break;
        case 2:
            printf("El vector ordenado de mayor a menor es: \n");
            ordenarDeMayorAMenor(vectorDeEnteros, tam);
            break;
        default:
            option_continue='n';
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}

int partition(int vectorDeEnteros[], int inicio, int fin){
    int i = inicio + 1;
    int piv = vectorDeEnteros[inicio];
    //el primer elemento es el pivote
    for(int j = inicio + 1; j<= fin; j++){
        //reordeno el array, poniendo los elementos que sean menores que el pivote de un lado y los que sean mayores del otro.
        if(vectorDeEnteros[j]<piv){
            vectorDeEnteros[i]=vectorDeEnteros[j];
            i += 1;
        }
    }
}
