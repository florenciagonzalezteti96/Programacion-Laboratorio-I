#include <stdio.h>
#include <stdlib.h>
#include "Operation.h"

int add_numbers (float, float);
int subtract_numbers(float, float);
int  divide_numbers (float, float, char* error_message);
int  multiply_numbers (float, float);
int  get_factorial (float);
void validate (int variable_to_validate);
int show_option_menu();
void show_message(char* message);
int get_Int();
int get_Option_Int();
int show_calculator(int first_number, int second_number);

int  add_numbers (float first_number, float second_number){
    return first_number + second_number;
 }

int  subtract_numbers(float first_number, float second_number){
    return first_number - second_number;
}

int  divide_numbers (float first_number, float second_number, char* error_message)
{
    int return_value;
    if(second_number == 0)
    {
       show_message(error_message);//FUNCION MENSAJE DE ERROR
    }
    else

    return return_value;
}

int  multiply_numbers(float first_number, float second_number){
    return first_number * second_number;
}

int  get_factorial(float number)
{
    int retorno = 0;
    if(number == 0 || number == 1){
        retorno = 1;
    }
    else{
        retorno = number * get_factorial(number - 1);
    }
    return retorno;
}

int validate (int variable_to_validate){
    int retorno = 0;
    if(variable_to_validate != 0){
        printf("Ha ocurrido un error en el programa. Por favor, ingrese de nuevo los datos.");
        retorno = 1;
    }
    retorno = 0;
}

int get_Option_Int(){
    int option_entered;
    show_message("Elija una opcion: \n1.Ingresar primer operando.\n2.Ingresar segundo operando.\n3.Informe de las operaciones a realizar.\n4.Informe de los resultados de las operaciones.\n5.Salir de la calculadora.\n");
    scanf("%d", &option_entered);
    return option_entered;
}

int get_Int(){
    int number_entered;
    show_message("Ingrese un numero: ");
    scanf("%d", &number_entered);
    return number_entered;
}

int validate_no_zero();
int validate_no_zero(int number_entered){
    int return_value=0;
    if(number_entered==0)
    {
        return_value=1;
    }
    return return_value;
}

int show_calculator(int first_number, int second_number){
    int operation=get_Int();
    show_message("Ingrese 1 para suma, 2 para resta, 3 para division, 4 para multiplicacion, 5 para factorial.");
    switch(operation){
    case 1:
        add_numbers(first_number, second_number);
        break;
    case 2:
        subtract_numbers(first_number, second_number);
        break;
    case 3:
        divide_numbers(first_number, second_number);
        break;
    case 4:
        multiply_numbers(first_number, second_number);
        break;
    case 5:
        get_factorial(first_number);
        get_factorial(second_number);
        break;
    }
}

int show_option_menu(){

    int option;
    int flag=0;
    int flag_two=0;
    int first_number;
    int second_number;
    int option_continue=='s';

    do{
        option = get_Option_Int();
        switch(option)
        {
            case 1:
                first_number=get_Int();
                flag=1;
                break;
            case 2:
                second_number=get_Int();
                flag_two=1;
                break;
            case 3:
                if(flag=0){
                    show_message("No ha ingresado un primer operando. Seleccione 1.\n");
                }
                else{
                    if(flag_two){
                        show_message("No ha ingresado un segundo operando. Seleccione 2.\n");
                    }
                    else{
                        show_calculator();
                    }
                }
            case 4:
                break;
            default:
                show_message("Dato invalido.\n");
                break;


        }while(option_continue=='s');

        system("pause");
        system("cls");
        return 0;
    }
}

void show_message(char* message){
    printf(message);
}
