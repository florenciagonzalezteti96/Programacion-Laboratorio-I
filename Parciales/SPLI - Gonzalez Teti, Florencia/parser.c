#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Vuelos.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_VuelosDesdeTexto(FILE* pFile, LinkedList* pListaVuelos)
{
    int retorno = -1;
    eVuelos* unVuelo = NULL;

    char id_Vuelo[10];
    char id_Avion[30];
    char id_Piloto[30];
    char fecha[30];
    char destino[30];
    char cantidad_Pasajeros[30];
    char hora_Despegue[30];
    char hora_Llegada[30];

    if(pListaVuelos != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_Vuelo, id_Avion, id_Piloto, fecha, destino, cantidad_Pasajeros, hora_Despegue, hora_Llegada);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_Vuelo, id_Avion, id_Piloto, fecha, destino, cantidad_Pasajeros, hora_Despegue, hora_Llegada);
            unVuelo = eVuelos_newParametros(id_Vuelo, id_Avion, id_Piloto, fecha, destino, cantidad_Pasajeros, hora_Despegue, hora_Llegada);

            ll_add(pListaVuelos, unVuelo);
        }
        retorno = 0;

    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_VuelosDesdeBinario(FILE* pFile, LinkedList* pListaVuelos)
{
    int retorno = -1;
    eVuelos* unVuelo = NULL;
    if(pListaVuelos != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            unVuelo = eVuelos_new();
            if(unVuelo != NULL)
            {
                fread(unVuelo, sizeof(eVuelos), 1, pFile);
                if(feof(pFile))
                {
                    retorno = -1;
                    break;
                }
                ll_add(pListaVuelos, unVuelo);
            }
        }
        fclose(pFile);
        pFile = NULL;
        retorno = 0;
    }
    return retorno;
}
