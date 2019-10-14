#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "input.h"
#include "string.h"
#include "ctype.h"
/** FUNCIONES BASICAS */
void inicializarcadena(int cadena[], int tam, int valorInicial){
    int i;
    for(i=0;i<tam;i++){
        cadena[i]=valorInicial;
    }
}
void cargarcadenaInicializado(int cadena[], int tam, char mensajeDeIngreso[], int valorInicial){
    int i;
    printf("%s", mensajeDeIngreso);
    for(i=0; i<tam; i++){
        if(estaLibre(cadena, tam, i, valorInicial)==1){
            scanf("%d", &cadena[i]); //si esta libre se guarda un valor.
        }
    }
    printf("\n");
}
void cargarcadena(int cadena[], int tam, char mensajeDeIngreso[]){
    int i;
    printf("%s", mensajeDeIngreso);
    for(i=0; i<tam; i++){
        scanf("%d", &cadena[i]);
    }
    printf("\n");
}
void mostrarcadena(int cadena[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n", cadena[i]);
    }
    printf("\n");
}
void hardcodearcadena(int cadena[], int tam){
    int cadenaAux[]={0,0,0,0,0};
    int i;
    for(i=0; i<tam; i++){
        cadena[i] = cadenaAux[i];
    }
}

int estaOcupado(int cadena[], int tam, int posicion, int nuevoValor, int valorInicial){
    int retorno = -1;
    if(posicion<tam){
        if(estaLibre(cadena, tam, posicion,valorInicial)==1){
            cadena[posicion]=nuevoValor;
            retorno = 0;
        }
    }
    return retorno;
}
int estaLibre(int cadena[], int tam, int posicion, int valorInicial){
    int retorno = 0;
    if(cadena[posicion] == valorInicial){
        retorno = 1;
    }
    return retorno;
}
int encontrarPrimeraPosicionLibre(int cadena[], int tam, int valorInicial){
    int i;
    int retorno = -1;
    for(i=0;i<tam;i++){
        if(cadena[i]==valorInicial){
            retorno = i;
            break;
        }
    }
    return retorno;
}
int cantidadPosicionesOcupados(int cadena[], int tam, int valorInicial){
    int i;
    int contador = 0;
    for(i=0; i<tam; i++){
        if(cadena[i]!=valorInicial){
            contador++;
        }
    }
    return contador;
}
int cantidadPosicionesLibres(int cadena[], int tam, int valorInicial){
    int i;
    int contador = 0;
    for(i=0; i<tam; i++){
        if(cadena[i]==valorInicial){
            contador++;
        }
    }
    return contador;
}
/** FUNCIONES DE ENTEROS */
int buscarValorInt(int cadena[], int tam, int num){
    int i;
    int retorno = 0;
    for(i=0; i<tam; i++){
        if(cadena[i]==num){
            retorno = 1;
        }
    }
    return retorno;
}
void mostrarPosicionNumero(int cadena[], int tam, int num){
    int i;
    int si_Existe = buscarValorInt(cadena, tam, num);
    if(si_Existe!=0){
        printf("\nLa posicion del numero es:");
        for(i=0; i<tam; i++){
            if(cadena[i]==num){
                printf("%d\n", i);
            }
        }
    }else{
        printf("El numero no existe en la lista.\n");
    }

}
/** CRITERIOS DE ORDENAMIENTO */
void ordenarDeMayorAMenor(int cadena[], int tam){
    int indicePrimercadena;
    int indiceSegundocadena;
    int aux;
    for(indicePrimercadena=0;indicePrimercadena<tam-1;indicePrimercadena++){
        for(indiceSegundocadena=indicePrimercadena+1;indiceSegundocadena<tam;indiceSegundocadena++){
            if(cadena[indicePrimercadena]<cadena[indiceSegundocadena]){
                /*C = A
                A = B criterio de ordenamiento
                B = C */
                aux = cadena[indicePrimercadena];
                cadena[indicePrimercadena] = cadena[indiceSegundocadena];
                cadena[indiceSegundocadena] = aux;
            }
        }
    }
    mostrarcadena(cadena, tam);
}
void ordenarDeMenorAMayor(int cadena[], int tam){
    int indicePrimercadena;
    int indiceSegundocadena;
    int aux;
    for(indicePrimercadena=0;indicePrimercadena<tam-1;indicePrimercadena++){
        for(indiceSegundocadena=indicePrimercadena+1;indiceSegundocadena<tam;indiceSegundocadena++){
            if(cadena[indicePrimercadena]>cadena[indiceSegundocadena]){
                /*C = A
                A = B criterio de ordenamiento
                B = C */
                aux = cadena[indicePrimercadena];
                cadena[indicePrimercadena] = cadena[indiceSegundocadena];
                cadena[indiceSegundocadena] = aux;
            }
        }
    }
    mostrarcadena(cadena, tam);
}
void menu_Ordenar_Vector(int cadena[], int tam){
    int option;
    char option_continue='s';
    do{
        printf("\nIngrese 1 para ordenar de menor a mayor o 2 para ordenar de mayor a menor:\nPresione 3 para volver al menu principal.\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("El vector ordenado de menor a mayor es: \n");
            ordenarDeMenorAMayor(cadena, tam);
            break;
        case 2:
            printf("El vector ordenado de mayor a menor es: \n");
            ordenarDeMayorAMenor(cadena, tam);
            break;
        default:
            option_continue='n';
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}
/** NUMEROS POSITIVOS Y NEGATIVOS */
void mostrarNumerosNegativos(int cadena[], int tam){
    printf("Estos son los numeros negativos:\n");
    int i;
    int flagNo_Negatives = 0;
    for(i=0; i<tam; i++){
        if(cadena[i]<0){
            printf("%d\n",cadena[i]);
            flagNo_Negatives = 1;
        }
    }
    if(flagNo_Negatives == 0){
        printf("No hay numeros negativos.\n");
    }
    printf("\n");
}
void mostrarNumerosPositivos(int cadena[], int tam){
    printf("Estos son los numeros positivos:\n");
    int i;
    int flagNo_Positivos = 0;
    for(i=0; i<tam; i++){
        if(cadena[i]>0){
            printf("%d\n",cadena[i]);
            flagNo_Positivos = 1;
        }
    }
    if(flagNo_Positivos == 0){
        printf("No hay numeros positivos.\n");
    }
    printf("\n");
}
void mostrarPromedioDeNegativos(int cadena[], int tam){
    int i;
    int acumuladorNegativos = 0;
    int contadorNegativos = 0;
    float promedioNegativos;
    for(i=0; i<tam; i++){
        if(cadena[i]>0){
            acumuladorNegativos = acumuladorNegativos + cadena[i];
            contadorNegativos++;
        }
    }
    promedioNegativos = (float) acumuladorNegativos / contadorNegativos;
    printf("Promedio de positivos: %.2f\n", promedioNegativos);
    printf("\n");
}
void mostrarPromedioDePositivos(int cadena[], int tam){
    int i;
    int acumuladorPositivos = 0;
    int contadorPositivos = 0;
    float promedioPositivos;
    for(i=0; i<tam; i++){
        if(cadena[i]>0){
            acumuladorPositivos = acumuladorPositivos + cadena[i];
            contadorPositivos++;
        }
    }
    promedioPositivos = (float) acumuladorPositivos / contadorPositivos;
    printf("Promedio de positivos: %.2f\n", promedioPositivos);
    printf("\n");
}
int mostrarCantidadPositivos(int cadena[], int tam){
    int contadorPositivos = 0;
    int i;
    for(i=0;i<tam;i++){
        if(cadena[i]>0){
            contadorPositivos++;
        }
    }
    return contadorPositivos;
}
int mostrarCantidadNegativos(int cadena[], int tam){
    int contadorNegativos = 0;
    int i;
    for(i=0;i<tam;i++){
        if(cadena[i]<0){
            contadorNegativos++;
        }
    }
    return contadorNegativos;
}
/** MINIMOS Y MAXIMOS */
int calcularMaximo (int cadena[], int tam){
    int i;
    int max;
    int flag;
    for(i=0; i<tam; i++){
        if(cadena[i]>max || flag == 0){
            max=cadena[i];
            flag = 1;
        }
    }
    return max;
}
void mostrarMaximo(int cadena[], int tam){
    int max = calcularMaximo(cadena, tam);
    printf("El max es: %d\n", max);
}
void mostrarPosicionMaximo (int cadena[], int tam){
    int i;
    int max = calcularMaximo(cadena, tam);
    printf("\nLa/s posicion/es del maximo es/son:");
    for(i=0; i<tam; i++){
        if(cadena[i]==max){
            printf("%d\n", i);
        }
    }
    printf("\n");
}
int calcularMinimo(int cadena[], int tam){
    int i;
    int min;
    int flag;
    for(i=0; i<tam; i++){
        if(cadena[i]<min || flag == 0){
            min=cadena[i];
            flag = 1;
        }
    }
 return min;
}
void mostrarMinimo(int cadena[], int tam){
    int min = calcularMinimo(cadena, tam);
    printf("El min es: %d\n", min);
}
void mostrarPosicionMinimo(int cadena[], int tam){
    int i;
    int min = calcularMinimo(cadena, tam);
    printf("\nLa/s posicion/es del minimo es/son:");
    for(i=0; i<tam; i++){
        if(cadena[i]==min){
            printf("%d\n", i);
        }
    }
}
void menu_Mostrar_Minimo_O_Maximo(int cadena[], int tam){
    int min = calcularMinimo(cadena, tam);
    int max = calcularMaximo(cadena, tam);
    int option;
    char option_continue='s';
    do{
        printf("\nIngrese 1 para mostrar minimo o 2 para mostrar maximo:\nPresione 3 para volver al menu principal.\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("El minimo es: %d.\n", min);
            mostrarPosicionMinimo(cadena, tam);
            break;
        case 2:
            printf("El maximo es: %d.\n", max);
            mostrarPosicionMaximo(cadena, tam);
            break;
        default:
            option_continue='n';
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}


