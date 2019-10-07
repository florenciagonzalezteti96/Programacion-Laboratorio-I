#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

typedef struct{
    int contadorVocales;
    char vocales [5];
}eVocales;
typedef struct{
    int id;
    char procesador[3][10];
    char marca[3][10];
    float precio;
}eNotebook;

/** \brief Inicializa el auxiliar de array de estructuras
 *
 * \param eVocales[] array de eVocales
 * \param int el tamaño del array de vocales
 * \return void
 *
 */
void init_eVocales(eVocales[], int);
/** \brief Esta funcion verifica el maximo de inicidencias de una vocal en una cadena ingresada e informa de la vocal con mayor incidencias.
 *
 * \param cadena[] char Cadena ingresada
 * \return char Vocal con mayor incidencias
 *
 */
char verificarVocales(char cadena[]);
/** \brief Esta funcion busca el mayor contador de vocales en un array de estructura eVocales
 *
 * \param list[] eVocales el array de estructuras
 * \param tam int El tamaño del array
 * \return int Devuelve el mayor contador
 *
 */
int getMaximoDeVocales(eVocales list[], int tam);
/** \brief Esta funcion carga los contadores de cada vocal de la lista de eVocales con todas las incidencias de las vocales en una cadena
 *
 * \param list eVocales* la lista de eVocales con cada vocal y el contador de la misma
 * \param tamLista int El tamaño de la lista
 * \param cadena[] char La cadena ingresada
 * \param tamCadena int El tamaño de la cadena ingresada
 * \return void
 *
 */
void cargarContadoresDeVocales(eVocales* list, int tamLista, char cadena[], int tamCadena);
/** \brief Esta vocal me informa cual es la vocal con mayor incidencias dentro de una cadena ingresada
 *
 * \param list[] eVocales La lista con las vocales
 * \param tam int El tamaño de la lista
 * \param mayorContador int El mayor numero de incidencias de una vocal en la cadena
 * \return char La vocal que mayor veces aparece
 *
 */
char dameVocalQueApareceMas(eVocales list[], int tam, int mayorContador);

/** \brief Esta funcion inicializa un array de estructuras Noteboook
 *
 * \param list[] eNotebook el array de estructuras
 * \param tamList int El tamaño del array
 * \return void
 *
 */
void init_eNotebook(eNotebook list[], int tamList);
void ordenarListaNotebooks(eNotebook list[], int tamList);
