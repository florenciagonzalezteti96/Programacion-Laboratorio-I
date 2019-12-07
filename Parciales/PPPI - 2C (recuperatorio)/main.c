#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"

int main()
{
    /**Ejercicio 1*/
    eProducto listaDeProductos[10];

    hardcodearProductos(listaDeProductos, 10);
    ordenarProductos(listaDeProductos, 10);
    mostrarListaProductos(listaDeProductos,10);

    printf("\n");
    printf("\n");
    printf("\n");

    /**Ejercicio 2*/

    int largo = calcularLargoDeCadena("Juana Gonzalez");

    printf("El largo es: %d", largo);

    return 0;
}



