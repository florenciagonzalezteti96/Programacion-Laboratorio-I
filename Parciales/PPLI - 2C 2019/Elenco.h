#include "Inputs.h"
#include "Actor.h"
#define VACIO 0
#define OCUPADO 1

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
void mostrarMenuElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores, eFecha listadoDeFechas[], int tamFechas, ePais listadoDePaises[], int tamPaises);
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
void mostrarMenus(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores, eFecha listadoDeFechas[], int tamFechas, ePais listadoDePaises[], int tamPaises);
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
int agregarUnElenco(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores, eFecha listadoDeFechas[], int tamFechas, ePais listadoDePaises[], int tamPaises);
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
eElenco agregarUnActorAElenco(eElenco listadoDeElencos[], int tamElencos, eActor listadoDeActores[], int tamActores, int idPelicula, int valorContrato, ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion muestra un elemento de tipo eElenco
 *
 * \param unElenco eElenco El elemento a mostrar
 * \param listadoDePeliculas[] ePelicula La lista de estructuras ePelicula
 * \param tamPeliculas int El tamaño de la lista de estructuras ePelicula
 * \param listadoDeActores[] eActor La lista de estructuras eActor
 * \param tamActores int El tamaño de la lista de estructuras eActor
 * \return void
 */
void mostrarUnElenco(eElenco unElenco, ePelicula listadoDePeliculas[], int tamPelicula, eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion muestra una lista de elementos de tipo eElenco
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
void mostrarListaElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion valida si los datos ingresados ya existen dentro de la lista de elencos
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \param unElenco eElenco El elemento con los datos ingresados a validar
 * \return int Devuelve -1 si los datos ingresados estan repetidos, caso contrario devuelve 0
 *
 */
int validarSiExiste(eElenco listadoDeElencos[], int tamElencos, eElenco unElenco);
/** \brief Esta funcion ordena los elencos por nombre de pelicula y, ante igualdad de criterio, por apellido de actor
 *
 * \param listadoDeElencos[] eElenco La lista de estructuras eElenco
 * \param tamElencos int El tamaño de la lista de estructuras eElenco
 * \param listadoDePeliculas[] ePelicula La lista de estructuras ePelicula
 * \param tamPeliculas int El tamaño de la lista de estructuras ePelicula
 * \param listadoDeActores[] eActor La lista de estructuras eActor
 * \param tamActores int El tamaño de la lista de estructuras eActor
 * \return int Devuelve -1 si no pudo acceder al ordenamiento, caso contrario devuelve 0
 *
 */
int ordenarElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eActor listadoDeActores[], int tamActores);
/** \brief Esta funcion encuentra minimo una incidencia de una pelicula de terror estrenada despues del 2002
 *
 * \param listaDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \param listaDeGeneros[] eGenero la lista de generos
 * \param tamGeneros int el tamaño de la lista de generos
 * \param listaDePeliculas[] ePelicula la lista de peliculas
 * \param tamPeliculas int el tamaño de la lista de peliculas
 * \return int devuelve -1 si no encontro ninguna pelicula que se encuentre en ese rango, caso contrario devuelve 0
 *
 */
int encontrarPeliculasDeTerrorEstrenadasPos2002(eFecha listaDeFechas[], int tamFechas, eGenero listaDeGeneros[], int tamGeneros, ePelicula listaDePeliculas[], int tamPeliculas);
/** \brief Esta funcion muestra las peliculas de terror estrenadas despues del 2002
 *
 * \param listaDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \param listaDeGeneros[] eGenero la lista de generos
 * \param tamGeneros int el tamaño de la lista de generos
 * \param listaDePeliculas[] ePelicula la lista de peliculas
 * \param tamPeliculas int el tamaño de la lista de peliculas
 * \return void
 *
 */
void mostrarPeliculasDeTerrorEstrenadasPos2002(eFecha listaDeFechas[], int tamFechas, eGenero listaDeGeneros[], int tamGeneros, ePelicula listaDePeliculas[], int tamPeliculas);

/** \brief Esta funcion lista las peliculas de terror estrenadas despues del 2002 si las hay
 *
 * \param listaDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \param listaDeGeneros[] eGenero la lista de generos
 * \param tamGeneros int el tamaño de la lista de generos
 * \param listaDePeliculas[] ePelicula la lista de peliculas
 * \param tamPeliculas int el tamaño de la lista de peliculas
 * \return int devuelve -1 si no hay ninguna pelicula para listar caso contrario las lista y devuelve 0
 *
 */
int listarPeliculasDeTerrorEstrenadasPos2002(eFecha listaDeFechas[], int tamFechas, eGenero listaDeGeneros[], int tamGeneros, ePelicula listaDePeliculas[], int tamPeliculas);
/** \brief Esta funcion despliega un menu de informes
 *
 * \param listadoDeElencos[] eElenco la lista de elencos
 * \param tamElencos int el tamaño de la lista de elencos
 * \param listadoDePeliculas[] ePelicula la lista de peliculas
 * \param tamPeliculas int el tamaño de la lista de peliculas
 * \param listadoDeGeneros[] eGenero la lista de generos
 * \param tamGeneros int el tamaño de la lista de generos
 * \param listadoDeActores[] eActor la lista de actores
 * \param tamActores int el tamaño de la lista de actores
 * \param listadoDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \param listadoDePaises[] ePais la lista de paises
 * \param tamPaises int el tamaño de la lista de paises
 * \return void
 *
 */
void mostrarMenuInformes(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores, eFecha listadoDeFechas[], int tamFechas, ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion muuestra las peliculas en las que trabaja un actor argentino
 *
 * \param listaDeElencos[] eElenco la lista de elencos
 * \param tamElencos int el tamaño de la lista de elencos
 * \param listaDePeliculas[] ePelicula la lista de peliculas
 * \param tamPeliculas int el tamaño de la lista de peliculas
 * \param listaDeActores[] eActor la lista de actores
 * \param tamActores int el tamaño de la lista de actores
 * \param listaDePaises[] ePais la lista de paises
 * \param tamPais int el tamaño de la lista de paises
 * \return int devuelve -1 si ningun actor argentino trabaja en ninguna pelicula, caso contrario los muestra y devulve 0
 *
 */
int mostrarPeliculasConActorArgentino(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores, ePais listaDePaises[], int tamPais);
/** \brief Esta funcion muestra las peliculas en las que trabaja un actor seleccionado
 *
 * \param listaDeElencos[] eElenco la lista de elencos
 * \param tamElencos int el tamaño de la lista de elencos
 * \param listaDePeliculas[] ePelicula la lista de peliculas
 * \param tamPeliculas int el tamaño de la lista de peliculas
 * \param listaDeActores[] eActor la lista de actores
 * \param tamActores int el tamaño de la lista de actores
 * \param listaDePaises[] ePais la lista de paises
 * \param tamPais int el tamaño de la lista de paises
 * \param listaDeGeneros[] eGenero la lista de generos
 * \param tamGeneros int el tamaño de la lista de generos
 * \param listaDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \return int devuelve -1 si el actor seleccionado no trbaja en ninguna pelicula, caso contrario devuelve 0
 *
 */
int mostrarPeliculasDelActorSeleccionado(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores, ePais listaDePaises[], int tamPais, eGenero listaDeGeneros[], int tamGeneros, eFecha listaDeFechas[], int tamFechas);
/** \brief Esta funcion calcula el total recaudado por un actor en todas las peliculas romanticas en las que trabajo
 *
 * \param listaDeElencos[] eElenco la lista de elencos
 * \param tamElencos int el tamaño de la lista de elencos
 * \param listaDePeliculas[] ePelicula la lista de peliculas
 * \param tamPeliculas int el tamaño de la lista de peliculas
 * \param listaDeActores[] eActor la lista de actores
 * \param tamActores int el tamaño de la lista de actores
 * \param listaDeGeneros[] eGenero la lista de generos
 * \param tamGeneros int el tamaño de la lista de generos
 * \param listaDePaises[] ePais la lista de paises
 * \param tamPaises int el tamaño de la lista de paises
 * \return float devuelve 0 si no trabaja en ninguna pelicula romantica, caso contrario devuelve la suma total recaudada
 *
 */
float calcularTotalContratoEnRomanticasActorSeleccionado(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores, eGenero listaDeGeneros[], int tamGeneros, ePais listaDePaises[], int tamPaises);
/** \brief Esta funcion muestra el total recaudado por un actor en todas las peliculas romanticas en las que trabajo
 *
 * \param listaDeElencos[] eElenco la lista de elencos
 * \param tamElencos int el tamaño de la lista de elencos
 * \param listaDePeliculas[] ePelicula la lista de peliculas
 * \param tamPeliculas int el tamaño de la lista de peliculas
 * \param listaDeActores[] eActor la lista de actores
 * \param tamActores int el tamaño de la lista de actores
 * \param listaDeGeneros[] eGenero la lista de generos
 * \param tamGeneros int el tamaño de la lista de generos
 * \param listaDePaises[] ePais la lista de paises
 * \param tamPaises int el tamaño de la lista de paises
 * \return int Devuelve -1 si el total recaudado es 0, caso contrario devuelve 0
 *
 */
int mostrarTotalGananciasDeActorRomance(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores, eGenero listaDeGeneros[], int tamGeneros,ePais listaDePaises[], int tamPaises);
/** \brief Esta funcion muestra una lista de los actores que no trabajan en ninguna pelicula
 *
 * \param listaDeActores[] eActor la lista de actores
 * \param tamActores int el tamaño de la lista de actores
 * \param listaDeElencos[] eElenco la lista de elencos
 * \param tamElencos int el tamaño de la lista de elencos
 * \param listaDePaises[] ePais la lista de paises
 * \param tamPaises int el tamaño de la lista de paises
 * \return int Devuelve -1 si no hay actores que no actuen en ninguna pelicula, caso contrario devuelve 0
 *
 */
int mostrarSiNoActua(eActor listaDeActores[], int tamActores, eElenco listaDeElencos[], int tamElencos, ePais listaDePaises[], int tamPaises);
/** \brief Esta funcion busca si el actor en particular trabaja en una pelicula
 *
 * \param unActor eActor El actor con el cual yo busco incidencias
 * \param listaDeElencos[] eElenco  la lista de elencos
 * \param tamElencos int el tamaño de la lista de elencos
 * \return int Devuelve -1 si actuo en minimo una pelicula, caso contrario devuelve 0
 *
 */
int buscarSiActua(eActor unActor, eElenco listaDeElencos[], int tamElencos);

/** \brief Esta funcion me permite obtener un elemento de tipo eElenco por medio de un indice
 *
 * \param listaDeElencos[] eElenco  la lista de elencos
 * \param tamElencos int el tamaño de la lista de elencos
 * \param indice int El indice del elemento
 * \return eElenco el elemento que yo busco.
 *
 */
eElenco obtenerElencoPorIndice(eElenco listaDeElencos[], int tamElencos, int indice);
void mostrarPeliculasConActoresDeAvellaneda(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores);
void mostrarActoresMayoresA30YConAlMenosUnPremio(eActor listadoDeActores[], int tamActores);
void mostrarEdadDeCadaActor(eActor listadoDeActores[], int tamActores);
void mostrarCantidadDePremiosEnUnElenco(eGenero listaDeGeneros[], int tamGeneros, eFecha listaDeFechas[], int tamFechas, eElenco listadoDeElencos[], int tamElencos, eActor listadoDeActores[], int tamActores, ePelicula listadoDePeliculas[], int tamPeliculas);


