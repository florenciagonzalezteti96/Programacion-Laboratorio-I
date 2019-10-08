#include "localidad.h"
int getLocalidad(eLocalidad listadoDeLocalidades[], int tamLocalidad){
    int retorno;
    int idIngresado;
    mostrarLocalidades(listadoDeLocalidades, tamLocalidad);
    printf("Ingrese el ID de la localidad del alumno: ");
    scanf("%d", &idIngresado);//cambiar por GETVALIDINT
    while((existeLocalidad(listadoDeLocalidades, tamLocalidad, idIngresado))== -1){
        printf("Error. El ID de la localidad ingresado no corresponde a ninguna localidad. Ingrese de nuevo: ");
        mostrarLocalidades(listadoDeLocalidades, tamLocalidad);
        scanf("%d", &idIngresado); //cambiar por getvalidInt
    }
    retorno = idIngresado;
    return retorno;
}
int existeLocalidad(eLocalidad listadoDeLocalidades[], int tamLocalidad, int idLocalidad){
    int retorno = -1;
    int i;
    for(i=0;i<tamLocalidad;i++){
        if(idLocalidad == listadoDeLocalidades[i].id){
            retorno = 0;
            break;
        }
    }
    return retorno;
}
void mostrarLocalidades(eLocalidad listadoDeLocalidades[], int tamLocalidad){
    int i;
    printf("Estas son las localidades:\n");
    printf("ID:\t\tNOMBRE:\t\tCODIGO POSTAL:\t\t\n");
    for(i=0;i<tamLocalidad;i++){
        printf("%d\t\t", listadoDeLocalidades[i].id);
        printf("%s\t\t", listadoDeLocalidades[i].nombreLocalidad);
        printf("%d\n", listadoDeLocalidades[i].codigoPostal);
    }
}
void mostrarLocalidadPorId(eLocalidad listadoDeLocalidades[], int tamLocalidad, int idLocalidad){
    int i;
    for(i=0;i<tamLocalidad;i++){
        if(idLocalidad == listadoDeLocalidades[i].id){
            printf("La localidad es %s.\n", listadoDeLocalidades[i].nombreLocalidad);
            break;
        }
    }
}
int buscarLocalidadPorId(eLocalidad listadoDeLocalidades[], int tamLocalidad, int idLocalidad){
    int retorno = -1;
    int i;
    for(i=0;i<tamLocalidad;i++){
        if(idLocalidad == listadoDeLocalidades[i].id){
            retorno = i;
            break;
        }
    }
    return retorno;
}
void hardcodearLocalidades(eLocalidad listadoDeLocalidades[],int tamLocalidad){
    int i;
    int id[]= {101,102,103,105,104};
    char localidad[][32]= {"Avellaneda","Wilde","Lomas de Zamora","Lanus","Quilmes"};
    int codigoPostal[]= {1870,1872,1700,1960,1858};
    for(i=0; i<tamLocalidad; i++){
        listadoDeLocalidades[i].id=id[i];
        strcpy(listadoDeLocalidades[i].nombreLocalidad,localidad[i]);
        listadoDeLocalidades[i].codigoPostal=codigoPostal[i];
    }
}
void hardcodearContador(eContador listaDeContadores[],int tamContador, eLocalidad listaDeLocalidades[])
{
    int i;
    for(i=0; i<tamContador; i++){
        listaDeContadores[i].contadorAlumnos = 0;
        listaDeContadores[i].idLocalidad = listaDeLocalidades[i].id;
    }
}
