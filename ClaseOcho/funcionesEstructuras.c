#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct{
    char nombre[50];
    int nota;
    int legajo;
    int isEmpty;//0 para ocupado, 1 para libre -> bandera
}eAlumno;

void mostrar_menu(eAlumno listadoDeAlumnos[], int tam, int valorInicial){
    int option;
    char option_continue='s';
    do{
        printf("\nIngrese 1 para mostrar los alumnos.\nIngrese 2 para cargar alumnos.\nIngrese 3 para buscar nombre.\nIngrese 4 para borrar a un alumno.\nIngrese 5 para salir.\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            inicializarAlumnos(listadoDeAlumnos, tam,valorInicial);
            listarAlumnos(listadoDeAlumnos, tam, valorInicial);
            break;
        case 2:
            hardcodearEstructura(listadoDeAlumnos, tam);
            break;
        case 3:
            //buscar por nombre
            break;
        case 4:
            //borrar por legajo
            break;
        default:
            option_continue='n';
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}
void hardcodearEstructura(eAlumno listaDeAlumnos[], int cantidadDeAlumnos){
    int i;
    int auxLegajos[] = {1,3,5,9,88};
    int auxNotas[] = {10,2,9,4,6};
    char nombresAux[][50] = {"Juan","Pedro","Maria","Julieta","Pepe"};

    for(i=0;i<cantidadDeAlumnos;i++){
        listaDeAlumnos[i].legajo = auxLegajos[i];
        listaDeAlumnos[i].nota = auxNotas[i];
        strcpy(listaDeAlumnos[i].nombre, nombresAux[i]);
        listaDeAlumnos[i].isEmpty = 0;
    }

}
void listarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, int valorInicial){
    int i;
    int hayAlumnos = 0;
    printf("NOMBRE:\t\tLEGAJO:\t\tNOTA:\t\t\n");
    for(i=0;i<cantidadDeAlumnos;i++){
        if(listadoDeAlumnos[i].isEmpty != valorInicial){
                hayAlumnos = 1;
                mostrarUnAlumno(listadoDeAlumnos[i]);
        }
    }
    if(hayAlumnos == 0){
        printf("No hay alumnos\n");
    }
}
void mostrarUnAlumno(eAlumno listadoDeAlumnos){
    printf("\n");
    printf("%s\t\t",listadoDeAlumnos.nombre);
    printf("%d\t\t", listadoDeAlumnos.legajo);
    printf("%d\t\t", listadoDeAlumnos.nota);
}
void inicializarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, int valorInicial){
    int i;
    for(i=0;i<cantidadDeAlumnos;i++){
        listadoDeAlumnos[i].isEmpty = valorInicial;
    }
}
int dameElPrimerLugarLibre(eAlumno listaDeAlumnos[], int cantidadDeAlumnos, int valorInicial){
    int i;
    int retorno = -1;
    for(i=0;i<cantidadDeAlumnos;i++){
        if(listaDeAlumnos[i].isEmpty == valorInicial){
            retorno = i;
            break;
        }
    }
    return retorno;
}
void borrarLegajo(eAlumno listaDeAlumnos[], int cantidadDeAlumnos, int legajo, int valorInicial){
    int i;
    int existeLegajo = 1;
    for(i=0;i<cantidadDeAlumnos;i++){
        if(listaDeAlumnos[].legajo == legajo){
            listaDeAlumnos[i].isEmpty = valorInicial;
            existeLegajo = 0;
        }
    }
    if(existeLegajo == 1){
        printf("El legajo no existe!");
    }

}

