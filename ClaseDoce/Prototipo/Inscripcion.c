#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "Local.h"
#include "alumno.h"
#include "Inscripcion.h"


int cargarInscripcion(eInscripcion listaDeInscripciones[], int tamInscripcion, eMateria listaDeMaterias[], int tamMaterias, eAlumno listaDeAlumnos[], int tamAlumnos){
    //int i;
    int retorno = -1;
    int indice;

    indice = buscar_Libre_Inscripcion(listaDeInscripciones, tamInscripcion);

    if(indice != -1){
        printf("Estos son los alumnos. Elija un legajo:\n");
        mostrarListadoSoloAlumnos(listaDeAlumnos, tamAlumnos);

    }

    return retorno;
}
int buscar_Libre_Inscripcion(eInscripcion listaDeInscripciones[],int tamInscripcion)
{
    int indice = -1;
    int i;

    for(i=0; i<tamInscripcion; i++)
    {
        if(listaDeInscripciones[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;//retorno -1 sino encontro un lugar libre
}
void initInscripcion(eInscripcion listaDeInscripciones[],int tamInscripciones)
{
    int i;
    for(i=0; i<tamInscripciones; i++){
        listaDeInscripciones[i].estado = LIBRE;
    }
}
