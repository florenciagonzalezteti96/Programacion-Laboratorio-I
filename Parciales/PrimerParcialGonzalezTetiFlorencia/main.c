#include <stdio.h>
#include <stdlib.h>
#include "Elenco.h"

#define TA 50
#define TP 20
#define TG 4
#define TE 1000

int main()
{
    eActor listadoDeActores[TA];
    ePelicula listadoDePeliculas[TP];
    eGenero listadoDeGeneros[TG];
    eElenco listadoDeElenco[TE];



    ordenarElencos(listadoDeElenco, TE, listadoDePeliculas, TP, listadoDeActores, TA);


    //mostrarListaDeActores(listadoDeActores, TA);
    //mostrarListaPeliculas(listadoDePeliculas, TP, listadoDeGeneros, TG);
    mostrarListaElencos(listadoDeElenco, TE, listadoDePeliculas, TP, listadoDeGeneros, TG, listadoDeActores, TA);
    //showMenuElencos(listadoDeElenco, TE, listadoDePeliculas, TP, listadoDeGeneros, TG, listadoDeActores, TA);

    return 0;
}
