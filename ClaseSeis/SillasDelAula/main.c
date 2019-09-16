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
#include "funciones.h"
#include "string.h"
#include "ctype.h"

int main()
{
    int legajos[5];
    int edades[5];
    char nombres[5][30];
    int i;

    inicializarVector(legajos,5,0);
    inicializarVector(edades,5,0);
    cargarVectorInicializado(legajos, 5, "Ingrese legajos: \n",0);
    cargarVectorInicializado(edades,5,"Ingrese edades: \n",0);
    for(i=0;i<5;i++){
        cargarVectorNombresYApellidos(nombres[i], "Ingrese un nombre: ", "Ingrese un apellido: ");
    }

    for(i=0;i<5;i++){
        mostrarVector(legajos,5);
        mostrarVector(edades,5);
        mostrarVector(nombres,5);
    }


    return 0;
}
