/*
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de optiones:

1. Ingresar 1er operando (A=first_number)//crear funcion para ingresar operandos

2. Ingresar 2do operando (B=y)//crear funcion para ingresar operandos


3. Calcular todas las operaciones//se puede tomar como que hay que crear un menu aparte para las optiones a elegir.
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)

4. Informar resultados //print f
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible divide_numbers por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�

5. Salir

� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �first_number� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "Operation.h"

int main()
{
    system("color F0");
    int option;//Menu principal. Le muestra al usuario todas las optiones para ingresar o recibir datos.
    int flag = 0;//Bandera para validar si el usuario ingreso un primer operando o no.
    int flag_two = 0;//Bandera para validar si el usuario ingreso un segundo operando o no.
    int first_number;//primer numero ingresado.
    int second_number;//segundo numero ingresado.
    float addition;//variable que guarda el resultado de la funcion llamada add_numbersOperandos.
    float subtraction;//variable que guarda el resultado de la funcion llamada subtract_numbersOperandos.
    float division;//variable que guarda el resultado de la funcion llamada divide_numbersOperandos.
    float multiplication;//variable que guarda el resultado de la funcion llamada multiply_numbersOperandos.
    float factorial_first_number;//variable que guarda el resultado de la funcion llamada calcularFactorialDeOperando.
    float factorial_second_number;//variable que guarda el resultado de la funcion llamada calcularFactorialDeOperando.
    char option_continue = 's';//cierre de la funcion do while.

    do
    {
        printf("Elija una opcion: \n1.Ingresar primer operando.\n2.Ingresar segundo operando.\n3.Informe de las operaciones a realizar.\n4.Informe de los resultados de las operaciones.\n5.Salir de la calculadora.\n");//se puede crear una funcion que cree el menu, o un printf para cada option o que quede asi
        fflush(stdin);
        scanf("%d", &option);
        switch(option)//menu de opciones
        {
        case 1:
            //ingreso del primer operando
            printf("Ingrese un primer operando:\n");
            fflush(stdin);
            scanf("%d", &first_number);
            printf("El primer operando ingresado es %d\n", first_number);
            flag = 1;
            break;

        case 2:
            //ingreso del segundo operando
            printf("Ingrese un segundo operando:\n");
            fflush(stdin);
            scanf("%d", &second_number);
            //valido que no ocurra una division por cero.
            if(second_number != 0)
            {
                printf("El segundo operando ingresado es %d\n", second_number);
                flag_two = 1;
            }
            else
            {
                printf("La division por cero no es posible. Seleccione 2 para ingresar un segundo operando.\n");
            }
            break;

        case 3:
            //validacion del ingreso de los operandos
            if(flag == 0)
            {
                printf("Usted no ha ingresado un primer operando. Seleccione 1 para ingresarlo.\n");
            }
            else
            {
                if(flag_two == 0)
                {
                    printf("Usted no ha ingresado un segundo operando o debe ingresar uno nuevo. Seleccione 2 para ingresarlo.\n");
                }
                else
                {
                    //muestro las operaciones a realizar y calculo los resultados.
                    printf("Las operaciones a realizar son:\n");
                    printf("Suma: %d + %d\n", first_number, second_number);
                    printf("Resta: %d - %d\n", first_number, second_number);
                    printf("Division: %d / %d\n", first_number, second_number);
                    printf("Multiplicacion: %d * %d\n", first_number, second_number);
                    printf("El factorial del primer operando sera: %d!\n", first_number);
                    printf("El factorial del segundo operando sera: %d!\n", second_number);

                    addition = add_numbers(first_number,second_number);
                    subtraction = subtract_numbers(first_number,second_number);
                    division = divide_numbers(first_number,second_number);
                    multiplication = multiply_numbers(first_number,second_number);
                    factorial_first_number = get_factorial(first_number);
                    factorial_second_number = get_factorial(second_number);
                }
            }
            break;

        case 4:
            //informo los resultados finales.
            printf("Informe de los resultados:\nLa suma es %.2f\nLa resta es %.2f\nLa division es %.2f\nLa multiplicacion es %.2f\nEl factorial del primer operando es %.2f\nEl factorial del segundo operando es %.2f\n", addition, subtraction, division, multiplication, factorial_first_number, factorial_second_number);
            break;

        case 5:
            //salida del programa.
            printf("Ha salido de la calculadora.\n");
            option_continue = 'n';
            break;

        default:
            //ingreso de una option que no existe en el menu.
            printf("No ingreso una opcion valida\n");
            break;
        }
    }
    while(option_continue=='s');

    system("pause");
    system("cls");

    return 0;
}



