#include <stdio.h>
#include <stdlib.h>
#include "Operation.h"
//A = first_number
//B = Y
float add_numbers (float, float);
float subtract_numbers(float, float);
float divide_numbers (float, float);
float multiply_numbers (float, float);
float get_factorial (float);

float add_numbers (float first_number, float second_number)
 {
     float addition_total;

     addition_total = first_number + second_number;

     return addition_total;
 }

float subtract_numbers(float first_number, float second_number)
{
    float subtraction_total;

    subtraction_total = first_number - second_number;

    return subtraction_total;
}

float divide_numbers (float first_number, float second_number)
{
    float division_total;

    division_total = (float) first_number / second_number;

    return division_total;
}

float multiply_numbers(float first_number, float second_number)
{
    float multiplication_total;

    multiplication_total = first_number * second_number;

    return multiplication_total;
}

float get_factorial (float number)
{
    int factorial;

    if(number == 0 || number == 1)
    {
        factorial = 1;
    }
    else
    {
        factorial = number * get_factorial(number - 1);
    }

    return factorial;
}




