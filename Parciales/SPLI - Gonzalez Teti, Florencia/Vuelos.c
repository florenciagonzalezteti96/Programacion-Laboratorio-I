#include "Vuelos.h"

eVuelos* eVuelos_new()
{
    eVuelos* unVuelo = (eVuelos*) malloc(sizeof(eVuelos));

    if(unVuelo != NULL)
    {
        unVuelo->id_Vuelo = 0;
        unVuelo->id_Avion = 0;
        unVuelo->id_Piloto = 0;
        strcpy(unVuelo->fecha,"");
        strcpy(unVuelo->destino,"");
        unVuelo->cantidad_Pasajeros = 0;
        unVuelo->hora_Despegue = 0;
        unVuelo->hora_Llegada = 0;
    }

    return unVuelo;
}

eVuelos* eVuelos_newParametros(char* id_Vuelo, char* id_Avion, char* id_Piloto, char* fecha, char* destino, char* cantidad_Pasajeros, char* hora_Despegue, char* hora_Llegada)
{
    eVuelos* unVuelo = eVuelos_new();

    if(id_Vuelo != NULL && id_Avion != NULL && id_Piloto != NULL && fecha != NULL && destino != NULL && cantidad_Pasajeros != NULL && hora_Despegue != NULL && hora_Llegada != NULL)
    {
        if(unVuelo != NULL)
        {
            eVuelos_set_IdVuelo(unVuelo, atoi(id_Vuelo));
            eVuelos_set_IdAvion(unVuelo, atoi(id_Avion));
            eVuelos_set_IdPiloto(unVuelo, atoi(id_Piloto));
            eVuelos_set_Fecha(unVuelo, fecha);
            eVuelos_set_Destino(unVuelo, destino);
            eVuelos_set_CantidadPasajeros(unVuelo, atoi(cantidad_Pasajeros));
            eVuelos_set_HoraDespegue(unVuelo, atoi(hora_Despegue));
            eVuelos_set_HoraLlegada(unVuelo, atoi(hora_Llegada));
        }
    }

    return unVuelo;
}
void eVuelos_delete(eVuelos* unVuelo)
{
    free(unVuelo);
    unVuelo = NULL;
}

int mostrarUnVuelo(eVuelos* unVuelo)
{
    int retorno = -1;
    int id_Vuelo;
    int id_Avion;
    int id_Piloto;
    char fecha[30];
    char destino[30];
    int cantidad_Pasajeros;
    int hora_Despegue;
    int hora_Llegada;

    if(unVuelo != NULL)
    {
        eVuelos_get_IdVuelo(unVuelo, &id_Vuelo);
        eVuelos_get_IdAvion(unVuelo, &id_Avion);
        eVuelos_get_IdPiloto(unVuelo, &id_Piloto);
        eVuelos_get_Fecha(unVuelo, fecha);
        eVuelos_get_Destino(unVuelo, destino);
        eVuelos_get_CantidadPasajeros(unVuelo, &cantidad_Pasajeros);
        eVuelos_get_HoraDespegue(unVuelo, &hora_Despegue);
        eVuelos_get_HoraLlegada(unVuelo, &hora_Llegada);

        printf("%8d", id_Vuelo);
        printf("%10d", id_Avion);
        switch(id_Piloto)
        {
        case 1:
            printf("%15s","Alex Lifeson");
            break;
        case 2:
            printf("%15s","Richard Bach");
            break;
        case 3:
            printf("%15s","John Kerry");
            break;
        case 4:
            printf("%15s","Erwin Rommel");
            break;
        case 5:
            printf("%15s","Stephen Coonts");
            break;
        }
        printf("%15s", fecha);
        printf("%15s", destino);
        printf("%25d", cantidad_Pasajeros);
        printf("%25d", hora_Despegue);
        printf("%25d\n", hora_Llegada);
        retorno = 0;
    }

    return retorno;
}
/** idVuelo */
int eVuelos_set_IdVuelo(eVuelos* unVuelo,int id_Vuelo)
{
    int retorno = -1;

    if(unVuelo != NULL)
    {
        unVuelo->id_Vuelo = id_Vuelo;
        retorno = 0;
    }

    return retorno;
}

