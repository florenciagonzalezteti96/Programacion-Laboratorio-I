#include <stdio.h>
#include <stdlib.h>
#include "Operation.h"

int add_numbers (float, float);
int subtract_numbers(float, float);
int  divide_numbers (float, float, char[] error_message);
int  multiply_numbers (float, float);
int  get_factorial (float);
void validate (int variable_to_validate);

int  add_numbers (float first_number, float second_number)
 {
     int retorno = 0;
     float addition_total;

     addition_total = first_number + second_number;
     printf("El resultado de %.2f + %.2f es: %.2f", first_number, second_number, addition_total);

     return retorno;
 }

int  subtract_numbers(float first_number, float second_number)
{
    int retorno = 0;
    float subtraction_total;

    subtraction_total = first_number - second_number;
    printf("El resultado de %.2f - %.2f es: %.2f", first_number, second_number, subtraction_total);

    return retorno;
}

int  divide_numbers (float first_number, float second_number, char[] error_message)
{
    int retorno = 0;
    float division_total;

    if(second_number!=0)
    {
       division_total = (float) first_number / second_number;
       printf("El resultado de %.2f / %.2f es: %.2f", first_number, second_number, division_total);
    }
    else
    {
       printf(error_message);
       retorno = 1;
    }

    return retorno;
}

int  multiply_numbers(float first_number, float second_number)
{
    int retorno = 0
    float multiplication_total;

    multiplication_total = first_number * second_number;
    printf("El resultado de %.2f * %.2f es: %.2f", first_number, second_number, multiplication_total);

    return retorno;
}

int  getFactorial (float number)
{
    int retorno = 0;
    int factorial;

    if(number == 0 || number == 1)
    {
        factorial = 1;
        printf("El factorial de %.2f! es: %.2f", number, factorial);
    }
    else
    {
        factorial = number * get_factorial(number - 1);
        printf("El factorial de %.2f! es: %.2f", number, factorial);
    }

    return retorno;
}

int validate (int variable_to_validate)
{
    int retorno = 0;

    if(variable_to_validate != 0)
    {
        printf("Ha ocurrido un error en el programa. Por favor, ingrese de nuevo los datos.");
        retorno = 1;
    }

    retorno = 0;
}




