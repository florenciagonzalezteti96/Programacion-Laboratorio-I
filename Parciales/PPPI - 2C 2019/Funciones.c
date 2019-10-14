#include "Funciones.h"
/**2. Crear una funcion que reciba una cadena. Calcular cuantas vocales tiene esa cadena y que vocal aparece mas veces.*/

char verificarVocales(char cadena[]){
    int tam;//tamaño de la cadena ingresada
    eVocales list[5]; //array de estructuras eVocales, con cada vocal y su contador
    char vocalConMasIncidencias;
    int mayorIncidencia;

    init_eVocales(list, 5);//cargo el array de estructuras con las vocales y su contador
    tam = strlen(cadena);//calculo el tamaño de la cadena ingresada
    cargarContadoresDeVocales(list, 5, cadena, tam);
    mayorIncidencia = getMaximoDeVocales(list, 5);
    vocalConMasIncidencias = dameVocalQueApareceMas(list, 5, mayorIncidencia);


    return vocalConMasIncidencias;
}
char dameVocalQueApareceMas(eVocales list[], int tam, int mayorContador){
    char retorno;
    int maximo;//variable que guarda la mayor incidencia de la lista
    //ya tengo los contadores y las vocales ingresadas, ahora busco el maximo:
    maximo = mayorContador;
    int i;
    for(i=0;i<5;i++){//comienza a recorrer la cadena ingresada
        if(maximo == list[i].contadorVocales){//compara si las letras son iguales
            retorno = *(list[i]).vocales;
        }
    }
    return retorno;
}
void cargarContadoresDeVocales(eVocales* list, int tamLista, char cadena[], int tamCadena){
    int i;  //declaro variables de control para la comparacion
    int j;
    for(i=0;i<tamCadena;i++){//comienza a recorrer la cadena ingresada
        for(j=0;j<tamLista;j++){//accede a la vocal en ese lugar de la lista
            if(cadena[i] == *(list[j]).vocales){//compara si las letras son iguales
                list[j].contadorVocales = list[j].contadorVocales + 1 ;//suma el contador de esa vocal
                printf("cadena : %c \t\t vocal: %c\n", cadena[i], *(list[j]).vocales);//voy controlando que los valores ingresados sean corrector
            }
        }
    }

}
int getMaximoDeVocales(eVocales list[], int tam){
    int retorno = 0; //variable para guardar el maximo y devolverlo
    int flag = 0;
    int i;
    for(i=0;i<tam;i++){
        if(flag == 0 || list[i].contadorVocales>retorno){
            retorno = list[i].contadorVocales;
            flag = -1;
        }
    }
    return retorno;
}
void init_eVocales(eVocales list[], int tamList){
    char vocales[5]={'a','e','i','o','u'};
    int i;
    for(i=0;i<tamList;i++){
        *(list[i]).vocales = vocales[i];
        list[i].contadorVocales = 0;
    }
}
/**3. Se tiene la estructura Notebook (id, procesador, marca, precio). Ordenar el array por procesador. Si el procesador es igual, ordenar por marca.
Hardcodear y mostrar en el menu.*/
void init_eNotebook(eNotebook list[], int tamList){
    int id[3]={1,2,3};
    char procesadores[3][10]={"n600","n600","x300"};
    char marca[3][10]={"azul","mormo","pepe"};
    float precios[3]={1500.25,2000.652,1350.124};
    int i;
    for(i=0;i<tamList;i++){
        list[i].id = id[i];
        strcpy(*(list[i]).procesador,procesadores[i]);
        strcpy(*(list[i]).marca,marca[i]);
        list[i].precio = precios[i];
    }
}
void ordenarListaNotebooks(eNotebook list[], int tamList){
    int i;
    int j;
    eNotebook auxNotebook;
    for(i=0;i<tamList-1;i++){
        for(j=i+1;j<tamList;j++){
            if(stricmp(*(list[i]).procesador,*(list[j]).procesador)>0){
                strcpy(*auxNotebook.procesador,*(list[i]).procesador);
                strcpy(*(list[i]).procesador, *(list[j]).procesador);
                strcpy(*(list[j]).procesador,*auxNotebook.procesador);
            }else if(stricmp(*(list[i]).procesador,*(list[j]).procesador)==0){
                if(stricmp(*(list[i]).marca,*(list[j]).marca)>0){
                    strcpy(*auxNotebook.marca,*(list[i]).marca);
                    strcpy(*(list[i]).marca, *(list[j]).marca);
                    strcpy(*(list[j]).marca,*auxNotebook.marca);
                }
            }
        }
    }
}
