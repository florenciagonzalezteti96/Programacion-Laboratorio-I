#include "alumno.h"


void inicializar_Alumnos(eAlumno listadoDeAlumnos[],int lengAlumnos)
{
    int i;

    for(i=0; i<lengAlumnos; i++)
    {
        listadoDeAlumnos[i].estado=LIBRE;

    }


}

eAlumno cargarAlumno(eLocalidad arrayLocalidad[],int lengLocalidad)
{
    eAlumno auxAlumno;
    eLocalidad unaLocalidad;


    //getValidInt("Ingrese un legajo:","legajo solo de numeros",0,1000,&auxAlumno.legajo);
    //borrar();
    getValidString("Ingrese un Nombre:","Solo letras",0,50,auxAlumno.name);
    borrar();
    getValidString("Ingrese un Apellido:","Solo letras",0,50,auxAlumno.lastname);
    borrar();
    getValidInt("Ingrese el Promedio:","promedio, Solo Numeros",0,10,&auxAlumno.promedio);
    borrar();

    unaLocalidad=una_localidad(arrayLocalidad,lengLocalidad);
    auxAlumno.idLocalidad=unaLocalidad.id;

    auxAlumno.estado=OCUPADO;

    return auxAlumno;
}

int buscar_Libre(eAlumno listadoDeAlumnos[],int lengAlumnos)
{
    int indice = -1;
    int i;

    for(i=0; i<lengAlumnos; i++)
    {
        if(listadoDeAlumnos[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;//retorno -1 sino encontro un lugar libre
}

int agregarAlumno(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad,int* id_beta)
{
    int indice;
    int localidad;
    int id_1;
    int retorno=-1;
    indice = buscar_Libre(listadoDeAlumnos, lengAlumnos);

    if(indice!=-1)
    {
        //hay lugar
        id_1=*id_beta;
        listadoDeAlumnos[indice] = cargarAlumno(arrayLocalidad,lengLocalidad);
        listadoDeAlumnos[indice].legajo=id_1;
        borrar();
        localidad=buscarLocalidadId(arrayLocalidad,lengLocalidad,listadoDeAlumnos[indice].idLocalidad);
        mostrarUnAlumno(listadoDeAlumnos[indice],arrayLocalidad[localidad]);

        retorno=verifyConformity("El Alumno ingresado es correcto?(Si/No)","Error, reponda (Si/No)");

        if(retorno==1)
        {
            listadoDeAlumnos[indice].estado=OCUPADO;
            listadoDeAlumnos[indice].legajo=id_1;
            id_1++;
            *id_beta=id_1;
        }
        if(retorno==0)
        {
            listadoDeAlumnos[indice].estado=LIBRE;
        }

    }


    return retorno;
}

void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam,int* id)
{
    int i;
    int id_1;
    id_1=*id;
    //int legajo[]= {101,102,105,106,107};
    float promedio[]= {6.66, 4,7.66,10.00,7.80,1,5,6,9,3};
    char nombre[][25]= {"Juan","Maria josefina","Maria","Flopy","Luca","Lucia","Alan","German","Brian","Pedro"};
    char apellido[][25]= {"Perez","Fernandez","Serrano","Gonzalez","Lodola","Morel","Passu","Villegas","Gonzalez","PepePoopPoop"};
    int localidad[]= {101,103,102,101,101,103,103,102,101,103};
    for(i=0; i<tam; i++)
    {
        listadoDeAlumnos[i].legajo = id_1;
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].name, nombre[i]);
        strcpy(listadoDeAlumnos[i].lastname,apellido[i]);
        listadoDeAlumnos[i].estado = OCUPADO;
        listadoDeAlumnos[i].idLocalidad=localidad[i];
        id_1++;

    }
    *id=id_1;

}
void mostrarUnAlumno(eAlumno miAlumno,eLocalidad miLocalidad)
{

    printf("%4d %20s %20s %15d %25s\n",miAlumno.legajo,miAlumno.name,miAlumno.lastname, miAlumno.promedio, miLocalidad.descripcion);

}
void mostrarSoloAlumno(eAlumno miAlumno)
{

    printf("%4d %20s %20s %15d\n",miAlumno.legajo,miAlumno.name,miAlumno.lastname, miAlumno.promedio);

}

