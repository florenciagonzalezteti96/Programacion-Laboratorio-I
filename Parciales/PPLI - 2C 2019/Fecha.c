#include "Fecha.h"

void hardcodearFechas(eFecha listadoDeFechas[], int tamFechas)
{
    int i;
    int dia[]= {1,5,6,8,7,9,4,6,8,5,4,2,6,5,9,15,4,8,12,11};
    int mes[]= {1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8};
    int anio[]= {2002,2005,2004,2008,1998,1999,1996,2002,2005,2007,2009,2015,2014,2012,1964,2007,2002,2018,2019,1995};
    for(i=0; i<tamFechas; i++)
    {
        listadoDeFechas[i].dia = dia[i];
        listadoDeFechas[i].mes = mes[i];
        listadoDeFechas[i].anio = anio[i];
    }
}

void mostrarUnaFecha(eFecha unaFecha)
{
    printf("%10d/" , unaFecha.dia);
    printf("%d/" , unaFecha.mes);
    printf("%d\n" , unaFecha.anio);
}

eFecha obtenerFechaPorIndice(eFecha listaDeFechas[], int tamFechas, int indice)
{
    int i;
    eFecha unaFecha;
    for(i=0;i<tamFechas;i++)
    {
        if(i == indice)
        {
            unaFecha = listaDeFechas[i];
            break;
        }
    }
    return unaFecha;
}

/*int existeCodigoFecha(eFecha listadoDeFechas[], int tamFechas, int codigoFecha)
{
    int retorno = -1;
    int i;

    for(i=0;i<tamFechas;i++)
    {
        if(listadoDeFechas[i].codigoPelicula == codigoFecha)
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int buscarIndiceFecha(eFecha listadoDeFechas[], int tamFechas, int idFecha)
{
    int retorno = -1;
    int i;

    for(i=0;i<tamFechas;i++)
    {
        if(idFecha == listadoDeFechas[i].codigoPelicula)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

void mostrarUnaFechaPorId(eFecha listadoDeFechas[], int tamFechas, int indiceFecha)
{
    mostrarUnaFecha(listadoDeFechas[indiceFecha]);
    retorno = 0;

    return retorno;
}*/
