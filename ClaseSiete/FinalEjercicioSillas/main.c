#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "input.h"
#include "string.h"
#include "ctype.h"
void hardcodearVectorEdades(int cadena[], int tam);
int main()
{
    //int legajos[5];
    int edades[5];

    hardcodearVectorEdades(edades, 5);
    //scanf("%[^\n]", palabra);

    return 0;
    return 0;
}

void hardcodearVectorEdades(int cadena[], int tam){
    int cadenaAux[]={200,20,"popoplpi",98,10};
    int i;
    for(i=0; i<tam; i++){
        cadena[i] = cadenaAux[i];
    }
}
