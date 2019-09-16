#include <stdio.h>
#include <stdlib.h>



typedef struct{
    char nombre[50];
    int nota;
    int legajo;
    int isEmpty;//0 para no esta vacio, 1 para si esta vacio -> bandera
}eAlumno;

void inicializarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, int valorInicial);
void listarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, int valorInicial);
void mostrarUnAlumno(eAlumno listadoDeAlumnos);

int main()
{
    eAlumno listadoDeAlumnos[5]; //no significa que hay 5 alumnos, sino que hay cinco lugares.
    eAlumno nuevoAlumno;

    inicializarAlumnos(listadoDeAlumnos, 5, 1);

    nuevoAlumno.isEmpty = 0;
    nuevoAlumno.nota = 58;
    nuevoAlumno.legajo = 1001;
    scanf("%s", nuevoAlumno.nombre);
    listadoDeAlumnos[2] = nuevoAlumno;

    listarAlumnos(listadoDeAlumnos, 5, 1);

    return 0;
}

void inicializarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, int valorInicial){
    int i;
    for(i=0;i<cantidadDeAlumnos;i++){
        listadoDeAlumnos[i].isEmpty = valorInicial;
    }
}
void mostrarUnAlumno(eAlumno listadoDeAlumnos){
    printf("Este son los datos del alumno: \n");
    printf("Nota: %d\nLegajo: %d\nNombre: %s\n", listadoDeAlumnos.nota, listadoDeAlumnos.legajo, listadoDeAlumnos.nombre);
}
void listarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, int valorInicial){
    int i;
    int hayAlumnos = 0;
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
