#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{

    int id;
    char descripcion[32];
    int codPostal;

} eLocalidad;

typedef struct
{

    int idLocalidad;
    int contadorAlumnos;

} eContador;


eLocalidad una_localidad(eLocalidad arrayLocalidad[], int lenLocalidad);
void mostrar_unaLocalidad(eLocalidad unaLocalidad);
void mostrar_Localidades(eLocalidad arrayLocalidad[],int lenLocalidad);
void hardcode_Localidad(eLocalidad arrayLocalidad[],int lenLocalidad);
int buscarLocalidadId(eLocalidad listaLocalidad[], int lenLocal, int idLocal);


void hardcode_Contador(eContador arrayContador[],int lenContador,eLocalidad arrayLocalidad[] );
int contarMinimo(eContador arrayContador[],int lenContador);
int contarMaximo(eContador arrayContador[],int lenContador);
void mostrar_Contador(eContador arrayContador[],int lenContador,eLocalidad arrayLocalidad[],int lenLocalidad,int resultado);














