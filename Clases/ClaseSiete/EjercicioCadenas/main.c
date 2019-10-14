#include <stdio.h>
#include <stdlib.h>
#define T 3

int main()
{
    int legajo[T];
    char nombre[T][20];//filas y columnas. para representar muchos nombres necesito una matriz.
    int i;
    int j;
    int auxInt;
    char auxString[20];

    for(i=0;i<T;i++){
        printf("Ingrese legajo: ");
        fflush(stdin);
        scanf("%d", &legajo[i]);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre[i]);
    }

    for(i=0;i<T;i++){
        printf("Legajo: %d\tNombre: %s", legajo[i], nombre[i]);
    }

    for(i=0;i=T-1;i++){
        for(j=i+1;j<T;j++){
            if(legajo[i]>legajo[j]){
                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                strcpy(auxString, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxString);

            }

        }

    }
    return 0;
}

//agregar el nombre de cada alumno y buscar y mostrar el nombre del maximo alumno
//funcion que ordene todos los alumnos que estan sentados por nombre y mostrar.
