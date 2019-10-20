#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Genero.h"

#define TRUE 0
#define FALSE 1

typedef struct{
    int codigo;
    char descripcion[52];
    int duracion;
    int idGenero;
}ePelicula;

void hardcodearPeliculas(ePelicula listadoDePeliculas[], int tamPeliculas);

/** \brief Esta funcion muestra una pelicula con el genero al cual pertenece
 *
 * \param unaPelicula ePelicula Un elemento de tipo ePelicula
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return void
 *
 */
int mostrarPeliculaPorId(ePelicula listadoDePeliculas[], int tamPeliculas, int codigoPelicula);
/** \brief Esta funcion muestra una pelicula sola
 *
 * \param unaPelicula ePelicula La pelicula a mostrar
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return void
 *
 */
void mostrarPelicula(ePelicula unaPelicula, eGenero listadoDeGeneros[],int tamGeneros);
/** \brief Esta funcion muestra las peliculas en un array de estructura ePelicula con los generos a los cuales pertenecen
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return void
 *
 */
void mostrarListaPeliculas(ePelicula listadoDePeliculas[],int tamPeliculas,eGenero listadoDeGeneros[],int tamGeneros);
/** \brief Esta funcion valida que el codigo de pelicula ingresado exista dentro de un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param idPelicula int El codigo de pelicula ingresado
 * \return int Devuelve 0 si encontro el codigo, caso contrario devuelve -1
 *
 */
int validarIdPelicula(ePelicula listadoDePeliculas[],int tamPeliculas,int idPelicula);
/** \brief Esta funcion pide el codigo de una pelicula y lo devuelve
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return int El codigo ingresado
 *
 */
int obtenerIdPelicula(ePelicula listadoDePeliculas[],int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros);
/** \brief Esta funcion busca el una pelicula dentro de un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param idPelicula int El codigo de pelicula ingresado
 * \return int Devuelve el indice de la pelicula si la encontro, caso contrario devuelve -1
 *
 */
int buscarIndicePelicula(ePelicula listadoDePeliculas[],int tamPeliculas,int idPelicula);
/** \brief Esta funcion  muestra la pelicula que corresponde con el codigo ingresado.
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param idPelicula int El codigo de pelicula ingresado
 * \return int Devuelve 0 si la pudo mostrar o -1 si no la encontro.
 *
 */
int mostrarPeliculaPorId(ePelicula listadoDePeliculas[], int tamPeliculas, int idPelicula);
/** \brief Esta funcion retorna la pelicula que corresponde con el codigo ingresado
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param idPelicula int El codigo de pelicula ingresado
 * \return ePelicula El elemento de tipo pelicula que se pidio
 *
 */
ePelicula obtenerPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, int codigo);

