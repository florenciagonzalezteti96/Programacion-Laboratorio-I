#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    /**
    EJERCICIO 2:
    char cadenaNombre[50];
    char mayorVocal;
    printf("Ingrese su nombre: ");
    gets(cadenaNombre);
    mayorVocal = verificarVocales(cadenaNombre);
    printf("\nLa vocal con mayor incidencia es: %c", mayorVocal);*/
    eNotebook list[3];
    init_eNotebook(list, 3);
    ordenarListaNotebooks(list, 3);
    int i;
    for(i=0;i<3;i++){
        printf("ID: %d\t\t", list[i].id);
        printf("MARCA: %s\t\t", list[i].marca);
        printf("PROCESADORES: %s\t\t", list[i].procesador);
        printf("PRECIO: %.2f\t\t\n", list[i].precio);
    }
    return 0;
}
