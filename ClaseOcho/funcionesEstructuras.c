#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcionesEstructuras.h"
#include "localidad.h"
#include "ctype.h"

void mostrar_menu(eAlumno listadoDeAlumnos[], int tam){
    int option;
    char option_continue='s';
    inicializarAlumnos(listadoDeAlumnos, tam);
    hardcodearEstructura(listadoDeAlumnos, 5);
    do{
        system("cls");
        printf("\nOpciones:\n1. Mostrar los alumnos.\n2. Cargar alumnos.\n3. Buscar por nombre.\n4.Borrar a un alumno por legajo.\n5.Borrar a un alumno por nombre.\n6.Modificar un alumno\n7.Salir.\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            listarAlumnos(listadoDeAlumnos, tam);
            printf("\n");
            system("pause");
            break;
        case 2:
            if((cargarUnAlumno(listadoDeAlumnos, tam) == -1)){
               printf("No hay espacio disponible!");
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            buscarPorLegajo(listadoDeAlumnos, tam);
            printf("\n");
            system("pause");
            break;
        case 4:
            borrarLegajo(listadoDeAlumnos, tam);
            printf("\n");
            system("pause");
            break;
        case 5:
            borrarPorNombre(listadoDeAlumnos, tam);
            printf("\n");
            system("pause");
            break;
        case 6:
            modificarAlumno(listadoDeAlumnos, tam);
            printf("\n");
            system("pause");
            break;
        default:
            option_continue='n';
            printf("\n");
            system("pause");
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}

void hardcodearEstructura(eAlumno listaDeAlumnos[], int cantidadDeAlumnos){
    int i;
    int auxLegajos[] = {1,3,5,4,7};
    int auxNotas[] = {10,2,9,6,8};
    char nombresAux[][50] = {"Juan","Pedro","Maria", "Maria", "Pablo"};
    for(i=0;i<cantidadDeAlumnos;i++){
        listaDeAlumnos[i].legajo = auxLegajos[i];
        listaDeAlumnos[i].nota = auxNotas[i];
        strcpy(listaDeAlumnos[i].nombre, nombresAux[i]);
        listaDeAlumnos[i].isEmpty = OCUPADO;
    }
}
int cargarUnAlumno(eAlumno listadoDeAlumnos[], int tam){
    int indice;
    int retorno = -1;
    indice = dameElPrimerLugarLibre(listadoDeAlumnos, tam);
    if(indice != -1){
        listadoDeAlumnos[indice] = crearUnAlumno();
        retorno = 0;
    }
    return retorno;
}
eAlumno crearUnAlumno (){
    eAlumno auxAlumno;

    pedirCadena("Ingrese un nombre: ", auxAlumno.nombre);
    auxAlumno.nota = getInt("Ingrese una nota: ");
    auxAlumno.legajo = getInt("Ingrese un legajo: ");
    auxAlumno.isEmpty = OCUPADO;

    return auxAlumno;
}
void listarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos){
    int i;
    int hayAlumnos = 0;
    printf("NOMBRE:\t\tLEGAJO:\t\tNOTA:\t\t\n");
    for(i=0;i<cantidadDeAlumnos;i++){
        if(listadoDeAlumnos[i].isEmpty != LIBRE){
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
    printf("%s\t\t", listadoDeAlumnos.nombre);
    printf("%d\t\t", listadoDeAlumnos.legajo);
    printf("%d\t\t", listadoDeAlumnos.nota);
}
void inicializarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos){
    int i;
    for(i=0;i<cantidadDeAlumnos;i++){
        listadoDeAlumnos[i].isEmpty = LIBRE;
    }
}
int dameElPrimerLugarLibre(eAlumno listaDeAlumnos[], int cantidadDeAlumnos){
    int i;
    int retorno = -1;
    for(i=0;i<cantidadDeAlumnos;i++){
        if(listaDeAlumnos[i].isEmpty == OCUPADO){
            retorno = i;
            break;
        }
    }
    return retorno;
}
void borrarLegajo(eAlumno listaDeAlumnos[], int cantidadDeAlumnos){
    int i;
    int legajo;
    int existeLegajo = 1;
    printf("Ingrese un legajo:\n");
    scanf("%d", &legajo);
    for(i=0;i<cantidadDeAlumnos;i++){
        if(listaDeAlumnos[i].legajo == legajo && listaDeAlumnos[i].isEmpty != OCUPADO){
                    listaDeAlumnos[i].isEmpty = LIBRE;
                    existeLegajo = 0;
                    break;
                }
        }
    if(existeLegajo != 0){
        printf("El dato no existe!");
    }
}
int buscarPorLegajo(eAlumno listadoDeAlumno[], int tam){
    int legajo;
    int retorno = -1;
    legajo = getInt("Ingrese un legajo: ");
    int i;
    for(i=0;i<tam;i++){
        if(listadoDeAlumno[i].legajo == legajo && listadoDeAlumno[i].isEmpty == OCUPADO){
            retorno = i;
        }
    }
    return retorno;
}
int modificarAlumno(eAlumno listadoDeAlumno[], int tam){
    int retorno = -1;
    int indice;
    eAlumno aux;
    int opcion;
    char confirmacion = 's';
    char confirmacion2 = 'n';

    indice = buscarPorLegajo(listadoDeAlumno, tam);
    aux = listadoDeAlumno[indice];
    if(indice != -1){
        do{
            opcion = getInt("Ingrese una opcion:\n1.Cambiar nombre\n2.Cambiar nota\nIngrese 3 para salir.\n");
            switch(opcion){
            case 1:
                pedirCadena("Ingrese un nombre: ", aux.nombre);
                printf("Desea seguir ingresando datos? Ingrese s para SI o n para NO\n");
                fflush(stdin);
                scanf("%c", &confirmacion);
                break;
            case 2:
                aux.nota = getInt("Ingrese una nota: ");
                printf("Desea seguir ingresando datos? Ingrese s para SI o n para NO\n");
                fflush(stdin);
                scanf("%c", &confirmacion);
                break;
            }
        }while(confirmacion == 's');

        printf("Este es el alumno:\n");
        mostrarUnAlumno(aux);
        printf("Desea cargar los datos?\n");
        fflush(stdin);
        scanf("%c", &confirmacion2);
        if(confirmacion2 == 's'){
            listadoDeAlumno[indice]=aux;
            retorno = 1;
        }else{
            retorno = 0;
        }
    }
    //retorno = 1 cargo los dtos
    //retorno = 0 cancelo la accion
    //retorno = -1 no se encontro el dato
    return retorno;
}
void borrarPorNombre(eAlumno listadoDeAlumno[], int tam){
    char nombre [20];
    printf("Ingrese un nombre:\n");
    fflush(stdin);
    gets(nombre);
    int i;
    for(i=0;i<tam;i++){
        if(strcmp(listadoDeAlumno[i].nombre, nombre)== 0){
            listadoDeAlumno[i].isEmpty = LIBRE;
        }
    }
}
void ordenarPorNombreDescente(eAlumno listadoDeAlumnos[], int tam){
    int i;
    int j;
    eAlumno auxAlumno;
    for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
            if(stricmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)<0){
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }
        }
    }
}
void ordenarPorNombreAscendente(eAlumno listadoDeAlumnos[], int tam){
    int i;
    int j;
    eAlumno auxAlumno;
    for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
            if(stricmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)>0){
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }
        }
    }
}
void ordenarPorNombreLegajoDescendente(eAlumno listadoDeAlumnos[], int tam){
    int i;
    int j;
    eAlumno auxAlumno;
    for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
            if(listadoDeAlumnos[i].legajo<listadoDeAlumnos[j].legajo){
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }
        }
    }
}
void ordenarPorNombreLegajoAscendente(eAlumno listadoDeAlumnos[], int tam){
    int i;
    int j;
    eAlumno auxAlumno;
    for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
            if(listadoDeAlumnos[i].legajo>listadoDeAlumnos[j].legajo){
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }
        }
    }
}
void firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(i=0;i<tam;i++){
        if(cadena[i]!='\0'){
            if(isspace(cadena[i])){
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}
void pedirCadena (char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    firstToUpper(cadena);
}
int getInt(char mensaje[]){
    int numero;
    printf("%s: ", mensaje);
    scanf("%d", &numero);
    return numero;
}
