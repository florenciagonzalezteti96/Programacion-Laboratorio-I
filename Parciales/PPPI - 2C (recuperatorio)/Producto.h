#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct
{
    int id;
    char nombre[50];
    float precio;

}eProducto;

int ordenarProductos(eProducto listaProductos[], int tamLista);
void hardcodearProductos(eProducto listaProductos[], int tamLista);
void mostrarListaProductos(eProducto listaProductos[], int tamLista);
void mostrarUnProducto(eProducto unProducto);

int calcularLargoDeCadena(char cadena[]);


