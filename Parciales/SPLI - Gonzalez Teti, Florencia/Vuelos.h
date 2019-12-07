#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int id_Vuelo;
    int id_Avion;
    int id_Piloto;
    char fecha[21];
    char destino[21];
    int cantidad_Pasajeros;
    int hora_Despegue;
    int hora_Llegada;

}eVuelos;

eVuelos* eVuelos_new();
eVuelos* eVuelos_newParametros(char* id_Vuelo, char* id_Avion, char* id_Piloto, char* fecha, char* destino, char* cantidad_Pasajeros, char* hora_Despegue, char* hora_Llegada);

void eVuelos_delete(eVuelos* unVuelo);
int mostrarUnVuelo(eVuelos* unVuelo);

int eVuelos_set_IdVuelo(eVuelos* unVuelo,int id_Vuelo);
int eVuelos_get_IdVuelo(eVuelos* unVuelo,int* id_Vuelo);

int eVuelos_set_IdPiloto(eVuelos* unVuelo, int id_Piloto);
int eVuelos_get_IdPiloto(eVuelos* unVuelo,int* id_Piloto);

int eVuelos_set_IdAvion(eVuelos* unVuelo, int id_Avion);
int eVuelos_get_IdAvion(eVuelos* unVuelo, int* id_Avion);

int eVuelos_set_Fecha(eVuelos* unVuelo,char* fecha);
int eVuelos_get_Fecha(eVuelos* unVuelo,char* fecha);

int eVuelos_set_Destino(eVuelos* unVuelo,char* destino);
int eVuelos_get_Destino(eVuelos* unVuelo,char* destino);

int eVuelos_set_CantidadPasajeros(eVuelos* unVuelo, int cantidad_Pasajeros);
int eVuelos_get_CantidadPasajeros(eVuelos* unVuelo,int* cantidad_Pasajeros);

int eVuelos_set_HoraDespegue(eVuelos* unVuelo, int hora_Despegue);
int eVuelos_get_HoraDespegue(eVuelos* unVuelo,int* hora_Despegue);

int eVuelos_set_HoraLlegada(eVuelos* unVuelo, int hora_Llegada);
int eVuelos_get_HoraLlegada(eVuelos* unVuelo,int* horaLlegada);
