#include "Pais.h"

void hardcodearPaises(ePais listadoDePaises[], int tamPaises)
{
    int i;
    int id[]= {1,2,3,4,5};
    char descripcionPais[][21]={"Argentina","USA","Sudafrica","Inglaterra","Israel"};
    for(i=0; i<tamPaises; i++)
    {
        listadoDePaises[i].id = id[i];
        strcpy(listadoDePaises[i].descripcionPais, descripcionPais[i]);
    }
}
void mostrarListaPaises(ePais listaDePaises[], int tamPais)
{
    int i;
    for(i=0;i<tamPais;i++)
    {
        mostrarUnPais(listaDePaises[i]);
    }
}
void mostrarUnPais(ePais unPais)
{
    printf("%4d", unPais.id);
    printf("%10s\n" , unPais.descripcionPais);
}

ePais obtenerUnPaisPorId(ePais listaDePaises[], int tamPaises, int idNacionalidad)
{
    ePais unPais;
    int i;

    for(i=0;i<tamPaises;i++)
    {
        if(listaDePaises[i].id == idNacionalidad)
        {
            unPais = listaDePaises[i];
            break;
        }
    }
    return unPais;
}
