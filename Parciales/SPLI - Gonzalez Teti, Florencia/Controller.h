#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vuelos.h"

/** \brief Esta funcion carga una lista dinamica con datos de un archivo ya existente, en modo texto
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Devuelve -1 si pudo realizar la carga de datos, 0 si logro abrir el archivo y cargar los datos, 1 si la lista o el puntero al archivo son nulos, 2 si la lista ya fue cargada.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
/** \brief Esta funcion carga una lista dinamica con datos de un archivo ya existente, en modo binario
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Devuelve -1 si pudo realizar la carga de datos, 0 si logro abrir el archivo y cargar los datos, 1 si la lista o el puntero al archivo son nulos, 2 si la lista ya fue cargada.
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee);

int controller_ListarVuelos(LinkedList* pListaVuelos);

/** \brief Esta funcion permite guardar los cambios realizados a los datos cargados en una lista dinamica en modo texto
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Devuelve -1 si la lista o el puntero al archivo son nulos, 0 si logro guardar los datos
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
/** \brief Esta funcion permite guardar los cambios realizados a los datos cargados en una lista dinamica en modo binario
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Devuelve -1 si la lista o el puntero al archivo son nulos, 0 si logro guardar los datos
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);
/** \brief Esta funcion recorre una lista dinamica con datos de tipo empleado y busca el mayor ID
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si la lista es nula, caso contrario devuelve el mayor id
 *
 */
/*int dameMayorId(LinkedList* pArrayListEmployee);
* \brief Esta funcion calcula el id del proximo empleado a agregar en una lista dinamica
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si la lista es nula, caso contrario devuelve el proximo id
 *

int dameProximoId(LinkedList* pArrayListEmployee);
* \brief Esta funcion busca a un empleado por id, dentro de una lista dinamica, y si lo encuentra, lo retorna
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \param id int el id del empleado a encontrar
 * \return void* Devuelve el empleado si lo encontro, caso contrario devuelve NULL
 *

* \brief Esta funcion permite obtener un empleado por su ID
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \param id int el id del empleado a encontrar
 * \return void* Devuelve el empleado si lo encontro, caso contrario devuelve NULL
 *

void* getEmployeeById(LinkedList* pArrayListEmployee, int id);*/

int filtrarPorPortugal(void* pVuelo);
int filtrar_EsMenorA3Horas(void* pVuelo);
int filtrarPorAlex(void* pVuelo);
/*int filtrarPorUno(void* unaLlamada);
int filtrarPorDos(void* unaLlamada);
int filtrarPorTres(void* unaLlamada);
int filtrarPorCuatro(void* unaLlamada);
int filtrarPorCinco(void* unaLlamada);*/

