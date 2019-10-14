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
    int isEmpty;
}ePelicula;

/** \brief Esta funcion inicializa todas los campos isEmpty en 0
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \return int Devuelve 0 si pudo inicializar, caso contrario devuelve -1.
 *
 */
int initPeliculas(ePelicula listadoDePeliculas[], int tamPeliculas);
/** \brief Esta funcion inicializa todas los campos codigo en 0
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \return int Devuelve 0 si pudo inicializar, caso contrario devuelve -1.
 *
 */
int initCodigoPelicula(ePelicula listadoDePeliculas[], int tamPeliculas);
/** \brief Esta funcion hardcodea un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \return void
 *
 */
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
int obtenerUnaPelicula(ePelicula listadoDePeliculas[],int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros);
/** \brief Esta funcion busca el una pelicula dentro de un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param idPelicula int El codigo de pelicula ingresado
 * \return int Devuelve el indice de la pelicula si la encontro, caso contrario devuelve -1
 *
 */
int buscarIndicePelicula(ePelicula listadoDePeliculas[],int tamPeliculas,int idPelicula);

/** \brief Esta funcion permite al usuario agregar una pelicula a un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return int Devuelve 1 si no pudo acceder al ingreso de datos, 0 si pudo cargar la nueva pelicula, -1 si no la cargo y 2 si el usuario decidio cancelar la carga
 *
 */
int agregarUnaPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros);
/** \brief Esta funcion permite ingresar los datos para crear una nueva pelicula dentro de una array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return ePelicula Devuelve la pelicula cargada
 *
 */
ePelicula getDataPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros);
/** \brief Esta funcion calcula un codigo para una pelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \return int Devuelve -1 si el tamaño del array es invalido o si no hay peliculas cargadas, caso contrario devuelve el codigo creado
 *
 */
int obtenerNuevoCodigoPelicula(ePelicula listadoDePeliculas[], int tamPeliculas);
/** \brief Esta funcion carga una nueva pelicula ingresada en un espacio libre de un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param nuevaPelicula ePelicula La pelicula a cargar en el array de estructura ePelicula
 * \return int Devuelve -1 si no hay lugar disponible en el array o 0 si pudo cargar la pelicula
 *
 */
int cargarUnaPelicula(ePelicula listadoDePeliculas[],int tamPeliculas, ePelicula nuevaPelicula);
/** \brief Esta funcion devuelve el primer lugar libre dentro de un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \return int Devuelve -1 si no pudo encontrar un lugar libre o si el tamaño del array es invalido, caso contrario devuelve el indice del primer lugar libre encontrado
 *
 */
int getIsEmptyPeliculas(ePelicula listadoDePeliculas[], int tamPeliculas);

/** \brief Esta funcion despliega un menu de modificaciones a elementos de un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return int Devuelve -1 si no encontro la pelicula a modificar, 1 si cargo las modificaciones o 0 si el usuario decidio cancelar la accion
 *
 */
int modificarUnaPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros);
/** \brief Esta funcion pide un codigo y permite realizar una baja logica de un elemento de un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param listadoDeGeneros[] eGenero El array de estructura eGenero
 * \param tamGeneros int El tamaño del array de estructura eGenero
 * \return int Devuelve 1 si no encontro la pelicula, -1 si el tamaño del array es invalido, 0 si pudo dar de baja o 2 si el usuario cancelo la accion
 *
 */
int eliminarPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros);
/** \brief Esta funcion realiza una baja logica de un elemento de un array de estructura ePelicula
 *
 * \param listadoDePeliculas[] ePelicula El array de estructura ePelicula
 * \param tamPeliculas int El tamaño del array de estructura ePelicula
 * \param codigoPelicula int El codigo de la pelicula a dar de baja
 * \return int Devuelve -1 si el tamaño del array es invalido o 0 si pudo realizar la baja
 *
 */
int removePelicula(ePelicula listadoDePeliculas[], int tamPeliculas, int codigoPelicula);
