#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "localidad.h"

#define OCUPADO 1
#define LIBRE 0

typedef struct{
    int legajo;
    char name[32];
    char lastName[32];
    int promedio;
    int idLocalidad;
    int isEmpty;
} eAlumno;

void initAlumnos(eAlumno listadoDeAlumnos[], int tamAlumnos);
void initLegajosAlumnos(eAlumno listadoDeAlumnos[], int tamAlumnos);
void mostrarUnAlumno(eAlumno unAlumno, eLocalidad unaLocalidad);
void mostrarDatosIngresadosAlumno(eLocalidad listadoDeLocalidades[], int tamLocalidad, char name[], char lastName[], float promedio, int idLocalidad);
int mostrarAlumnos(eAlumno listadoDeAlumnos[], int tamAlumnos, eLocalidad listadoDeLocalidades[], int tamLocalidad);

int addAlumno(eAlumno listadoDeAlumnos[], int tamAlumnos, eLocalidad listadoDeLocalidades[], int tamLocalidad, int legajo, char name[],char lastName[], float promedio, int idLocalidad);
void getDataAlumno(eLocalidad listadoDeLocalidades[], int tamLocalidad, char name[],char lastName[],float* promedio, int* idLocalidad);
int getIsEmpty(eAlumno listadoDeAlumnos[], int tamAlumnos);
int getNuevoLegajo(eAlumno listadoDeAlumnos[], int tamAlumnos);

int cargarUnAlumno(eAlumno listadoDeAlumnos[], int tamAlumnos, eLocalidad listadoDeLocalidades[], int tamLocalidad);
void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam);
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tamAlumnos, eLocalidad listadoDeLocalidades[], int indiceLocalidad);