int eVuelos_get_IdVuelo(eVuelos* unVuelo,int* id_Vuelo)
{
    int retorno = -1;

    if(unVuelo != NULL && id_Vuelo != NULL)
    {
        *id_Vuelo = unVuelo->id_Vuelo;
        retorno = 0;
    }

    return retorno;
}
/** idPiloto */
int eVuelos_set_IdPiloto(eVuelos* unVuelo, int id_Piloto)
{
    int retorno = -1;

    if(unVuelo != NULL)
    {
        unVuelo->id_Piloto = id_Piloto;
        retorno = 0;
    }

    return retorno;
}

int eVuelos_get_IdPiloto(eVuelos* unVuelo,int* id_Piloto)
{
    int retorno = -1;

    if(unVuelo != NULL && id_Piloto != NULL)
    {
        *id_Piloto = unVuelo->id_Piloto;
        retorno = 0;
    }

    return retorno;
}
/** idAvion */
int eVuelos_set_IdAvion(eVuelos* unVuelo, int id_Avion)
{
    int retorno = -1;

    if(unVuelo != NULL)
    {
        unVuelo->id_Avion = id_Avion;
        retorno = 0;
    }

    return retorno;
}

int eVuelos_get_IdAvion(eVuelos* unVuelo, int* id_Avion)
{
    int retorno = -1;

    if(unVuelo != NULL && id_Avion != NULL)
    {
        *id_Avion = unVuelo->id_Avion;
        retorno = 0;
    }

    return retorno;
}
/**fecha*/
int eVuelos_set_Fecha(eVuelos* unVuelo,char* fecha)
{
    int retorno = -1;

    if(unVuelo != NULL)
    {
        strcpy(unVuelo->fecha, fecha);
        retorno = 0;
    }

    return retorno;
}

int eVuelos_get_Fecha(eVuelos* unVuelo,char* fecha)
{
    int retorno = -1;

    if(unVuelo != NULL && fecha != NULL)
    {
        strcpy(fecha, unVuelo->fecha);
        retorno = 0;
    }

    return retorno;
}
/**destino*/
int eVuelos_set_Destino(eVuelos* unVuelo,char* destino)
{
    int retorno = -1;

    if(unVuelo != NULL)
    {
        strcpy(unVuelo->destino, destino);
        retorno = 0;
    }

    return retorno;
}

int eVuelos_get_Destino(eVuelos* unVuelo,char* destino)
{
    int retorno = -1;

    if(unVuelo != NULL && destino != NULL)
    {
        strcpy(destino, unVuelo->destino);
        retorno = 0;
    }

    return retorno;
}
/**cantidad pasajeros*/
int eVuelos_set_CantidadPasajeros(eVuelos* unVuelo, int cantidad_Pasajeros)
{
    int retorno = -1;

    if(unVuelo != NULL)
    {
        unVuelo->cantidad_Pasajeros = cantidad_Pasajeros;
        retorno = 0;
    }

    return retorno;
}

int eVuelos_get_CantidadPasajeros(eVuelos* unVuelo,int* cantidad_Pasajeros)
{
    int retorno = -1;

    if(unVuelo != NULL && cantidad_Pasajeros != NULL)
    {
        *cantidad_Pasajeros = unVuelo->cantidad_Pasajeros;
        retorno = 0;
    }

    return retorno;
}
/**hora despegue*/
int eVuelos_set_HoraDespegue(eVuelos* unVuelo,int hora_Despegue)
{
    int retorno = -1;

    if(unVuelo != NULL)
    {
        unVuelo->hora_Despegue = hora_Despegue;
        retorno = 0;
    }

    return retorno;
}

int eVuelos_get_HoraDespegue(eVuelos* unVuelo,int* hora_Despegue)
{
    int retorno = -1;

    if(unVuelo != NULL && hora_Despegue != NULL)
    {
        *hora_Despegue = unVuelo->hora_Despegue;
        retorno = 0;
    }

    return retorno;
}
/**hora llegada*/
int eVuelos_set_HoraLlegada(eVuelos* unVuelo, int hora_Llegada)
{
    int retorno = -1;

    if(unVuelo != NULL)
    {
        unVuelo->hora_Llegada = hora_Llegada;
        retorno = 0;
    }

    return retorno;
}

int eVuelos_get_HoraLlegada(eVuelos* unVuelo,int* horaLlegada)
{
    int retorno = -1;

    if(unVuelo != NULL && horaLlegada != NULL)
    {
        *horaLlegada = unVuelo->hora_Llegada;
        retorno = 0;
    }

    return retorno;
}
