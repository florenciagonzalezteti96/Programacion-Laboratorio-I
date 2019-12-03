#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

/** \brief Esta funcion me permite hardcodear una lista de elementos de tipo eFecha
 *
 * \param listadoDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \return void
 *
 */
void hardcodearFechas(eFecha listadoDeFechas[], int tamFechas);
/** \brief Esta funcion me permite mostrar un elemento de tipo eFecha
 *
 * \param unaFecha eFecha el elemento a mostrar
 * \return void
 *
 */
void mostrarUnaFecha(eFecha unaFecha);
/** \brief Esta funcion me permite validar si el codigo ingresado de una fecha existe
 *
 * \param listadoDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \param codigoFecha int el codigo ingresado
 * \return int Devuelve -1 si no existe, caso contrario devuelve 0
 *
 */
int existeCodigoFecha(eFecha listadoDeFechas[], int tamFechas, int codigoFecha);
/** \brief Esta funcion me permite obtener el indice de un elemento de tipo eFecha dentro de una lista
 *
 * \param listadoDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \param idFecha int El codigo del elemento
 * \return int Devuelve -1 si no lo encontro, caso contrario devuelve el indice
 *
 */
int buscarIndiceFecha(eFecha listadoDeFechas[], int tamFechas, int idFecha);
/** \brief Esta funcion me permite obtener un elemento de tipo eFecha a traves de un codigo
 *
 * \param listadoDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \param codigoFecha int el codigo del elemento a buscar
 * \return eFecha el elemento de tipo eFecha
 *
 */
eFecha obtenerUnaFechaPorCodigo(eFecha listadoDeFechas[], int tamFechas, int codigoFecha);
/** \brief Esta funcion me permite obtener una fecha a traves de un indice
 *
 * \param listaDeFechas[] eFecha la lista de fechas
 * \param tamFechas int el tamaño de la lista de fechas
 * \param indice int el indice del elemento a buscar
 * \return eFecha el elemento buscado
 *
 */
eFecha obtenerFechaPorIndice(eFecha listaDeFechas[], int tamFechas, int indice);
