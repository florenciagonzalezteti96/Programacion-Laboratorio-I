#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pListaLlamadas LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pListaVuelos)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;

    pFile = fopen(path,"r");

    if(pFile != NULL && pListaVuelos != NULL)
    {
        isEmpty = ll_isEmpty(pListaVuelos);
        if(isEmpty == 1)
        {
            retorno = parser_VuelosDesdeTexto(pFile, pListaVuelos);
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
int controller_loadFromBinary(char* path, LinkedList* pListaVuelos)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;

    pFile = fopen(path,"rb");

    if(pFile != NULL && pListaVuelos != NULL)
    {
        isEmpty = ll_isEmpty(pListaVuelos);
        if(isEmpty == 1)
        {
            retorno = parser_VuelosDesdeBinario(pFile, pListaVuelos);
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
int controller_ListarVuelos(LinkedList* pListaVuelos)
{
    int retorno = -1;
    int i;
    int len;
    int isEmpty = 0;

    if(pListaVuelos!= NULL)
    {
        retorno = 0;
        isEmpty = ll_isEmpty(pListaVuelos);
        if(isEmpty != 1)
        {
            len = ll_len(pListaVuelos);
            eVuelos* auxVuelo;
            printf("%5s%10s%15s%15s%15s%25s%25s%25s\n","Id Vuelo:", "Id Avion:", "Id Piloto:","Fecha:","Destino:","Cantidad De Pasajeros:","Hora de despegue:","Hora de llegada:");
            for(i=0; i<len; i++)
            {
                auxVuelo = (eVuelos*) ll_get(pListaVuelos, i);
                mostrarUnVuelo(auxVuelo);
                if(i!=0 && i%25==0)
                {
                    system("pause");
                }
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
int controller_saveAsText(char* path, LinkedList* pListaVuelos)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    eVuelos* auxVuelos = NULL;

    int id_Vuelo;
    int id_Avion;
    int id_Piloto;
    char fecha[21];
    char destino[21];
    int cantidad_Pasajeros;
    int hora_Despegue;
    int hora_Llegada;

    if(pListaVuelos != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pListaVuelos);

        if(pFile != NULL)
        {
            fprintf(pFile, "IdVuelo,IdAvion,IdPiloto,Fecha,Destino,CantidadDePasajeros,Horadedespegue,Horadellegada\n");
            for(i=0; i<len; i++)
            {
                auxVuelos = (eVuelos*) ll_get(pListaVuelos, i);
                eVuelos_get_IdVuelo(auxVuelos, &id_Vuelo);
                eVuelos_get_IdAvion(auxVuelos, &id_Avion);
                eVuelos_get_IdPiloto(auxVuelos, &id_Piloto);
                eVuelos_get_Fecha(auxVuelos, fecha);
                eVuelos_get_Destino(auxVuelos, destino);
                eVuelos_get_CantidadPasajeros(auxVuelos, &cantidad_Pasajeros);
                eVuelos_get_HoraDespegue(auxVuelos, &hora_Despegue);
                eVuelos_get_HoraLlegada(auxVuelos, &hora_Llegada);

                fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n", id_Vuelo, id_Avion, id_Piloto, fecha, destino, cantidad_Pasajeros, hora_Despegue, hora_Llegada);
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
int controller_saveAsBinary(char* path, LinkedList* pListaVuelos)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    eVuelos* auxVuelos = NULL;

    if(pListaVuelos != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");//abro el archivo en modo escritura
        len = ll_len(pListaVuelos);

        if(pFile != NULL)
        {
            for(i=0; i<len; i++)
            {
                auxVuelos = (eVuelos*) ll_get(pListaVuelos, i);
                fwrite(auxVuelos, sizeof(eVuelos), 1, pFile);
            }
        }
        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

/*int dameMayorId(LinkedList* pLista)
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
*/
/*int filtrarPorUno(void* pVuelo)
{
    int retorno = -1;
    eVuelos* unVuelo = pVuelo;

    if(unVuelo != NULL)
    {
        retorno = 1;

        if(unVuelo->id_Problema == 1)
        {
            retorno = 0;
        }
    }

    return retorno;
}*/
int filtrarPorPortugal(void* pVuelo)
{
    int retorno = -1;
    eVuelos* unVuelo = pVuelo;
    char destino[30];

    if(unVuelo != NULL)
    {
        retorno = 1;
        eVuelos_get_Destino(unVuelo, destino);

        if(stricmp(destino,"Portugal") == 0)
        {
            retorno = 0;
        }
    }

    return retorno;
}
int filtrarPorAlex(void* pVuelo)
{
    int retorno = -1;
    eVuelos* unVuelo = pVuelo;
    int id_Piloto;

    if(unVuelo != NULL)
    {
        retorno = 1;
        eVuelos_get_IdPiloto(unVuelo, &id_Piloto);

        if(id_Piloto != 1)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int filtrar_EsMenorA3Horas(void* pVuelo)
{
    int retorno = -1;
    int totalHoras;
    int hora_Despegue;
    int hora_Llegada;
    eVuelos* unVuelo = pVuelo;

    if(pVuelo != NULL)
    {
        retorno = 1;
        eVuelos_get_HoraDespegue(unVuelo, &hora_Despegue);
        eVuelos_get_HoraLlegada(unVuelo, &hora_Llegada);

        totalHoras = hora_Llegada-hora_Despegue;

        if(totalHoras < 3)
        {
            retorno = 0;
        }
    }
    return retorno;
}

/*
int filtrarPorDos(void* pLlamada)
{
    int retorno = -1;
    eLlamada* unaLlamada = pLlamada;

    if(unaLlamada != NULL)
    {
        retorno = 1;

        if(unaLlamada->id_Problema == 2)
        {
            retorno = 0;
        }
    }

    return retorno;
}
int filtrarPorTres(void* pLlamada)
{
    int retorno = -1;
    eLlamada* unaLlamada = pLlamada;

    if(unaLlamada != NULL)
    {
        retorno = 1;

        if(unaLlamada->id_Problema == 3)
        {
            retorno = 0;
        }
    }

    return retorno;
}
int filtrarPorCuatro(void* pLlamada)
{
    int retorno = -1;
    eLlamada* unaLlamada = pLlamada;

    if(unaLlamada != NULL)
    {
        retorno = 1;

        if(unaLlamada->id_Problema == 4)
        {
            retorno = 0;
        }
    }

    return retorno;
}
int filtrarPorCinco(void* pLlamada)
{
    int retorno = -1;
    eLlamada* unaLlamada = pLlamada;

    if(unaLlamada != NULL)
    {
        retorno = 1;

        if(unaLlamada->id_Problema == 5)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int settear (void* pLlamada)
{
    int retorno = -1;
    eLlamada* pUnaLlamada = pLlamada;

    if(pUnaLlamada != NULL)
    {

    }

    if( isdigit(pDominio->dominio[0]) == 1 )
    {
        pDominio->tipo= 'M';
        todoOk=1;
    }
    else
    {
        pDominio->tipo='A';
        todoOk=1;
    }

    return retorno;
}*/

