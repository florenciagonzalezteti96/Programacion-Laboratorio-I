#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Operaciones.h"

void showOptionMenu(void);
int getInt(char* message);
float getFloat(char* message);
int isInt (float number);


void showOptionMenu()
{
    int option;
    int optionContinue = 's';
    float firstNumber = 0;
    float secondNumber = 0;
    int flagOne = 0;
    int flagTwo = 0;
    int factorialOne = 0;
    int factorialTwo = 0;
    float addition;
    float subtraction;
    float division;
    float multiplication;
    float factorialFirstNumber;
    float factorialSecondNumber;


    do
    {
        option = getInt("Elija una opcion: \n1.Ingresar primer operando.\n2.Ingresar segundo operando.\n3.Calcular resultados de operaciones.\n4.Informe de resultados.\n5.Salir.\n");
        switch(option)
        {
        case 1:
            firstNumber = getFloat("Ingrese un primer operando:");
            printf("El primer operando es: %.2f\n\n", firstNumber);
            flagOne = 1;
            break;
        case 2:
            secondNumber = getFloat("Ingrese un segundo operando:");
            printf("El segundo operando es: %.2f\n\n", secondNumber);
            flagTwo = 1;
            break;
        case 3:
            if(flagOne == 0)
            {
                printf("Usted no ha ingresado un primer operando. Seleccione 1 para ingresarlo.\n");
            }
            else
            {
                if(flagTwo == 0)
                {
                    printf("Usted no ha ingresado un segundo operando. Seleccione 2 para ingresarlo.\n");
                }
                else
                {
                    printf("Las operaciones a realizar son:\n");
                    printf("Suma: %.2f + %.2f\n", firstNumber, secondNumber);
                    printf("Resta: %.2f - %.2f\n", firstNumber, secondNumber);
                    printf("Division: %.2f / %.2f\n", firstNumber, secondNumber);
                    printf("Multiplicacion: %.2f * %.2f\n", firstNumber, secondNumber);
                    printf("Factorizacion del primer operando: %.2f!\n", firstNumber);
                    printf("Factorizacion del segundo operando: %.2f!\n", secondNumber);
                    printf("\n\n");
                    addition = addNumbers(firstNumber,secondNumber);
                    subtraction = subtractNumbers(firstNumber,secondNumber);
                    division = divideNumbers(firstNumber,secondNumber, "Error. La division por cero no se puede realizar. Ingrese un nuevo segundo operando.\n");
                    multiplication = multiplyNumbers(firstNumber,secondNumber);
                    if (firstNumber>=0 && isInt(firstNumber)==1)
                    {
                        factorialFirstNumber = getFactorial(firstNumber);
                        factorialOne = 1;
                    }
                    else
                    {
                        printf("Error. No se pudo realizar el factoreo del primer operando. Seleccione 1 para ingresar uno nuevo (entero positivo).");
                        factorialTwo = 1;
                    }

                    if (secondNumber>=0 && isInt (secondNumber) == 1)
                    {
                        factorialSecondNumber = getFactorial(secondNumber);
                    }else{

                     printf("Error. No se pudo realizar el factoreo del primer operando. Seleccione 1 para ingresar uno nuevo (entero positivo).");
}


                }//operaciones a realizar
            }//else validacion segundo operando
            break;
        case 4:
            printf("Informe de los resultados:\n");
            printf("El resultado de %.2f + %.2f es: %.2f\n", firstNumber, secondNumber, addition);
            printf("El resultado de %.2f - %.2f es: %.2f\n", firstNumber, secondNumber, subtraction);
            printf("El resultado de %.2f * %.2f es: %.2f\n", firstNumber, secondNumber, multiplication);
            if(division!=-1){
              printf("El resultado de %.2f / %.2f es: %.2f\n", firstNumber, secondNumber, division);
            }else{
               printf("La division por cero no es posible. Si quiere realizar una division, ingrese un nuevo segundo operando (no cero.)\n");
            }
            if(factorialOne!=0 && factorialTwo!=0){
            printf("El factorial de %.2f es: %.2f y el factorial de %.2f es: %.2f\n", firstNumber, secondNumber, factorialFirstNumber, factorialSecondNumber);

            }else{
            printf("No se ha podido realizar el factoreo.");
            }
            break;
        case 5:
            printf("Usted ha salido de la calculadora.\n");
            printf("\n\n");
            optionContinue ='n';
            break;
        default:
            printf("Dato invalido.\n");
            break;
        }//switch
    }while(optionContinue == 's');//do_while
}//show_menu


float getFloat(char* message)
{
    float number;
    printf(message);
    fflush(stdin);
    scanf("%f", &number);

    return number;
}

int getInt(char* message)
{
    int number;

    printf(message);
    fflush(stdin);
    scanf("%d", &number);

    return number;
}

int isInt (float number)
{
    int integral = number;
    int isInt = 0;

    if (number - integral == 0)
     {
         isInt = 1;
     }
     return isInt;
}
