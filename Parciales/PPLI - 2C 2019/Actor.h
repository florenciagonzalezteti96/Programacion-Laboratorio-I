#include "Inputs.h"
#include "Pelicula.h"
#include "Pais.h"
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int codigo;
    char nombre[52];
    char apellido[52];
    int idNacionalidad;
    char sexo;
    int isEmpty;
} eActor;

/** \brief Esta funcion despliega un menu para gestionar una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param listaDePeliculas[] ePelicula La lista de peliculas
 * \param tamPeliculas int El tamaño de la lista de peliculas
 * \return void
 *
 */
void mostrarMenuActores(eActor listadoDeActores[], int tamActores, ePelicula listaDePeliculas[], int tamPeliculas, ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion inicializa todos los campos isEmpty de la lista de actores en VACIO ( 0 )
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return int Devuelve 0 si pudo inicializar todos los lugares, caso contrario devuelve -1
 *
 */
int inicializarActores(eActor listadoDeActores[], int tamActor);
/** \brief Esta funcion inicializa todos los campos codigo de la lista de actores en VACIO ( 0 )
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return int Devuelve 0 si pudo inicializar todos los lugares, caso contrario devuelve -1
 *
 */
int inicializarCodigosActores(eActor listadoDeActores[], int tamActor);
/** \brief Esta funcion hardcodea datos en una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return void
 *
 */
void hardcodearActores(eActor listadoDeActores[], int tamActores);

/** \brief Esta funcion muestra un elemento de tipo eActor
 *
 * \param unActor eActor El elemento a mostrar
 * \return void
 *
 */
void mostrarUnActor(eActor unActor,ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion muestra una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return void
 *
 */
void mostrarListaDeActores(eActor listadoDeActores[], int tamActores,ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion recibe el id de un actor y muestra a ese actor
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param idActor int El id del actor que se quiere mostrar
 * \return void
 *
 */
void mostrarActorPorId(eActor listadoDeActores[], int tamActores, int idActor);

/** \brief Esta funcion permite cargar un actor en una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return int Devuelve 1 si no pudo acceder al ingreso de datos, -1 si no pudo realizar la carga de datos, 0 si pudo cargar al actor o 2 si el usuario cancelo la carga
 *
 */
int cargarUnActor(eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion pide el ingreso de datos para un elemento de tipo eActor
 *
 * \param name[] char El nombre del actor
 * \param lastName[] char El apellido del actor
 * \param sexo char* El sexo del actor
 * \return void
 *
 */
void obtenerDatosActor(char name[],char lastName[], char* sexo);
/** \brief Esta funcion muestra datos ingresado para un elemento de tipo eActor
 *
 * \param name[] char El nombre del actor
 * \param lastName[] char El apellido del actor
 * \param sexo char* El sexo del actor
 * \return void
 *
 */
void mostrarDatosActor(char name[],char lastName[], char sexo);
/** \brief Esta funcion agrega un actor a una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param codigo int El codigo del actor
 * \param name[] char El nombre del actor
 * \param lastName[] char El apellido del actor
 * \param sexo char El sexo del actor
 * \return int Devuelve -1 si no pudo agregarlo a la lista, caso contrario devuelve 0
 *
 */
int agregarActor(eActor listadoDeActores[], int tamActores, int codigo, char name[],char lastName[], char sexo);
/** \brief Esta funcion permite obtener un codigo nuevo para un actor
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return int Devuelve -1 si no pudo realizar el calculo del nuevo codigo, caso contrario devuelve el nuevo codigo
 *
 */
int obtenerNuevoCodigo(eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion busca el primer lugar disponible para la carga de datos dentro de una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return int Devuelve -1 si no hay lugar disponible, caso contrario devuelve el indice del primer lugar disponible
 *
 */
int obtenerLugarDisponibleActor(eActor listadoDeActores[], int tamActores);

/** \brief Esta funcion ordena los actores por apellido y nombre
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return void
 *
 */
int ordenarActores(eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion permite realizar modificaciones a los elementos dentro de una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param listadoDePeliculas[] ePelicula La lista de peliculas
 * \param tamPeliculas int El tamaño de la lista de peliculas
 * \return int Devuelve -1 si no logro encontrar al actor a modificar, 0 si el usuario cancelo la accion o 1 si se realizaron las modificaciones
 *
 */
int modificarUnActor(eActor listadoDeActores[], int tamActores, ePelicula listadoDePeliculas[], int tamPeliculas, ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion busca un actor de acuerdo a un codigo ingresado
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param codigo int El codigo del actor a buscar
 * \return int Si lo encontro, devuelve el indice del actor. Caso contrario, devuelve -1
 *
 */
int encontrarActorPorCodigo(eActor listadoDeActores[], int tamActores,int codigo);
/** \brief Esta funcion elimina a un actor de una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param listadoDePeliculas[] ePelicula La lista de peliculas
 * \param tamPeliculas int El tamaño de la lista de peliculas
 * \return int Devuelve -1 si no pudo acceder a la eliminacion, 0 si se elimino al actor, 1 si no logro encontrar al actor o 2 si el usuario cancelo la accion
 *
 */
int eliminarActor(eActor listadoDeActores[], int tamActores, ePelicula listaDePeliculas[], int tamPeliculas, ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion da de baja a un actor de una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param id int El id del actor a dar de baja
 * \return int Devuelve -1 si no pudo realizar la baja, caso contrario devuelve 0
 *
 */
int darBajaActor(eActor listadoDeActores[], int tamActores, int id);
/** \brief Esta funcion obtiene el codigo de un actor de una lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \return int Devuelve el codigo del actor ingresado
 *
 */
int obtenerIdActor(eActor listadoDeActores[], int tamActores,ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion valida que el id de actor ingresado exista en la lista de actores
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param id Actor int El id del actor a validar
 * \return int Devuelve 0 si logro encontrarlo, caso contrario devuelve -1
 *
 */
int validarIdActor(eActor listadoDeActores[], int tamActores, int idActor);
/** \brief Esta funcion retorna el actor al que corresponde el codigo ingresado
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param codigo int El codigo del actor que se pide
 * \return eActor El elemento de tipo eActor que se pide
 *
 */
eActor obtenerActor(eActor listadoDeActores[],int tamActor,int codigo);
/** \brief Esta funcion valida que el actor que corresponde al codigo ingresado este dado de alta
 *
 * \param listadoDeActores[] eActor La lista de actores
 * \param tamActores int El tamaño de la lista de actores
 * \param codigoActor int El codigo del actor que se pide
 * \return int Devuelve -1 si no esta dado de alta, caso contrario devuelve 0
 *
 */
int validarSiExisteActor(eActor listadoDeActores[], int tamActores, int codigoActor);
