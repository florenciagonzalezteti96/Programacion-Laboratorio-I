#include <stdio.h>
#include <stdlib.h>


int getInt_Validate(int* number, char* message, char* errorMessage, int lowLimit, int highLimit);

int main()
{
    int edad;

    if(getInt_Validate(&edad, "Ingrese una edad\n", "Error. Rango entre 10-99.Vuelva a ingresar.\n", 10, 99) == -1){
        printf("ERROR.");
    }
    else{
        printf("Esta es su edad: %d\n", edad);
    }

    return 0;
}

int getInt_Validate(int* number, char* message, char* errorMessage, int lowLimit, int highLimit)
{
    int return_value = 0;
    int contadorIntentos;



    do{
        printf(message);
        fflush(stdin);
        scanf("%d", number);

        if(*number<lowLimit){
            printf(errorMessage);
        }else{
            if(*number>highLimit){
            printf(errorMessage);
            }

    }while(contadorIntentos<5){

    }
    return return_value;
}


