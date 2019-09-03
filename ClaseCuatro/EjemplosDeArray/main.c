#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define T 10


int main()
{
    system("color F0");

    int vectorDeNumeros[T];

    show_option_menu(vectorDeNumeros, T);

    return 0;
}


