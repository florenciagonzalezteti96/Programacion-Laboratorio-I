#include <stdio.h>
#include <stdlib.h>
#include "Elenco.h"

#define TA 30
#define TP 20
#define TG 4
#define TE 1000

int main()
{
    eActor listaDeActores[TA];
    ePelicula listadoDePeliculas[TP];
    eGenero listadoDeGeneros[TG];
    eElenco listadoDeElenco[TE];
    initElencos(listadoDeElenco,TE);
    initCodigoReparto(listadoDeElenco, TE);
    initPeliculas(listadoDePeliculas, TP);
    initActor(listaDeActores, TA);

    hardcodearPeliculas(listadoDePeliculas, 4);
    hardcodearGeneros(listadoDeGeneros, TG);
    hardCodearActores(listaDeActores, 4);

    return 0;
}
