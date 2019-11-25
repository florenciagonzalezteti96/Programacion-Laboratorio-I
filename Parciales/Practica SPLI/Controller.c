#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "eLlamada.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pListaLlamadas LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pListaLlamadas)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;

    pFile = fopen(path,"r");

    if(pFile != NULL && pListaLlamadas != NULL)
    {
        isEmpty = ll_isEmpty(pListaLlamadas);
        if(isEmpty == 1)
        {
            retorno = parser_LlamadasDesdeTexto(pFile, pListaLlamadas);
        }
        else
        {
            retorno = 2;
        }
    }

    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pListaLlamadas LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pListaLlamadas)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;

    pFile = fopen(path,"rb");

    if(pFile != NULL && pListaLlamadas != NULL)
    {
        isEmpty = ll_isEmpty(pListaLlamadas);
        if(isEmpty == 1)
        {
            retorno = parser_LlamadasDesdeBinario(pFile, pListaLlamadas);
        }
        else
        {
            retorno = 2;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListarLlamadas(LinkedList* pListaLlamadas)
{
    int retorno = -1;
    int i;
    int len;
    int isEmpty = 0;

    if(pListaLlamadas != NULL)
    {
        retorno = 0;
        isEmpty = ll_isEmpty(pListaLlamadas);
        if(isEmpty != 1)
        {
            len = ll_len(pListaLlamadas);
            eLlamada* auxLlamada;
            printf("%4s%20s%20s%22s%25s\n","Id Llamada:", "Fecha:", "Numero del Cliente:","Id Problema:","Esta solucionado:");
            for(i=0; i<len; i++)
            {
                auxLlamada = (eLlamada*) ll_get(pListaLlamadas, i);
                mostrarUnaLlamada(auxLlamada);
                /*if(i!=0 && i%150==0)
                {
                    system("pause");
                }*/
            }
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pListaLlamadas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pListaLlamadas)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    eLlamada* auxLlamada = NULL;

    int id_Llamada;
    char fecha[12];
    int numero_Cliente;
    int id_Problema;
    char solucionado[2];

    if(pListaLlamadas != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pListaLlamadas);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id Llamada,Fecha,Numero Cliente,Id Problema,Solucionado\n");
            for(i=0; i<len; i++)
            {
                auxLlamada = (eLlamada*) ll_get(pListaLlamadas, i);
                eLlamada_get_IdLlamada(auxLlamada, &id_Llamada);
                eLlamada_get_fecha(auxLlamada, fecha);
                eLlamada_get_numeroCliente(auxLlamada, &numero_Cliente);
                eLlamada_get_idProblema(auxLlamada, &id_Problema);
                eLlamada_get_solucionado(auxLlamada, solucionado);

                fprintf(pFile, "%d,%s,%d,%d,%s\n", id_Llamada, fecha, numero_Cliente, id_Problema, solucionado);
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pListaLlamadas LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pListaLlamadas)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    eLlamada* auxLlamada = NULL;

    if(pListaLlamadas != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");//abro el archivo en modo escritura
        len = ll_len(pListaLlamadas);

        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                auxLlamada = (eLlamada*) ll_get(pListaLlamadas, i);
                fwrite(auxLlamada, sizeof(eLlamada), 1, pFile);
            }
        }
        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

int dameMayorId(LinkedList* pListaLlamadas)
{
    int retorno = -1;
    if(pListaLlamadas != NULL)
    {
        int len;
        int flag = 0;
        int i;
        eLlamada* auxLlamada;

        len = ll_len(pListaLlamadas);

        for(i=0; i<len; i++)
        {
            auxLlamada = (eLlamada*) ll_get(pListaLlamadas, i);
            if(flag == 0 || retorno < auxLlamada->id_Llamada)
            {
                retorno = auxLlamada->id_Llamada;
                flag = -1;
            }
        }
    }
    return retorno;
}

int dameProximoId(LinkedList* pListaLlamadas)
{
    int retorno = -1;
    if(pListaLlamadas != NULL)
    {
        retorno = dameMayorId(pListaLlamadas);
        retorno++;
    }
    return retorno;
}


