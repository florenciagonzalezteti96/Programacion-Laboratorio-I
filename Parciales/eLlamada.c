#include "eLlamada.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "inputs.h"

eLlamada* llamada_new()
{
    eLlamada* unaLlamada = (eLlamada*) malloc(sizeof(eLlamada));

    if(unaLlamada != NULL)
    {
        unaLlamada->id_Llamada = 0;
        strcpy(unaLlamada->fecha,"");
        unaLlamada->numero_Cliente = 0;
        unaLlamada->id_Problema = 0;
        strcpy(unaLlamada->solucionado,"");
    }

    return unaLlamada;
}

eLlamada* llamada_newParametros(char* id_Llamada, char* fecha, char* numero_Cliente, char* id_Problema, char* solucionado)
{
    eLlamada* unaLlamada = llamada_new();

    if(id_Llamada != NULL && fecha != NULL && numero_Cliente != NULL && id_Problema != NULL && solucionado != NULL)
    {
        if(unaLlamada != NULL)
        {
            eLlamada_set_IdLlamada(unaLlamada, atoi(id_Llamada));
            eLlamada_set_fecha(unaLlamada, fecha);
            eLlamada_set_numeroCliente(unaLlamada, atoi(numero_Cliente));
            eLlamada_set_idProblema(unaLlamada, atoi(id_Problema));
            eLlamada_get_solucionado(unaLlamada, solucionado);
        }
    }

    return unaLlamada;
}

void llamada_delete(eLlamada* unaLlamada)
{
    free(unaLlamada);
    unaLlamada = NULL;
}

int mostrarUnaLlamada(eLlamada* unaLlamada)
{
    int retorno = -1;

    if(unaLlamada != NULL)
    {
        printf("%4d", unaLlamada->id_Llamada);
        printf("%18s", unaLlamada->fecha);
        printf("%20d", unaLlamada->numero_Cliente);
        printf("%20d", unaLlamada->id_Problema);
        printf("%25s\n", unaLlamada->solucionado);
        retorno = 0;
    }

    return retorno;
}
/**id_Llamada*/
int eLlamada_set_IdLlamada(eLlamada* unaLlamada,int id_Llamada)
{
    int retorno = -1;

    if(unaLlamada != NULL)
    {
        unaLlamada->id_Llamada = id_Llamada;
        retorno = 0;
    }

    return retorno;
}

int eLlamada_get_IdLlamada(eLlamada* unaLlamada,int* id_Llamada)
{
    int retorno = -1;

    if(unaLlamada != NULL && id_Llamada != NULL)
    {
        *id_Llamada = unaLlamada->id_Llamada;
        retorno = 0;
    }

    return retorno;
}
/**fecha*/
int eLlamada_set_fecha(eLlamada* unaLlamada, char* fecha)
{
    int retorno = -1;

    if(unaLlamada != NULL && fecha != NULL)
    {
        strcpy(unaLlamada->fecha, fecha);
        retorno = 0;
    }

    return retorno;
}

int eLlamada_get_fecha(eLlamada* unaLlamada,char* fecha)
{
    int retorno = -1;

    if(unaLlamada != NULL && fecha != NULL)
    {
        strcpy(fecha, unaLlamada->fecha);
        retorno = 0;
    }

    return retorno;
}
/**numero_Cliente*/
int eLlamada_set_numeroCliente(eLlamada* unaLlamada,int numeroCliente)
{
    int retorno = -1;

    if(unaLlamada != NULL)
    {
        unaLlamada->numero_Cliente = numeroCliente;
        retorno = 0;
    }

    return retorno;
}

int eLlamada_get_numeroCliente(eLlamada* unaLlamada, int* numeroCliente)
{
    int retorno = -1;

    if(unaLlamada != NULL && numeroCliente != NULL)
    {
        *numeroCliente = unaLlamada->numero_Cliente;
        retorno = 0;
    }

    return retorno;
}
/**id_Problema*/
int eLlamada_set_idProblema(eLlamada* unaLlamada,int id_Problema)
{
    int retorno = -1;

    if(unaLlamada != NULL)
    {
        unaLlamada->id_Problema = id_Problema;
        retorno = 0;
    }

    return retorno;
}

int eLlamada_get_idProblema(eLlamada* unaLlamada,int* id_Problema)
{
    int retorno = -1;

    if(unaLlamada != NULL && id_Problema != NULL)
    {
        *id_Problema = unaLlamada->id_Problema;
        retorno = 0;
    }

    return retorno;
}
/**solucionado*/
int eLlamada_set_solucionado(eLlamada* unaLlamada,char* solucionado)
{
    int retorno = -1;

    if(unaLlamada != NULL)
    {
        strcpy(unaLlamada->solucionado, solucionado);
        retorno = 0;
    }

    return retorno;
}

int eLlamada_get_solucionado(eLlamada* unaLlamada,char* solucionado)
{
    int retorno = -1;

    if(unaLlamada != NULL && solucionado != NULL)
    {
        strcpy(solucionado, unaLlamada->solucionado);
        retorno = 0;
    }

    return retorno;
}
int compararPor_IdProblema(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    int idProblema_Uno;
    int idProblema_Dos;

    eLlamada* llamada_Uno = (eLlamada*) pElementOne;
    eLlamada* llamada_Dos = (eLlamada*) pElementTwo;

    eLlamada_get_idProblema(llamada_Uno, &idProblema_Uno);
    eLlamada_get_idProblema(llamada_Dos, &idProblema_Dos);

    if(idProblema_Uno > idProblema_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(idProblema_Uno == idProblema_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}

void pedirDatosLlamada(char* idProblema, char* fecha, char* numero_Cliente, char* id_Problema, char* solucionado)
{
    pedirCadena("Ingrese la fecha de la llamada: ", fecha);
    pedirCadenaSoloNumeros("Ingrese el numero del cliente de la llamada: ", numero_Cliente);
    pedirCadenaSoloNumeros("Ingrese el id del problema: ", idProblema);
    pedirCadena("¿Ha sido solucionado el problema? Ingrese SI o NO: ", solucionado);
}

