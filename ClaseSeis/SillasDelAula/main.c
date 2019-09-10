#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**asignarle a cada silla del aula el legajo del alumno que esta sentado:
5 sillas
mostrar datos: que muestre el legajo y la edad.
*/


int main()
{
    int legajos[5];
    int edades[5];

    inicializarVector(legajos, 5, -1);
    //harcodeo sillas
    hardcodearVector(legajos, 5);
    hardcodearVectorEdades(edades, 5);

    mostrarDatos(legajos, 5, edades);
    mostrarMaximaEdadYLegajo(edades, legajos, 5);





    return 0;
}
