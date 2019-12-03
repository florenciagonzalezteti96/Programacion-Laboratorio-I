#include "Genero.h"

int hardcodearGeneros(eGenero listadoDeGeneros[], int tamGeneros)
{
    int retorno = -1;
    if(tamGeneros>0)
    {
        int id[]= {1,2,3,4};
        char descripcion[][25]= {"Accion","Terror","Romance","Suspenso"};
        int i;
        for(i=0; i<tamGeneros; i++)
        {
            listadoDeGeneros[i].id = id[i];
            strcpy(listadoDeGeneros[i].descripcion, descripcion[i]);
        }
        retorno = 0;
    }
    return retorno;
}
int validarIdGenero(eGenero listadoDeGeneros[], int tamGeneros, int idGenero)
{
    int i;
    int retorno = -1;
    for(i=0; i<tamGeneros; i++)
    {
        if(idGenero == listadoDeGeneros[i].id)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int buscarIndiceGenero(eGenero listadoDeGeneros[], int tamGeneros, int idGenero)
{
    int i;
    int retorno = -1;
    for(i=0; i<tamGeneros; i++)
    {
        if(idGenero == listadoDeGeneros[i].id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int obtenerUnGenero(eGenero listadoDeGeneros[], int tamGeneros)
{
    int idGenero;
    mostrarListaGeneros(listadoDeGeneros, tamGeneros);
    idGenero = getInt("Ingrese el codigo del genero de la pelicula: \n");
    while((validarIdGenero(listadoDeGeneros, tamGeneros, idGenero)== -1))
    {
        idGenero = getInt("El codigo de genero ingresado es invalido. Reingrese: ");
        printf("\n");
    }
    return idGenero;
}
eGenero obtenerUnGeneroPorId(eGenero listadoDeGeneros[], int tamGeneros, int idGenero)
{
    int i;
    int existeGenero;
    eGenero auxGenero;

    existeGenero = buscarIndiceGenero(listadoDeGeneros, tamGeneros, idGenero);

    if(tamGeneros != 0 && existeGenero != -1)
    {
        for(i=0; i<tamGeneros; i++)
        {
            if(idGenero == listadoDeGeneros[i].id)
            {
                auxGenero = listadoDeGeneros[i];
                break;
            }
        }
    }

    return auxGenero;
}
int mostrarGeneroPorId(eGenero listadoDeGeneros[], int tamGeneros, int idGenero)
{
    int retorno = -1;
    int indiceGenero = buscarIndiceGenero(listadoDeGeneros, tamGeneros, idGenero);
    if(indiceGenero != -1)
    {
        printf("%12s", listadoDeGeneros[indiceGenero].descripcion);
        retorno = 0;
    }
    return retorno;
}
void mostrarListaGeneros(eGenero listadoDeGeneros[], int tamGeneros)
{
    int i;
    printf("ID:\t\tNombre del genero:\n");
    for(i=0; i<tamGeneros; i++)
    {
        printf("%3d", listadoDeGeneros[i].id);
        printf("%31s\n", listadoDeGeneros[i].descripcion);
    }
}
