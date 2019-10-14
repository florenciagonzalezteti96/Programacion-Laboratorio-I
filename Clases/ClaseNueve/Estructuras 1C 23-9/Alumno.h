#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idLocalidad;
    char localidad[30];
    int codigoPostal;
} eLocalidad;
typedef struct
{
    int legajo;
    char nombre[29];
    float promedio;
    int idLocalidad;
    int estado;
} eAlumno;
typedef struct
{
    int idLocalidad;
    int cantidadAlumnos;

}eAux;

eAlumno cargarAlumno(void);
void mostrarUnAlumno(eAlumno miAlumno, eLocalidad unaLocalidad);
int buscarLibre(eAlumno*, int);
void cargarListadoAlumnos(eAlumno[], int);
void mostrarListadoAlumnos(eAlumno[], int, eLocalidad[], int);
void hardCodearAlumnos(eAlumno[], int);
void sortStudentsByNameAndAverage(eAlumno[], int);
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tam, eLocalidad listaLocalidades[], int tl);
int modificarAlumno(eAlumno[], int, int, eLocalidad[], int);
int buscarAlumnoPorLegajo(eAlumno[], int, int);
int calcularCantidadAlumnos (eAlumno listaAlumno[], eLocalidad lista[], int tL, int tA);
int buscarLocalidadPorId(eLocalidad[], int, int);
int buscarLocalidadConMenosAlumnos(eLocalidad lista[], int tLocalidad, eAlumno listaAlumno[], int tAlumnos);

