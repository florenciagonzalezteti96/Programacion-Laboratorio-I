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
