#include <stdio.h>
#include <stdlib.h>

/** \brief Calcula el factorial de un numero
 *
 * \param int El numero a factorizar.
 * \return int El factorial del numero que recibe.
 *
 */
unsigned int factorizar (int);

int main()
{
    int numero;
    int numero_factorial = 1;

    printf("Ingresar un numero: \n");
    fflush(stdin);
    scanf("%d", &numero);
    //con while
    while(numero != 0){
        numero_factorial = numero_factorial * numero; /** ESTA ES LA MEJOR FORMA DE HACERLO. */
        numero = numero - 1;
    }
    printf("El factorial es: %d", numero_factorial);
    //con for
    int i;
    int factorial = 1;
    for(i = 1; i<= numero, i--){
        factorial = factorial * i;
    }
    printf("Factorial de %d es: %d\n", numero, factorial)
    return 0;
}

unsigned int factorizar (int numero){
    unsigned int resultado;

    if(numero == 0){
        resultado = 1;
    }
    else{
        resultado = numero * factorizar(numero - 1);
    }
    return resultado;
}


