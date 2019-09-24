#include "localidad.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void hardcodearLocalidades(eLocalidad listaDeLocalidades[], int cantidadDeLocalidades){
    int i;
    char auxNombre[][30] = {"Avellaneda","Lanus","Wilde"};
    int auxCodigoPostal[] = {1870,1758,1852};
    int idLocalidad[] = {1,2,3};
    for(i=0;i<cantidadDeLocalidades;i++){
        listaDeLocalidades[i].codigoPostal = auxCodigoPostal[i];
        listaDeLocalidades[i].idLocalidad = idLocalidad[i];
        strcpy(listaDeLocalidades[i].nombreLocalidad, auxNombre[i]);
    }
}
int buscarLocalidadPorId(eLocalidad listaDeLocalidades[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++){
        if(listaDeLocalidades[i].idLocalidad == id){
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarLocalidad(eLocalidad listaDeLocalidades[], int cantidadDeLocalidades){
    int i;
    printf("Nombre de la localidad:\t\tID de la localidad:\t\t")
    for(i=0;i<cantidadDeLocalidades;i++){
        printf("%s", listaDeLocalidades[i].nombreLocalidad);
        printf("10%d", listaDeLocalidades[i].idLocalidad);
    }



}
