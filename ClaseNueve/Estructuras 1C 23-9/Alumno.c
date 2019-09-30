#include "Alumno.h"

int buscarLibre(eAlumno listadoDeAlumnos[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
int buscarLocalidadPorId(eLocalidad listaDeLocalidades[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++){
        if(listaDeLocalidades[i].idLocalidad == id){
            indice = i;
            break;
        }
    }
    return indice;
}
void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int legajo[]= {101,102,105};
    float promedio[]= {6.66, 4,7.66};
    char nombre[][25]= {"Juan","Maria josefina","Maria"};
    int localidad[]={1,1,3};
    for(i=0; i<3; i++)
    {
        listadoDeAlumnos[i].legajo = legajo[i];
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].nombre, nombre[i]);
        listadoDeAlumnos[i].estado = OCUPADO;
        listadoDeAlumnos[i].idLocalidad=localidad[i];

    }
}
void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam, eLocalidad listaDeLocalidades[], int tl)
{
    int i;
    int index;
    eLocalidad unaLocalidad;

    for(i=0; i<tam; i++)
    {
        index = buscarLocalidadPorId(listaDeLocalidades, tl, listadoDeAlumnos[i].idLocalidad);
        if(index != -1){
            unaLocalidad = listaDeLocalidades[index];
            mostrarUnAlumno(listadoDeAlumnos[i], unaLocalidad);
        }
    }
}
void cargarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int indice;

    indice = buscarLibre(listadoDeAlumnos, tam);
    printf("Indice: %d\n", indice);
    if(indice!=-1)
    {
        listadoDeAlumnos[indice] = cargarAlumno();
    }
    else
    {
        printf("No hay espacio disponible");
    }

}
eAlumno cargarAlumno(void)
{
    eAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]", miAlumno.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &miAlumno.promedio);
    printf("En que localidad vive?");
    scanf("%d", &miAlumno.idLocalidad);
    miAlumno.estado = OCUPADO;

    return miAlumno;
}
void mostrarUnAlumno(eAlumno miAlumno, eLocalidad unaLocalidad)
{
    printf("%d", miAlumno.legajo);
    printf("%25s", miAlumno.nombre);
    printf("%8.2f ", miAlumno.promedio);
    printf("%10s\n", unaLocalidad.localidad);
}
void sortStudentsByNameAndAverage(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)>0)
            {
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }

            else
            {
                if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)==0)
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
}
int buscarAlumnoPorLegajo(eAlumno* listaDeAlumnos, int cant, int legajo)
{
    int i;
    int retorno = -1;


    if(listaDeAlumnos!=NULL && cant>0)
    {

     for(i=0; i<cant; i++)
    {
        if(listaDeAlumnos[i].legajo==legajo && listaDeAlumnos[i].estado==OCUPADO)
        {
            retorno = i;
            break;
        }
    }
    }
    return retorno;
}
int modificarAlumno(eAlumno listaDeAlumnos[], int cant, int legajo, eLocalidad listaLocalidades[], int tl)
{
    int index;
    int quePaso = -1;
    char respuesta;
    eAlumno aux;

    index = buscarAlumnoPorLegajo(listaDeAlumnos,cant, legajo);
    if(index!=-1)
    {
        aux = listaDeAlumnos[index];
        mostrarUnAlumno(aux, listaLocalidades[index]);
        printf("Ingrese el nuevo nombre: ");
        fflush(stdin);
        gets(aux.nombre);
        printf("Esta seguro que desea modificar este alumno? :");
        respuesta = getchar();
        if(respuesta=='s')
        {
            listaDeAlumnos[index] = aux;
            quePaso = 1;
        }
        else
        {
            quePaso = 0;
        }

    }
    return quePaso;
}
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tam, eLocalidad listaLocalidades[], int tl)
{
    int legajo;
    int i;
    char respuesta;
    int quePaso = -1;

    mostrarListadoAlumnos(listadoDeAlumnos,tam, listaLocalidades, tl);

    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++){
        if(listadoDeAlumnos[i].legajo==legajo && listadoDeAlumnos[i].estado==OCUPADO)
        {
            mostrarUnAlumno(listadoDeAlumnos[i], listaLocalidades[i]);
            printf("Esta seguro que desea eliminar este alumno? :");
            respuesta = getchar();
            if(respuesta=='s')
            {
                listadoDeAlumnos[i].estado = LIBRE;
                quePaso = 1;
            }
            else
            {
                quePaso = 0;
            }
            break;
        }
    }
    return quePaso;
}

int calcularCantidadAlumnos (eAlumno listaAlumno[], eLocalidad lista[], int tLocalidad, int tAlumnos){
    int retorno = -1;
    int i;
    int j;
    int cantidadAlumnos = 0;
    for(i=0;i<tLocalidad;i++){
            for(j=0;j<tAlumnos;j++){
            if(listaAlumno[j].idLocalidad == lista[i].idLocalidad){
                cantidadAlumnos ++;
                retorno = cantidadAlumnos;
            }
        }
    }
    return retorno;
}
int buscarLocalidadConMenosAlumnos(eLocalidad lista[], int tLocalidad, eAlumno listaAlumno[], int tAlumnos){
    int retorno = -1;
    eAux listaAux[3] = {{1,0},{2,0},{3,0}};
    int i;
    for(i=0;i<tLocalidad;i++){
        if(listaAux[i].idLocalidad == lista[i].idLocalidad){
            if(listaAlumno[i].idLocalidad == lista[i].idLocalidad){
                listaAux[i].cantidadAlumnos = listaAux[i].cantidadAlumnos + 1;
            }
        }
    }
        for(i=0;i<tLocalidad;i++){
        printf("localidad: %d -- alumnos: %d\n", listaAux[i].idLocalidad, listaAux[i].cantidadAlumnos);
    }






    return retorno;
}
int buscarMinimo (eAux lista[], int tAux){
    int retorno = -1;
    int flag = -1;
    int minimo;
    int i;
    for(i=0;i<tAux;i++){
        if(flag == -1 || minimo>lista[i].cantidadAlumnos){
            minimo = lista[i].cantidadAlumnos;
            flag = -1;
            retorno = minimo;
        }
    }
    return retorno;
}
int buscarIndiceMinimo (eAux lista[], int tAux){
    int retorno = -1;
    int minimo = buscarMinimo(lista, tAux);
    int i;
    for(i=0;i<tAux;i++){
        if(minimo == lista[i].cantidadAlumnos){
            minimo = lista[i].cantidadAlumnos;
            retorno = i;
            break;
        }
    }

    return retorno;
}

