#include <stdio.h>
#include <stdlib.h>
#include "Elenco.h"

#define TA 50//tamaño de la lista de actores
#define TP 20//tamaño de la lista de peliculas
#define TG 4//tamaño de la lista de generos
#define TE 1000//tamaño de la lista de elencos
#define TF 20//tamaño de la lista de fechas
#define TPais 5//tamaño de la lista de paises

int main()
{
    eActor listadoDeActores[TA];
    ePelicula listadoDePeliculas[TP];
    eGenero listadoDeGeneros[TG];
    eElenco listadoDeElencos[TE];
    eFecha listadoDeFechas[TF];
    ePais listadoDePaises[TPais];

    mostrarMenus(listadoDeElencos, TE, listadoDePeliculas, TP, listadoDeGeneros, TG, listadoDeActores, TA, listadoDeFechas, TF, listadoDePaises, TPais);


    return 0;
}
