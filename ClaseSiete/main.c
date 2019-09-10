#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[15];
    char apellido[15];
    char apellidoNombre[35];

    //ingreso de nombre, apellido y la variable nombreAPelido guarda el apellido con la primera letra en mayuscula,
    //espacio y nombre con la primera letra en mayuscula. EJ: Gonzalez, Florencia.

    //ingreso de nombre
    printf("Ingrese su nombre: ");
    fflush(stdin);
    fgets(nombre, 15, stdin);
    //ingreso de apellido
    printf("\nIngrese su apellido: ");
    fflush(stdin);
    scanf("%[^\n]", apellido);

    //strcat(apellidoNombre, apellido);
    //strcat(apellidoNombre, ", ");
    //strcat(apellidoNombre, nombre);

    printf("%s", nombre);
    printf("%s", apellido);


    //cambio a mayuscula y a minuscula.

    //concateno en nombre y apellido





    return 0;
}
