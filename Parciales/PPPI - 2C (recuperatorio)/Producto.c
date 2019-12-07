#include "Producto.h"

int ordenarProductos(eProducto listaProductos[], int tamLista)
{
    int retorno = -1;
    eProducto auxProducto;
    int i;
    int j;

    for(i=0;i<tamLista-1;i++)
    {
        for(j=i+1;j<tamLista;j++)
        {
            if(listaProductos[i].precio > listaProductos[j].precio)
            {
                auxProducto = listaProductos[i];
                listaProductos[i] = listaProductos[j];
                listaProductos[j] = auxProducto;
            }
            else
            {
                if(listaProductos[i].precio == listaProductos[j].precio)
                {
                    if(stricmp(listaProductos[i].nombre,listaProductos[j].nombre)>0)
                    {
                        auxProducto = listaProductos[i];
                        listaProductos[i] = listaProductos[j];
                        listaProductos[j] = auxProducto;
                    }
                }
            }
            retorno = 0;
        }
    }
    return retorno;
}

void hardcodearProductos(eProducto listaProductos[], int tamLista)
{
    int i;
    int id[]={1,2,3,4,5,6,7,8,9,10};
    float precio[]={2000,5000,3000,4000,2000,1000,9000,4500,1200,2000};
    char nombre[][50]={"Harina","Huevos","Harina","Anana","Mesa","Pera","Leche","Fideos","Alfombra","Manzana"};
    for(i=0;i<tamLista;i++)
    {
        listaProductos[i].id = id[i];
        listaProductos[i].precio = precio[i];
        strcpy(listaProductos[i].nombre, nombre[i]);

    }

}

void mostrarListaProductos(eProducto listaProductos[], int tamLista)
{
    int i;
    for(i=0;i<tamLista;i++)
    {
        mostrarUnProducto(listaProductos[i]);
    }
}

void mostrarUnProducto(eProducto unProducto)
{
    printf("%4d", unProducto.id);
    printf("%10.2f", unProducto.precio);
    printf("%10s\n", unProducto.nombre);

}

int calcularLargoDeCadena(char cadena[])
{
    //char i[20];
    int j = 0;

    //strcpy(i, cadena);

    while(cadena[j] != '\0')
    {
        j++;
    }

    return j;
}
