#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int id;
    char descripcionPais[21];

}ePais;

/** \brief Esta funcion me permite hardcodear una lista de elementos de tipo ePais
 *
 * \param listadoDePaises[] ePais la lista de paises
 * \param tamPaises int el tamaño de la lista de paises
 * \return void
 *
 */
void hardcodearPaises(ePais listadoDePaises[], int tamPaises);
/** \brief Esta funcion me permite mostrar una lista de elementos de tipo ePais
 *
 * \param listaDePaises[] ePais la lista de paises
 * \param tamPais int el tamaño de la lista de paises
 * \return void
 *
 */
void mostrarListaPaises(ePais listaDePaises[], int tamPais);
/** \brief Esta funcion me permite mostrar un elemento de tipo ePais
 *
 * \param unPais ePais el elemento a mostrar
 * \return void
 *
 */
void mostrarUnPais(ePais unPais);

/** \brief Esta funcion me permite obtener un elemento de tipo ePais a traves de un id
 *
 * \param listadoDePaises[] ePais la lista de paises
 * \param tamPaises int el tamaño de la lista de paises
 * \param idNacionalidad int el id para realizar la busqueda
 * \return ePais el elemento de tipo ePais
 *
 */
ePais obtenerUnPaisPorId(ePais listaDePaises[], int tamPaises, int idNacionalidad);
