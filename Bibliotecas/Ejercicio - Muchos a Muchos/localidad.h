#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"

typedef struct{
    int id;
    char nombreLocalidad[32];
    int codigoPostal;
} eLocalidad;

typedef struct{
    int idLocalidad;
    int contadorAlumnos;
} eContador;

int getLocalidad(eLocalidad listadoDeLocalidades[], int tamLocalidad);
int existeLocalidad(eLocalidad listadoDeLocalidades[], int tamLocalidad, int idLocalidad);
void mostrarLocalidades(eLocalidad listadoDeLocalidades[], int tamLocalidad);
void mostrarLocalidadPorId(eLocalidad listadoDeLocalidades[], int tamLocalidad, int idLocalidad);
int buscarLocalidadPorId(eLocalidad listadoDeLocalidades[], int tamLocalidad, int idLocalidad);
void hardcodearContador(eContador listaDeContadores[],int tamContador, eLocalidad listaDeLocalidades[]);
