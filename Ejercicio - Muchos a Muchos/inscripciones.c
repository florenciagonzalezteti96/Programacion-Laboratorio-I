#include "inscripciones.h"
void inicializar_Inscripcion(eInscripciones listadoDeInscripciones[],int tamInscripciones){
    int i;
    for(i=0; i<tamInscripciones; i++){
        listadoDeInscripciones[i].isEmpty=LIBRE;
    }
}
int buscarLugarInscripcion(eInscripciones listadoDeInscripciones[],int tamInscripciones)
{
    int retorno = -1;
    int i;
    for(i=0; i<tamInscripciones; i++)
    {
        if(listadoDeInscripciones[i].isEmpty==LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int inscribirAlumno(eInscripciones listaDeInscripciones[], int tamInscripciones,eAlumno listadoDeAlumnos[],int tamAlumnos,eMateria listadoDeMaterias[],int tamMateria,eLocalidad listaDeLocalidades[],int tamLocalidad)
{
    int hayLugarDisponible;
    int legajo;
    int materia;
    int retorno = -1;
    hayLugarDisponible = buscarLugarInscripcion(listaDeInscripciones, tamInscripciones);

    if(hayLugarDisponible!=-1){
        mostrarListadoAlumnos(listadoDeAlumnos,lengAlumnos,arrayLocalidad,lengLocalidad);
        getValidInt("Ingrese el alumno a Inscribir:","Error,Solo los numeros en Pantalla",1000,1010,&legajo);
        listaDeInscripcion[indice].legajo=legajo;
        borrar();
        mostrar_Materias(listadoDeMateria,lengMateria);
        getValidInt("Ingrese la materia:","Error, solo los numero en la pantalla",100,103,&materia);
        listaDeInscripcion[indice].idMateria=materia;
        borrar();
        listaDeInscripcion[indice].Finscripcion=pedirFecha();

        borrar();
        printf("%d %d %d/%d/%d\n",listaDeInscripcion[indice].legajo,listaDeInscripcion[indice].idMateria,listaDeInscripcion[indice].Finscripcion.day,listaDeInscripcion[indice].Finscripcion.month,listaDeInscripcion[indice].Finscripcion.year);

        retorno=verifyConformity("Los datos ingresados son correctos?(Si/No)","Error, reponda (Si/No)");

        if(retorno==1){
            listaDeInscripcion[indice].estado=OCUPADO;

            //listadoDeAlumnos[indice].legajo=id_1;
            //id_1++;
            //*id_beta=id_1;
        }
        if(retorno==0){
            listaDeInscripcion[indice].estado=LIBRE;
        }
    }
    return retorno;
}
