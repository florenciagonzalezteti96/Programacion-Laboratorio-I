#define LIBRE 0
#define OCUPADO 1
#include "localidad.h"
typedef struct{
    char nombre[50];
    int nota;
    int legajo;
    int idLocalidad;
    int isEmpty;//0 para ocupado, 1 para libre -> bandera
}eAlumno;

void mostrar_menu(eAlumno listadoDeAlumnos[], int tam, eLocalidad listaDeLocalidades[], int tl);
void hardcodearEstructura(eAlumno listaDeAlumnos[], int cantidadDeAlumnos);
void listarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, eLocalidad listaDeLocalidades[], int tl);
void mostrarListadoAlumnos(eAlumno[], int, eLocalidad[], int);
void mostrarUnAlumno(eAlumno miAlumno, eLocalidad unaLocalidad);
void inicializarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos);
int dameElPrimerLugarLibre(eAlumno listaDeAlumnos[], int cantidadDeAlumnos);
void borrarLegajo(eAlumno listaDeAlumnos[], int cantidadDeAlumnos);
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tam, eLocalidad listaLocalidades[], int tl);
eAlumno crearUnAlumno (eLocalidad listadoDeLocalidades[], int tl);
int cargarUnAlumno(eAlumno listadoDeAlumnos[], int tam, eLocalidad listaDeLocalidades, int tl);
void ordenarPorNombreDescente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreAscendente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreLegajoDescendente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreLegajoAscendente(eAlumno listadoDeAlumnos[], int tam);
void firstToUpper(char cadena[]);
void pedirCadena (char mensaje[], char cadena[]);
int getInt(char mensaje[]);
int buscarPorLegajo(eAlumno listadoDeAlumno[], int tam);
void borrarPorNombre(eAlumno listadoDeAlumno[], int tam);
int modificarAlumno2(eAlumno listadoDeAlumno[], int tam, eLocalidad listaDeLocalidades[], int tl);
