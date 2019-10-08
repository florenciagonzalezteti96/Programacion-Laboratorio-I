#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
int main()
{
    eAlumno listadoDeAlumnos[100];
    eLocalidad listadoDeLocalidades[5];
    hardcodearLocalidades(listadoDeLocalidades, 5);
    initAlumnos(listadoDeAlumnos, 100);
    initLegajosAlumnos(listadoDeAlumnos,100);
    hardCodearAlumnos(listadoDeAlumnos, 10);
    mostrarAlumnosPorLocalidad(listadoDeAlumnos,100,listadoDeLocalidades,5);
    mostrarAlumnosDeAvellaneda(listadoDeAlumnos,100,listadoDeLocalidades,5);

    return 0;
}
