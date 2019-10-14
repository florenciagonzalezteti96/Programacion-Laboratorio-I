#include "fechas.h"
typedef struct{
    int idInscripcion;
    int legajo;
    int idMateria;
    eFecha fechaDeInscripcion;
    int isEmpty;
}eInscripciones;
void inicializar_Inscripcion(eInscripciones listadoDeInscripciones[],int tamInscripciones);
int buscarLugarInscripcion(eInscripciones listadoDeInscripciones[],int tamInscripciones);
