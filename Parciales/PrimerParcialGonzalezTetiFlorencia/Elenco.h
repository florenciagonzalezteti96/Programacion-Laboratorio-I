#include "Inputs.h"
#include "Actor.h"
#define TRUE 0
#define FALSE 1

typedef struct
{
    int codigoPelicula;
    int codigoActor;
    float valorContrato;
    int isEmpty;
} eElenco;

/** \brief Esta funcion despliega un menu de gestion de una lista de elencos
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \param listadoDePeliculas[] ePelicula La lista de estructuras ePelicula
 * \param tamPeliculas int El tamaño de la lista de estructuras ePelicula
 * \param listadoDeGeneros[] eGenero La lista de estructuras eGenero
 * \param tamGeneros int El tamaño de la lista de estructuras eGenero
 * \param listadoDeActores[] eActor La lista de estructuras eActor
 * \param tamActores int El tamaño de la lista de estructuras eActor
 * \return void
 *
 */
void mostrarMenuElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion despliega un menu de gestion de una lista de elencos y una lista de actores
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \param listadoDePeliculas[] ePelicula La lista de estructuras ePelicula
 * \param tamPeliculas int El tamaño de la lista de estructuras ePelicula
 * \param listadoDeGeneros[] eGenero La lista de estructuras eGenero
 * \param tamGeneros int El tamaño de la lista de estructuras eGenero
 * \param listadoDeActores[] eActor La lista de estructuras eActor
 * \param tamActores int El tamaño de la lista de estructuras eActor
 * \return void
 *
 */
void mostrarMenus(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion inicializa todos los campos isEmpty de la lista de elencos en VACIO ( 0 )
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \return int Devuelve 0 si logro inicializar todos los espacios, caso contrario devuelve -1
 *
 */
int inicializarElencos(eElenco listaDeElencos[], int tamElencos);
/** \brief Esta funcion hardcodea datos en una lista de elencos
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \return void
 *
 */
void hardcodearElencos(eElenco listadoDeElencos[], int tamElencos);
/** \brief Esta funcion obtiene el primer lugar vacante dentro de una lista de elencos
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \return int Devuelve -1 si no encontro un lugar vacante, caso contrario devuelve el indice del lugar encontrado
 *
 */
int obtenerLugarDisponibleElenco(eElenco listadoDeElencos[], int tamElencos);
/** \brief Esta funcion permite al usuario ingresar varios actores por pelicula
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \param listadoDePeliculas[] ePelicula La lista de estructuras ePelicula
 * \param tamPeliculas int El tamaño de la lista de estructuras ePelicula
 * \param listadoDeGeneros[] eGenero La lista de estructuras eGenero
 * \param tamGeneros int El tamaño de la lista de estructuras eGenero
 * \param listadoDeActores[] eActor La lista de estructuras eActor
 * \param tamActores int El tamaño de la lista de estructuras eActor
 * \return int Devuelve -1 si no pudo acceder a la carga, 0 si pudo cargar, 1 si el elenco ingresado ya existe o 2 si el usuario cancelo la carga
 *
 */
int agregarUnElenco(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion crea una entidad eElenco para agregar un elenco a una lista de elencos
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \param listadoDeActores[] eActor La lista de estructuras eActor
 * \param tamActores int El tamaño de la lista de estructuras eActor
 * \param idPelicula int El id de la pelicula a la cual se quiere agregar el actor
 * \param valorContrato int El valor del contrato del actor por la pelicula
 * \return eElenco Devuelve la entidad eElenco creada
 *
 */
eElenco agregarUnActorAElenco(eElenco listadoDeElencos[], int tamElencos, eActor listadoDeActores[], int tamActores, int idPelicula, int valorContrato);
void mostrarUnElenco(eElenco unElenco, ePelicula listadoDePeliculas[], int tamPelicula, eActor listadoDeActores[], int tamActores);

void mostrarListaElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores);
int validarSiExiste(eElenco listadoDeElencos[], int tamElencos, eElenco unElenco);
int ordenarElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eActor listadoDeActores[], int tamActores);
