#include "Inputs.h"
#include "Pelicula.h"
#define TRUE 0
#define FALSE 1
typedef struct{
    int codigo;
    char nombre[52];
    char apellido[52];
    char sexo;
    int isEmpty;
}eActor;

void mostrarMenuActores(eActor listaDeActores[], int tamActores, ePelicula listaDePeliculas[], int tamPeliculas);
void hardcodearActores(eActor listadoDeActores[], int tamActores);
int initActor(eActor listaDeActores[], int tamActor);
int initCodigoActor(eActor listaDeActores[], int tamActor);

void mostrarUnActor(eActor unActor);
void mostrarListaDeActores(eActor listaDeActores[], int tamActores);

int cargarUnActor(eActor listaDeActores[], int tamActores);

void getDataActor(char name[],char lastName[], char* sexo);
void showDataActor(char name[],char lastName[], char sexo);

int agregarActor(eActor listaDeActores[], int tamActores, int codigo, char name[],char lastName[], char sexo);
int getNewCodigo(eActor listaDeActores[], int tamActores);
int getIsEmptyActores(eActor listaDeActores[], int tamActores);
int modificarUnActor(eActor listadoDeActores[], int tamActores, ePelicula listadoDePeliculas[], int tamPeliculas);
int encontrarActorPorCodigo(eActor listadoDeActores[], int tamActores,int codigo);
int removeActor(eActor listadoDeActores[], int tamActores, int id);
int eliminarActor(eActor listaDeActores[], int tamActores, ePelicula listaDePeliculas[], int tamPeliculas);
void sortActores(eActor listadoDeActores[], int tamActores);
void hardCodearActores(eActor listadoDeActores[], int tamActores);
int obtenerUnActor(eActor listadoDeActores[], int tamActores);
int validarIdActor(eActor listadoDeActores[], int tamActores, int idActor);
void mostrarActorPorId(eActor listadoDeActores[], int tamActores, int idActor);
