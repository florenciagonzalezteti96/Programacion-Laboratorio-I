#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Inputs.h"


typedef struct
{
    char calle[21];
    int altura;
    char localidad[30];

}eDireccion;

eDireccion pedirDireccion();
void mostrarDireccion (eDireccion unaDireccion);
