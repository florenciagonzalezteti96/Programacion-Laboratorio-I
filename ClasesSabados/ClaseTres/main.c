#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 3

/**
no funcionan->
    //mostrarUnArray(miArray[CANTIDAD]);
    //mostrarUnArray(miArray[]);


*/

void mostrarUnArray(int parametroArray[], int tam);
void inicializarUnArray(int parametroArray[], int tam);

int main()
{
    int miArray[CANTIDAD];

    inicializarUnArray(miArray, CANTIDAD);
    mostrarUnArray(miArray, CANTIDAD);

    return 0;
}

void inicializarUnArray(int parametroArray[], int tam){
    int i;
    for(i=0;i<tam;i++){
        parametroArray[i]=0;
    }
}

void mostrarUnArray(int parametroArray[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n",parametroArray[i]);
    }
    printf("\n\n");
}
