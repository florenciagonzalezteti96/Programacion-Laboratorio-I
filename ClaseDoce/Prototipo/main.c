#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "Local.h"
#include "alumno.h"
#include "Inscripcion.h"
#include "Materia.h"
//settings-Enviroment-GeneralSetings-TerminaltoLunchConsolePrograms
//settings-Editor-GeneralSettings-EditorSettings-Fonts-Manjari
#define LL 3
//lengh localidad
#define LA 11
//lengh Alumnos


int main()
{
    eLocalidad listaDelocalidades[LL];
    eAlumno listaDeAlumnos[LA];
    eContador listaDeContador[LL];
    eMateria listadoDeMaterias[4];
    int id_beta=1000;
    int opcion;
    int respuesta;

    inicializar_Alumnos(listaDeAlumnos,LA);

    hardcode_Localidad(listaDelocalidades,LL);
    hardCodearAlumnos(listaDeAlumnos,9,&id_beta);
    hardcode_Contador(listaDeContador,LL,listaDelocalidades);
    hardCodearMaterias(listadoDeMaterias, 4);

    mostrarListadoSoloAlumnos(listaDeAlumnos, LA);
    do
    {
        getValidInt("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Eliminar\n5.Modificar\n7.Salir\nElija una opcion: ","Error, solo numeros[1-7]",1,7,&opcion);

        switch(opcion)
        {
        case 1:
            borrar();//Usar Punteros para esto.
            respuesta=agregarAlumno(listaDeAlumnos,LA,listaDelocalidades,LL,&id_beta);
            switch(respuesta)
            {
            case 0:
                printf("Alumno no Cargado\n");
                break;
            case 1:
                printf("Alumno Cargado\n");
                break;
            case -1:
                printf("Espacio no Disponible\n");
                break;
            }
            pausa();
            break;
        case 2:
            borrar();
            submenu_Mostrar(listaDeAlumnos,LA,listaDelocalidades,LL,listaDeContador,LL);
            pausa();
            break;
        case 3:
            borrar();
            sortStudentsByNameAndAverage(listaDeAlumnos,LA);
            pausa();
            break;
        case 4:
            borrar();
            respuesta = eliminarAlumno(listaDeAlumnos,LA,listaDelocalidades,LL);
            switch(respuesta)
            {
            case 0:
                borrar();
                printf("Accion cancelada por el usuario\n");
                pausa();
                break;
            case 1:
                borrar();
                printf("Alumno eliminado\n");
                pausa();
                break;
            case -1:
                borrar();
                printf("Dato no encontrado\n");
                pausa();
                break;
            }

            break;
        case 5:
            /*
            respuesta = modificarAlumno(listaDeAlumnos,A,102);
            switch(respuesta)
            {
            case 0:
                printf("Accion cancelada por el usuario\n");
                break;
            case 1:
                printf("Alumno modificado\n");
                break;
            case -1:
                printf("Dato no encontrado\n");
                break;
            }*/
            break;
        }
        borrar();
    }
    while(opcion!=7);

    return 0;
}



