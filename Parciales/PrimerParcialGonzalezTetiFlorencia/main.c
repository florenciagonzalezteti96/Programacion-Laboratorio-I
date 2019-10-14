#include <stdio.h>
#include <stdlib.h>
#include "Elenco.h"

#define TA 50
#define TP 20
#define TG 4
#define TE 1000

int main()
{
    eActor listaDeActores[TA];
    ePelicula listadoDePeliculas[TP];
    eGenero listadoDeGeneros[TG];
    //eElenco listadoDeElenco[TE];
    //initElencos(listadoDeElenco,TE);
    //initCodigoReparto(listadoDeElenco, TE);
    initPeliculas(listadoDePeliculas, TP);
    initActor(listaDeActores, TA);

    hardcodearPeliculas(listadoDePeliculas, 30);
    hardcodearGeneros(listadoDeGeneros, TG);
    hardCodearActores(listaDeActores, 30);

    mostrarListaPeliculas(listadoDePeliculas, TP, listadoDeGeneros, TG);

    return 0;
}
