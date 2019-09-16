#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcionesEstructuras.h"

int main()
{
    eAlumno listadoDeAlumnos[5]; //no significa que hay 5 alumnos, sino que hay cinco lugares.

    inicializarAlumnos(listadoDeAlumnos,5,1);
    hardcodearEstructura(listadoDeAlumnos, 5);
    borrarLegajo(listadoDeAlumnos, 5, 9, 1);
    listarAlumnos(listadoDeAlumnos, 5, 1);

    return 0;
}







