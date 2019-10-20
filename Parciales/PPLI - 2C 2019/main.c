#include <stdio.h>
#include <stdlib.h>
#include "Elenco.h"

#define TA 50//tamaño de la lista de actores
#define TP 20//tamaño de la lista de peliculas
#define TG 4//tamaño de la lista de generos
#define TE 1000//tamaño de la lista de elencos

int main()
{
    eActor listadoDeActores[TA];
    ePelicula listadoDePeliculas[TP];
    eGenero listadoDeGeneros[TG];
    eElenco listadoDeElenco[TE];

    mostrarMenus(listadoDeElenco, TE, listadoDePeliculas, TP, listadoDeGeneros, TG, listadoDeActores, TA);

    return 0;
}
