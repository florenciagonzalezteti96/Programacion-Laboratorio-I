#include "Direccion.h"

eDireccion pedirDireccion()
{
    eDireccion unaDireccion;

    unaDireccion.altura = getInt("Ingrese la altura de la direccion: ");
    pedirCadena("Ingrese la calle de la direccion: ",unaDireccion.calle);
    pedirCadena("Ingrese la localidad de la direccion: ",unaDireccion.localidad);

    return unaDireccion;
}

void mostrarDireccion (eDireccion unaDireccion)
{
    printf("%s", unaDireccion.localidad);
}
