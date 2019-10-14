#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcionesEstructuras.h"

int main()
{
    eAlumno listadoDeAlumnos[10];
    eLocalidad listadoDeLocalidades[3];

    hardcodearLocalidades(listadoDeLocalidades, 3);


    mostrar_menu(listadoDeAlumnos, 10, listadoDeLocalidades, 3);

    return 0;
}
