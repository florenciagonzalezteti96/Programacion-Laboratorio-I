#include "alumno.h"
void initAlumnos(eAlumno listadoDeAlumnos[], int tamAlumnos){
    int i;
    for(i=0;i<tamAlumnos;i++){
        listadoDeAlumnos[i].isEmpty = LIBRE;
    }
}
void initLegajosAlumnos(eAlumno listadoDeAlumnos[], int tamAlumnos){
    int i;
    for(i=0;i<tamAlumnos;i++){
        listadoDeAlumnos[i].legajo = 0;
    }
}
void mostrarUnAlumno(eAlumno unAlumno, eLocalidad unaLocalidad){
    printf("%7d", unAlumno.legajo);
    printf("%16s", unAlumno.name);
    printf("%18s", unAlumno.lastName);
    printf("%15d", unAlumno.promedio);
    printf("%18s\n", unaLocalidad.nombreLocalidad);
}
void mostrarDatosIngresadosAlumno(eLocalidad listadoDeLocalidades[], int tamLocalidad, char name[], char lastName[], float promedio, int idLocalidad){
    printf("%s",name);
    printf("%20s",lastName);
    printf("%15.2f",promedio);
    mostrarLocalidadPorId(listadoDeLocalidades, tamLocalidad, idLocalidad);
}
int mostrarAlumnos(eAlumno listadoDeAlumnos[], int tamAlumnos, eLocalidad listadoDeLocalidades[], int tamLocalidad){
    int retorno = -1;
    int localidad;
    int i;
    if(tamAlumnos>0 && tamLocalidad>0){
        printf("LEGAJO:\t\tNOMBRE:\t\tAPELLIDO:\tPROMEDIO:\tLOCALIDAD:\n");
        for(i=0; i<tamAlumnos; i++){
            if(listadoDeAlumnos[i].isEmpty != LIBRE){
                localidad = buscarLocalidadPorId(listadoDeLocalidades, tamLocalidad, listadoDeAlumnos[i].idLocalidad);
                mostrarUnAlumno(listadoDeAlumnos[i], listadoDeLocalidades[localidad]);
                retorno = 0;
            }
        }
    }
    return retorno;
}
int addAlumno(eAlumno listadoDeAlumnos[], int tamAlumnos, eLocalidad listadoDeLocalidades[], int tamLocalidad, int legajo, char name[],char lastName[], float promedio, int idLocalidad){
    int retorno = -1;
    int lugar_Disponible = getIsEmpty(listadoDeAlumnos, tamAlumnos);
    int localidadExiste = existeLocalidad(listadoDeLocalidades, tamLocalidad, idLocalidad);
    if(lugar_Disponible!= -1 && localidadExiste != -1){
        listadoDeAlumnos[lugar_Disponible].legajo = legajo;
        strcpy(listadoDeAlumnos[lugar_Disponible].name, name);
        strcpy(listadoDeAlumnos[lugar_Disponible].lastName, lastName);
        listadoDeAlumnos[lugar_Disponible].promedio = promedio;
        listadoDeAlumnos[lugar_Disponible].idLocalidad = idLocalidad;
        listadoDeAlumnos[lugar_Disponible].isEmpty = OCUPADO;
        retorno = 0;
    }
    return retorno;
}
void getDataAlumno(eLocalidad listadoDeLocalidades[], int tamLocalidad, char name[],char lastName[],float* promedio, int* idLocalidad){
    printf("Ingrese los datos del alumno: \n");
    pedirCadena("Nombre del alumno:", name);
    pedirCadena("\nApellido del alumno: ", lastName);
    *promedio = getFloat("\nPromedio del alumno: ");
    *idLocalidad = getLocalidad(listadoDeLocalidades, tamLocalidad);
}
int getIsEmpty(eAlumno listadoDeAlumnos[], int tamAlumnos){
    int retorno = -1;
    int i;
    for(i=0;i<tamAlumnos;i++){
        if(listadoDeAlumnos[i].isEmpty == LIBRE){
            retorno = i;
            break;
        }
    }
    return retorno;
}
int getNuevoLegajo(eAlumno listadoDeAlumnos[], int tamAlumnos){
    int retorno = -1;
    int flag = 0;
    int nuevoLegajo;
    if(tamAlumnos>0){
        int i;
        for(i=0;i<tamAlumnos;i++){
            if(flag == 0 || listadoDeAlumnos[i].legajo>nuevoLegajo){
                nuevoLegajo = listadoDeAlumnos[i].legajo;
                flag = 1;
            }
        }
        retorno = nuevoLegajo;
    }
    return retorno;
}
int cargarUnAlumno(eAlumno listadoDeAlumnos[], int tamAlumnos, eLocalidad listadoDeLocalidades[], int tamLocalidad){
    int retorno = 1;
    char name[51];
    char lastName[51];
    float promedio;
    int idLocalidad;
    int legajo;//se calcula automaticamente
    char confirmacion;
    char opcion_continuar;
    if(tamAlumnos>0 && tamLocalidad>0){
        do{
            getDataAlumno(listadoDeLocalidades, tamLocalidad, name, lastName, &promedio, &idLocalidad);
            printf("\n");
            printf("Estos son los datos ingresados:\n");
            mostrarDatosIngresadosAlumno(listadoDeLocalidades, tamLocalidad, name, lastName, promedio, idLocalidad);//cambiar en la funcion showData, y que me muestre la localidad por idLocalidad
            printf("\n");
            confirmacion = getConfirmacion("Desea cargar los datos? Ingrese s para SI o n para NO: \n");
            if(confirmacion == 's'){
                legajo = getNuevoLegajo(listadoDeAlumnos, tamAlumnos);
                legajo++;
                retorno = addAlumno(listadoDeAlumnos, tamAlumnos, listadoDeLocalidades, tamLocalidad, legajo, name, lastName, promedio, idLocalidad);
            }
            else if(confirmacion == 'n'){
                retorno = 2;
            }
            printf("\n");
            opcion_continuar = getConfirmacion("Desea ingresar otro alumno? Ingrese s para SI o n para NO: ");
            printf("\n");
        }while(opcion_continuar == 's');
    }
    return retorno;
}
void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam){
    int i;
    int legajo[]= {101,102,105,106,107,110,108,109,112,111};
    float promedio[]= {6.66, 4,7.66,10.00,7.80,1,5,6,9,3};
    char nombre[][25]= {"Juan","Maria josefina","Maria","Flopy","Luca","Lucia","Alan","German","Brian","Pedro"};
    char apellido[][25]= {"Perez","Fernandez","Serrano","Gonzalez","Lodola","Morel","Passu","Villegas","Gonzalez","PepePoopPoop"};
    int localidad[]= {101,103,102,107,101,106,103,106,105,107};
    for(i=0; i<tam; i++){
        listadoDeAlumnos[i].legajo = legajo[i];
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].name, nombre[i]);
        strcpy(listadoDeAlumnos[i].lastName,apellido[i]);
        listadoDeAlumnos[i].isEmpty = OCUPADO;
        listadoDeAlumnos[i].idLocalidad=localidad[i];
    }
}
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tamAlumnos, eLocalidad listadoDeLocalidades[], int tamLocalidades){
    int legajo;
    int localidad;
    char opcionContinuar;
    int retorno = -1;

    mostrarAlumnos(listadoDeAlumnos,tamAlumnos,listadoDeLocalidades,tamLocalidades);
    legajo = getInt("Ingrese el legajo del alumno para realizar la baja: ");

    int i;
    for(i=0; i<tamAlumnos; i++){
        if((listadoDeAlumnos[i].legajo==legajo) && (listadoDeAlumnos[i].isEmpty==OCUPADO)){
            localidad = buscarLocalidadPorId(listadoDeLocalidades,tamLocalidades,listadoDeAlumnos[i].idLocalidad);
            mostrarUnAlumno(listadoDeAlumnos[i],listadoDeLocalidades[localidad]);
            opcionContinuar = getConfirmacion("Esta seguro que desea eliminar este alumno? Ingrese s para SI o n para NO");
            if(opcionContinuar=='s'){
                listadoDeAlumnos[i].isEmpty = LIBRE;
                retorno = 0;
            }else{
                retorno = 1;
            }
        }
    }
    return retorno;
}
void mostrarUnAlumnoPorLocalidad(eAlumno listadoDeAlumnos[],int tamAlumnos, eLocalidad listadoDeLocalidades[],int indiceLocalidad){
    int i;
    for(i=0;i<tamAlumnos;i++){
        if(listadoDeAlumnos[i].isEmpty==OCUPADO){
            if(listadoDeLocalidades[indiceLocalidad].id==listadoDeAlumnos[i].idLocalidad){
                mostrarUnAlumno(listadoDeAlumnos[i],listadoDeLocalidades[indiceLocalidad]);
            }
        }
    }
}
void mostrarAlumnosPorLocalidad(eAlumno listadoDeAlumnos[],int tamAlumnos,eLocalidad listadoDeLocalidades[], int tamLocalidad){
    int i;
    for(i=0;i<tamLocalidad;i++){
        printf("Localidad: %s\n", listadoDeLocalidades[i].nombreLocalidad);
        mostrarUnAlumnoPorLocalidad(listadoDeAlumnos, tamAlumnos, listadoDeLocalidades, i);
        printf("\n\n");
    }
}
void mostrarAlumnosDeAvellaneda(eAlumno listadoDeAlumnos[],int tamAlumnos,eLocalidad listadoDeLocalidades[],int tamLocalidad){
    char descripcion[]= {"Avellaneda"};
    int i;
    for(i=0;i<tamLocalidad;i++){
        if(strcmp(listadoDeLocalidades[i].nombreLocalidad,descripcion)==0){
            printf("Estos son los alumnos en %s:\n",descripcion);
            mostrarUnAlumnoPorLocalidad(listadoDeAlumnos,tamAlumnos,listadoDeLocalidades,i);
        }
        printf("\n");
    }
}
void ordenarAlumnosPorNombreYPromedio(eAlumno listadoDeAlumnos[], int tamAlumnos){
    eAlumno auxAlumno;
    int i;
    int j;
    for(i=0; i<tamAlumnos-1; i++){
        for(j=i+1; j<tamAlumnos; j++){
            if(strcmp(listadoDeAlumnos[i].name,listadoDeAlumnos[j].name)>0){
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }else{
                if(strcmp(listadoDeAlumnos[i].name,listadoDeAlumnos[j].name)==0){
                    if(listadoDeAlumnos[i].promedio>listadoDeAlumnos[j].promedio){
                        auxAlumno = listadoDeAlumnos[i];
                        listadoDeAlumnos[i] = listadoDeAlumnos[j];
                        listadoDeAlumnos[j] = auxAlumno;
                    }
                }
            }
        }
    }
}
void cantidadAlumnosPorLocalidad(eAlumno listadoDeAlumnos[],int tamAlumnos,eLocalidad listadoDeLocalidades[],int tamLocalidades){
    eContador auxContador[tamLocalidades];
    hardcodearContador(auxContador, tamLocalidades, listadoDeLocalidades);
    int i,j;
    for(i=0; i<tamLocalidades; i++){
        for(j=0; j<tamAlumnos; j++){
            if(listadoDeAlumnos[j].isEmpty==OCUPADO){
                if(listadoDeAlumnos[j].idLocalidad==listadoDeAlumnos[i].idLocalidad){
                    auxContador[i].contadorAlumnos++;
                }
            }
        }
    }
}
int buscarAlumnoLegajo(eAlumno listadoDeAlumnos[],int tamAlumnos,int legajo){
    int i;
    int retorno = -1;
    for(i=0;i<tamAlumnos;i++){
        if(listadoDeAlumnos[i].isEmpty==OCUPADO){
            if(listadoDeAlumnos[i].legajo==legajo){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
