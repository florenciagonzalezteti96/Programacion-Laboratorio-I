#include <stdio.h>
#include <stdlib.h>

int main()
{
    /**los arrays son datos. agrupaciones fijas de elementos y eso es mucho mas dinamico trabajarlo con vectores.
    --parte abstracta: como agrupar los datos.
    --parte de hardware: entender como existe en la memoria RAM, como se manipula eso y como se puede crear.
    --los corchetes me indican que lo que le estoy dando es una direccion de memoria.
    --tiene indice cero y la cantidad de elementos es cantDeElemn-1
    --para mostrar los datos de un vector, tambien tengo que usar una estructura repetitiva. Tengo que acompañar al vector cone
    el subindice del elemento que quiero mostrar.
    --

    INICIALIZACION POR EXTENSION:
    --harcodeo. meto datos en el programa desde el codigo.
    int vectorDeNumeros[10]={0,0,0,0,0,0,0,0,0,0};
    --inicializa todo en cero.
    int vectorDeNumeros[10]={0};
    int vectorDeNumeros[10]={};
    --inicializo el valor del PRIMER DATO:
    int vectorDeNumeros[10]={1};

    SETEO EL VECTOR:
    --carga secuencial (se usa un for)
    int i;
    for(i=0;i<10;i++){
        vectorDeNumeros[i] = 0;
        --la linea par inicializar una veriable es la misma que para iniciar un vector.
        --sin inicializar el vector, los capacitores que existen en la computadora, le dan un valor binario random para que tengan un valor. SIEMPRE HAY QUE INICIALIZARLO.
        --para modificar el vector en cualquier lugar, uso un for()
    }

    MUESTRO EL VECTOR:
    for(i=0;i<10;i++){
        printf("%d\n",vectorDeNumeros[i]);
    }*/

    int vectorDeNumeros[10]={7,-5,5,-6,-1,-4,11,5,3,-1};
    int i;
    int j = 0;
    int x = 0;
    int min;
    int max;
    int flagMin = 0;
    int flagMax = 0;
    int posicionMin;
    int posicionMax;
    float promedio;

    //otra forma de cargar secuencialmente:

    for(i=0;i<10;i++){
        printf("%d\n",vectorDeNumeros[i]);

    }
    printf("\n\n");
    for(i=0;i<10;i++){
        if(vectorDeNumeros[i]<0){
        printf("%d\n",vectorDeNumeros[i]);
        }
    }
    printf("\n\n");
    for(i=0;i<10;i++){
        if(vectorDeNumeros[i]>0){
            x = x + vectorDeNumeros[i];
            j++;
        }
    }
    promedio = (float) x / j;
    printf("promedio: %.2f\n", promedio);
    printf("\n\n");

    for(i=0;i<10;i++){
    if(vectorDeNumeros[i]<min || flagMin == 0){
       min=vectorDeNumeros[i];
       posicionMin = i;
       flagMin=1;
     }
     if(vectorDeNumeros[i]>max || flagMax == 0){
       max=vectorDeNumeros[i];
       posicionMax = i;
       flagMax=1;
     }
    }
    printf("El max es: %d y su posision es: %d\n", max, posicionMax);
    printf("El min es: %d y su posision es: %d\n", min, posicionMin);
    printf("\n\n");

    return 0;
}
