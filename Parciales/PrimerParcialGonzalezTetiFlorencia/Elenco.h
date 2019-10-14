#include "Inputs.h"
//#include "Pelicula.h"
#include "Actor.h"
#define TRUE 0
#define FALSE 1

typedef struct{
    int codigoPelicula;
    int codigoActor;
    float valorContrato;
    int isEmpty;
}eElenco;

void showMenuElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores);
int initElencos(eElenco listaDeElencos[], int tamElencos);
int getIsEmptyElenco(eElenco listadoDeElencos[], int tamElencos);
int agregarUnElenco(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores);
eElenco agregarActoresAElenco(eElenco listadoDeElencos[], int tamElencos, eActor listadoDeActores[], int tamActores, int idPelicula, int valorContrato);
void mostrarUnElenco(eElenco unElenco, ePelicula listadoDePeliculas[], int tamPelicula, eActor listadoDeActores[], int tamActores);