void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam,eLocalidad listaLocalidad[],int lenLocal)
{
    int i;
    int index;

    printf("\n%4s %20s %20s %15s %25s\n","Id","Nombre","Apellido","Promedio","Localidad");
    for(i=0; i<tam; i++)
    {

        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            index  = buscarLocalidadId(listaLocalidad,lenLocal,listadoDeAlumnos[i].idLocalidad);
            if(index!=-1)
            {
                mostrarUnAlumno(listadoDeAlumnos[i],listaLocalidad[index]);
            }
        }
    }
    printf("\n");
}
void mostrarListadoSoloAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    //int index;

    printf("\n%4s %20s %20s %15s\n","Id","Nombre","Apellido","Promedio");
    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            mostrarSoloAlumno(listadoDeAlumnos[i]);
        }
    }
    printf("\n");
}
void submenu_Mostrar(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad,eContador arrayDeContador[],int lengContador)
{

    int opcion;


    do
    {
        printf("%30s\n","SUB MENU MOSTRAR");
        getValidInt("1. Mostrar todos los alumnos con la descripcion de su localidad\n2. Mostrar todas las localidades\n3. Mostrar por cada localidad, todos los alumnos que viven en ella\n4. Mostrar los alumnos que viven en Avellaneda\n5. Mostrar la localidad con habitantes\n6. Salir al menu\nElija una opcion: ",
                    "Error. Solo numeros, Elija las opciones correspodientes.",1,6,&opcion);

        switch(opcion)
        {

        case 1:
            borrar();
            mostrarListadoAlumnos(listadoDeAlumnos, lengAlumnos,arrayLocalidad,lengLocalidad);
            pausa();
            break;
        case 2:
            borrar();
            mostrar_Localidades(arrayLocalidad,lengLocalidad);
            pausa();
            break;
        case 3:
            borrar();
            mostrar_porLocalidad(listadoDeAlumnos, lengAlumnos,arrayLocalidad,lengLocalidad);
            pausa();
            break;
        case 4:
            borrar();
            mostrar_SoloAvellaneda(listadoDeAlumnos, lengAlumnos,arrayLocalidad,lengLocalidad);
            pausa();
            break;
        case 5:
            borrar();
            contarAlumnos(listadoDeAlumnos,lengAlumnos,arrayLocalidad,lengLocalidad,arrayDeContador,lengContador);
            pausa();
            break;
        }
        borrar();
    }
    while(opcion!=6);

}
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tam, eLocalidad listaLocalidad[], int lenLocal)
{
    int legajo;
    int i;
    int index;
    int respuesta=-1;
    mostrarListadoAlumnos(listadoDeAlumnos,tam,listaLocalidad,lenLocal);

    legajo=getInt("Ingrese el legajo:");

    for(i=0; i<tam; i++)
    {

        if(listadoDeAlumnos[i].legajo==legajo && listadoDeAlumnos[i].estado==OCUPADO)
        {
            index  = buscarLocalidadId(listaLocalidad,lenLocal,listadoDeAlumnos[i].idLocalidad);
            borrar();
            mostrarUnAlumno(listadoDeAlumnos[i],listaLocalidad[index]);

            respuesta=verifyConformity("Esta seguro que desea eliminar este alumno?[Si/No]:","Error, solo letra [Si/No]");

            if(respuesta==1)
            {
                listadoDeAlumnos[i].estado = LIBRE;

            }

        }

    }

    return respuesta;

}
void mostrar_AlumnoLocalidad(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad)
{
    int i;
    for(i=0; i<lengAlumnos; i++)
    {
        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            if(arrayLocalidad[lengLocalidad].id==listadoDeAlumnos[i].idLocalidad)
            {
                mostrarUnAlumno(listadoDeAlumnos[i],arrayLocalidad[lengLocalidad]);

            }
        }
    }

}

void mostrar_porLocalidad(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad)
{
    int i;
    for(i=0; i<lengLocalidad; i++)
    {
        printf("%30s\n",arrayLocalidad[i].descripcion);
        mostrar_AlumnoLocalidad(listadoDeAlumnos,lengAlumnos,arrayLocalidad,i);
        printf("\n\n");
    }
}
void mostrar_SoloAvellaneda(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad)
{
    int i;

    char option[]= {"Avellaneda"};

    for(i=0; i<lengLocalidad; i++)
    {

        if(strcmp(arrayLocalidad[i].descripcion,option)==0)
        {
            printf("%30s\n",arrayLocalidad[i].descripcion);

            mostrar_AlumnoLocalidad(listadoDeAlumnos,lengAlumnos,arrayLocalidad,i);
        }
        printf("\n");
    }

}
void sortStudentsByNameAndAverage(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    printf("Ordenando alumnos...\n");

    pausa();
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoDeAlumnos[i].name,listadoDeAlumnos[j].name)>0)
            {
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }

            else
            {
                if(strcmp(listadoDeAlumnos[i].name,listadoDeAlumnos[j].name)==0)
                {
                    if(listadoDeAlumnos[i].promedio>listadoDeAlumnos[j].promedio)
                    {
                        auxAlumno = listadoDeAlumnos[i];
                        listadoDeAlumnos[i] = listadoDeAlumnos[j];
                        listadoDeAlumnos[j] = auxAlumno;
                    }
                }
            }
        }

    }
    borrar();
    printf("Alumnos Ordenados.\n");

}

int verifyConformity (char message[], char cancelMessage[])
{
    int save=0; //bandera que avisa si el usuario desea guardar los datos ingresados
    char answer[2]; //respuesta del usuario
    int respuesta;

    getValidString(message,cancelMessage,2,2,answer);
    respuesta=strcmp(answer,"Si");
    borrar();
    if (respuesta==0)
    {

        save=1;
    }
    return save;
}

void cantidadAlumnosPorLocalidad(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad,eContador arrayContador[])
{
    int i,j;

    for(i=0; i<lengLocalidad; i++)
    {
        for(j=0; j<lengAlumnos; j++)
        {
            if(listadoDeAlumnos[j].estado==OCUPADO)
            {
                if(listadoDeAlumnos[j].idLocalidad==arrayLocalidad[i].id)//verificar el estado
                {

                    arrayContador[i].contadorAlumnos++;

                }
            }
        }
    }
}

void contarAlumnos(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad,eContador arrayContador[],int lenContador)
{
    int respuesta;
    int i;
    cantidadAlumnosPorLocalidad(listadoDeAlumnos,lengAlumnos,arrayLocalidad,lengLocalidad,arrayContador);
    getValidInt("1-Obtener el minimo\n2-Obtener el maximo\nElija una opcion: ","Error, solo numeros.",1,2,&respuesta);
    for(i=0; i<lengAlumnos; i++)
    {
        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            mostrar_Contador(arrayContador,lenContador,arrayLocalidad,lengLocalidad,respuesta);
        }
    }

}

void pausa()
{
    //if(sysOp==1)
    //
    //system("read -p 'Press Enter to continue...' var");
    //}
    //if (sysOp==2)
    //{
        system("pause");
    //}
}
void borrar()
{
    //if(sysOp==1)
    //{
    system("cls");
    //}
    //if (sysOp==2)
    //{
    //    system("cls");
    //}
}
