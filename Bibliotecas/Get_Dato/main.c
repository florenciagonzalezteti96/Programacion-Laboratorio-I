#include <stdio.h>
#include <stdlib.h>
#include "Get_Dato.h"
int main()
{
    int num;
    if(getIntConRango(&num,"Ingrese un numero:","Se ha excedido de rango",10,90)==1){
        printf("Este es el nuevo numero: %d", num);
    }
    return 0;
}
