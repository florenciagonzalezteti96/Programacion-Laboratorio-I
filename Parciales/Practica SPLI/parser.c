#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "eLlamada.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LlamadasDesdeTexto(FILE* pFile, LinkedList* pListaLlamadas)
{
    int retorno = -1;
    eLlamada* unaLlamada = NULL;

    char id_Llamada[20];
    char fecha[20];
    char numero_Cliente[20];
    char id_Problema[21];
    char solucionado[21];

    if(pListaLlamadas != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_Llamada, fecha, numero_Cliente, id_Problema, solucionado);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_Llamada, fecha, numero_Cliente, id_Problema, solucionado);
            unaLlamada = llamada_newParametros(id_Llamada, fecha, numero_Cliente, id_Problema, solucionado);

            ll_add(pListaLlamadas, unaLlamada);
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
int parser_LlamadasDesdeBinario(FILE* pFile, LinkedList* pListaLlamadas)
{
    int retorno = -1;
    eLlamada* unaLlamada = NULL;
    if(pListaLlamadas != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            unaLlamada = llamada_new();
            if(unaLlamada != NULL)
            {
                fread(unaLlamada, sizeof(eLlamada), 1, pFile);
                if(feof(pFile))
                {
                    retorno = -1;
                    break;
                }
                ll_add(pListaLlamadas, unaLlamada);
            }
        }
        fclose(pFile);
        pFile = NULL;
        retorno = 0;
    }
    return retorno;
}
