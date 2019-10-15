#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#define A 5

int main()
{
    eAlumno listaDeAlumnos[A];
    eLocalidad listaLocalidades[3]={{1,"Avellaneda",1870},{2,"Wilde",1872},{3,"Lomas de Zamora",1700}};
    buscarLocalidadConMenosAlumnos(listaLocalidades, 3, listaDeAlumnos, A);
    int i;
    /*for(i=0;i<3;i++)
    {
        printf("%d - %s - %d\n", listaLocalidades[i].idLocalidad,listaLocalidades[i].localidad,listaLocalidades[i].codigoPostal);
    }*/

    /**
    menos alumnos por localidad

inicialiozo el auxiliar, --
carggo los id --
dentro de cada id, busco la cantidad de alumnos y la cargo en cantidad de alumnos
busco el minimo en ese vector
uso ese minimo para buscar el id del minimo
comparo con el id de localidad
muestro esa localidad

    AGREGAR ESTRUCTURA MATERIA
    INT CODIGO
    CHAR NOMBRE
    INT CARGA HORARIA



    */


    int respuesta;
    int opcion;
    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=LIBRE;
    }

    hardCodearAlumnos(listaDeAlumnos,A);


    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Eliminar\n5.Modificar\n7.Salir");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarListadoAlumnos(listaDeAlumnos,A);
            break;
        case 2:
            mostrarListadoAlumnos(listaDeAlumnos, A, listaLocalidades, 3);
            break;
        case 3:
            sortStudentsByNameAndAverage(listaDeAlumnos,A);
            break;
        case 4:
            respuesta = eliminarAlumno(listaDeAlumnos,A, listaLocalidades, 3);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno eliminado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }

            break;
        case 5:

            respuesta = modificarAlumno(listaDeAlumnos,A,101, listaLocalidades, 3);
            switch(respuesta)
            {
                case 0:
                    printf("Accion cancelada por el usuario\n");
                    break;
                case 1:
                    printf("Alumno modificado\n");
                    break;
                case -1:
                    printf("Dato no encontrado\n");
                    break;
            }
            break;
        }
    }
    while(opcion!=7);
    return 0;
}

