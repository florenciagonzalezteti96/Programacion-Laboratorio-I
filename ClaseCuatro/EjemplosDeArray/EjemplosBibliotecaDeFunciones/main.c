#include <stdio.h>
#include <stdlib.h>

void show_message(char message[]);
int getInt_Validate(int* number, char* message, char* errorMessage, int lowLimit, int highLimit);

int main()
{
    int edad;

    if(getInt_Validate(&edad, "Ingrese una edad\n", "Error. Rango entre 10-99.Vuelva a ingresar.\n", 10, 99) == -1){
        printf("ERROR.");
    }else{
        printf("Esta es su edad: %d\n", edad);
    }

    return 0;
}

void show_message(char message[]){
    printf(message);
}

int getInt_Validate(int* number, char* message, char* errorMessage, int lowLimit, int highLimit){
    int return_value;
    show_message(message);
    scanf()
    if(*number<lowLimit || *number>highLimit){
        show_message(errorMessage);
        return_value = -1;
    }else{
        scanf("%d", number);
        return_value = 0;
    }

    return return_value;
}


