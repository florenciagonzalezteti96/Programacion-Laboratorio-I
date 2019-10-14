#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"

typedef struct{
    int id;
    char descripcion[52];
}eGenero;

/** \brief Esta funcion hardcodea un listado de generos con un id y una descripcion.
 *
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return int Devuelve -1 si tamGeneros es menor a 0, devuelve 0 si pudo realizar el hardcodeo.
 *
 */
int hardcodearGeneros(eGenero listadoDeGeneros[], int tamGeneros);
/** \brief Esta funcion recibe un codigo de genero y lo usa para verificar que ese genero exista en la lista.
 *
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \param idGenero int El codigo de genero ingresado
 * \return int Devuelve -1 si el codigo ingresado no corresponde a ningun genero de la lista, devuelve 0 si el codigo existe en la lista.
 *
 */
int validarIdGenero(eGenero listadoDeGeneros[], int tamGeneros, int idGenero);
/** \brief Esta funcion recibe un codigo de genero y lo usa para buscar el indice del genero en la lista.
 *
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \param idGenero int El codigo de genero ingresado
 * \return int Devuelve -1 si el codigo ingresado no encontro el genero, si lo encontro devuelve su indice.

 *
 */
int buscarIndiceGenero(eGenero listadoDeGeneros[], int tamGeneros, int idGenero);
/** \brief Esta funcion pide un codigo de genero.
 *
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return int Devuelve el codigo ingresado
 *
 */
int obtenerUnGenero(eGenero listadoDeGeneros[], int tamGeneros);
/** \brief Esta funcion recibe un codigo de genero y muestra el genero al que corresponde dicho codigo
 *
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \param idGenero int El codigo de genero ingresado
 * \return int Devuelve 0 si pudo encontrar y mostrar el genero, si no devuelve -1
 *
 */
int mostrarGeneroPorId(eGenero listadoDeGeneros[], int tamGeneros, int idGenero);
/** \brief Esta funcion muestra un array de estructura eGenero
 *
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return void
 *
 */
void mostrarListaGeneros(eGenero listadoDeGeneros[], int tamGeneros);
