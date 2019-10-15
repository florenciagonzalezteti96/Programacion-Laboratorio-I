#include "Pelicula.h"

int initPeliculas(ePelicula listadoDePeliculas[], int tamPeliculas)
{
    int i;
    int retorno = -1;
    if(tamPeliculas>0)
    {
        for(i=0; i<tamPeliculas; i++)
        {
            listadoDePeliculas[i].isEmpty = TRUE;
            retorno = 0;
        }
    }
    return retorno;
}
int initCodigoPelicula(ePelicula listadoDePeliculas[], int tamPeliculas)
{
    int i;
    int retorno = -1;
    if(tamPeliculas>0)
    {
        for(i=0; i<tamPeliculas; i++)
        {
            listadoDePeliculas[i].codigo = 0;
            retorno = 0;
        }
    }
    return retorno;
}
void hardcodearPeliculas(ePelicula listadoDePeliculas[], int tam)
{
    int i;
    int codigo[] = {101,102,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
    char descripcion[][25] = {"Hulk","Los Vengadores","Spiderman","Siempre a tu lado","Cube","Ultimo Baile","Alien","Mona Lisa","Samurai Vendetta","711","Grease","Mayo","El hijo de Godzilla","Fanny","Canon","El templo","Callejon de los milagros","Shangai","Enemigo del estado","Helen"};
    int duracion[] = {100,120,160,100,150,124,160,180,190,200,210,185,129,175,145,165,135,125,152,125,125};
    int idGenero[] = {1,1,3,2,4,4,4,1,1,2,3,4,1,2,1,2,3,4,1,2};
    for(i=0; i<tam; i++)
    {
        listadoDePeliculas[i].codigo = codigo[i];
        strcpy(listadoDePeliculas[i].descripcion, descripcion[i]);
        listadoDePeliculas[i].duracion = duracion[i];
        listadoDePeliculas[i].idGenero = idGenero[i];
        listadoDePeliculas[i].isEmpty = FALSE;
    }
}
void mostrarPelicula(ePelicula unaPelicula, eGenero listadoDeGeneros[],int tamGeneros)
{
    printf("%7d", unaPelicula.codigo);
    printf("%28s", unaPelicula.descripcion);
    printf("%24d", unaPelicula.duracion);
    mostrarGeneroPorId(listadoDeGeneros, tamGeneros, unaPelicula.idGenero);
    printf("\n");
}
void mostrarListaPeliculas(ePelicula listadoDePeliculas[],int tamPeliculas,eGenero listadoDeGeneros[],int tamGeneros)
{
    printf("Codigo:\t\t\tDescripcion:\tDuracion (minutos) :\tGenero:\n");
    int i;
    for(i=0; i<tamPeliculas; i++)
    {
        if(listadoDePeliculas[i].isEmpty == FALSE)
        {
            mostrarPelicula(listadoDePeliculas[i], listadoDeGeneros, tamGeneros);
        }
    }
    printf("\n");
}
int validarIdPelicula(ePelicula listadoDePeliculas[],int tamPeliculas,int idPelicula)
{
    int i;
    int retorno = -1;
    for(i=0; i<tamPeliculas; i++)
    {
        if(idPelicula == listadoDePeliculas[i].codigo)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int obtenerUnaPelicula(ePelicula listadoDePeliculas[],int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros)
{
    int idPelicula;
    mostrarListaPeliculas(listadoDePeliculas,tamPeliculas,listadoDeGeneros, tamGeneros);
    idPelicula = getInt("Ingrese el codigo de la pelicula: \n");
    while((validarIdPelicula(listadoDePeliculas, tamPeliculas, idPelicula)== -1))
    {
        idPelicula = getInt("El codigo de la pelicula ingresado es invalido. Reingrese: ");
        printf("\n");
    }
    return idPelicula;
}
int buscarIndicePelicula(ePelicula listadoDePeliculas[],int tamPeliculas,int idPelicula)
{
    int i;
    int retorno = -1;
    for(i=0; i<tamPeliculas; i++)
    {
        if(idPelicula == listadoDePeliculas[i].codigo)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int agregarUnaPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros)
{
    int retorno = 1;
    ePelicula nuevaPelicula;
    char confirmacion;
    char opcion_continuar;
    if(tamPeliculas>0)
    {
        do
        {
            nuevaPelicula = getDataPelicula(listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros);
            printf("\n");
            printf("Estos son los datos ingresados:\n");
            mostrarPelicula(nuevaPelicula, listadoDeGeneros, tamGeneros);
            printf("\n");
            confirmacion = getConfirmacion("Desea cargar los datos? Ingrese s para SI o n para NO: \n");
            if(confirmacion == 's')
            {
                retorno = cargarUnaPelicula(listadoDePeliculas, tamPeliculas, nuevaPelicula);
            }
            else if(confirmacion == 'n')
            {
                retorno = 2;
            }
            printf("\n");
            opcion_continuar = getConfirmacion("Desea ingresar otra pelicula? Ingrese s para SI o n para NO: ");
            printf("\n");
        }
        while(opcion_continuar == 's');
    }
    return retorno;
}
ePelicula getDataPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros)
{
    ePelicula unaPelicula;
    pedirCadena("Ingrese el nombre de la pelicula: ", unaPelicula.descripcion);
    unaPelicula.duracion = getInt("Ingrese la duracion de la pelicula: ");
    unaPelicula.idGenero = obtenerUnGenero(listadoDeGeneros, tamGeneros);
    unaPelicula.codigo = obtenerNuevoCodigoPelicula(listadoDePeliculas, tamPeliculas);
    printf("\n");
    return unaPelicula;
}
int obtenerNuevoCodigoPelicula(ePelicula listadoDePeliculas[], int tamPeliculas)
{
    int retorno = -1;
    int flag = 0;
    int nuevoCodigo;
    if(tamPeliculas>0)
    {
        int i;
        for(i=0; i<tamPeliculas; i++)
        {
            if(listadoDePeliculas[i].isEmpty == FALSE)
            {
                if(flag == 0 || listadoDePeliculas[i].codigo> nuevoCodigo)
                {
                    nuevoCodigo = listadoDePeliculas[i].codigo;
                    flag = 1;
                }
            }
        }
        nuevoCodigo ++ ;
        retorno = nuevoCodigo;
    }
    return retorno;
}
int cargarUnaPelicula(ePelicula listadoDePeliculas[],int tamPeliculas, ePelicula nuevaPelicula)
{
    int retorno = -1;
    int lugar_Disponible = getIsEmptyPeliculas(listadoDePeliculas, tamPeliculas);
    if(lugar_Disponible!= -1)
    {
        listadoDePeliculas[lugar_Disponible] = nuevaPelicula;
        listadoDePeliculas[lugar_Disponible].isEmpty = FALSE;
        retorno = 0;
    }
    return retorno;
}
int getIsEmptyPeliculas(ePelicula listadoDePeliculas[], int tamPeliculas)
{
    int i;
    int retorno = -1;
    if(tamPeliculas>0)
    {
        for(i=0; i<tamPeliculas; i++)
        {
            if(listadoDePeliculas[i].isEmpty == TRUE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int modificarUnaPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros)
{
    int retorno = -1;
    int codigo;
    int indice;
    ePelicula aux;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';

    mostrarListaPeliculas(listadoDePeliculas,tamPeliculas,listadoDeGeneros,tamGeneros);

    codigo = getInt("\nIngrese el id de la pelicula a modificar:");
    indice = buscarIndicePelicula(listadoDePeliculas, tamPeliculas, codigo);

    if(indice != -1)
    {
        aux = listadoDePeliculas[indice];
        do
        {
            system("cls");
            opcion = getInt("Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar duracion.\n3. Cambiar genero.\n4. Salir al menu principal.\n");
            switch(opcion)
            {
            case 1:
                pedirCadena("Ingrese un nuevo nombre: ", aux.descripcion);
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 2:
                aux.duracion = getInt("Ingrese una nueva duracion: ");
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO:");
                printf("\n");
                system("pause");
                break;
            case 3:
                aux.idGenero = obtenerUnGenero(listadoDeGeneros, tamGeneros);
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 4:
                confirmacion='n';
                printf("\n");
                system("pause");
                break;
            default:
                printf("Ingreso una opcion incorrecta.\n");
                printf("\n");
                system("pause");
                break;
            }
        }
        while(confirmacion == 's');

        printf("Esta es la nueva pelicula:\n");
        printf("\n");
        mostrarPelicula(aux, listadoDeGeneros, tamGeneros);
        printf("\n");
        cargar = getConfirmacion("\nDesea cargar los datos? Ingrese s para SI o n para NO:");
        if(cargar == 's')
        {
            listadoDePeliculas[indice]=aux;
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}
int eliminarPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros)
{
    int retorno = -1;
    int codigo = 0;
    int index = 0;
    char confirmacion;
    if(tamPeliculas>0)
    {
        printf("Estas son las peliculas:\n");
        mostrarListaPeliculas(listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros);
        codigo = getInt("\nIngrese el codigo de la pelicula que desea eliminar:");
        printf("\n");
        index = buscarIndicePelicula(listadoDePeliculas, tamPeliculas, codigo);
        if(index == -1)
        {
            retorno = 1;
        }
        else
        {
            mostrarPelicula(listadoDePeliculas[index],listadoDeGeneros,tamGeneros);
            confirmacion = getChar("\nEsta seguro que quiere eliminar la pelicula? Ingrese s para SI o n para NO:");
            if(confirmacion == 's')
            {
                retorno = removePelicula(listadoDePeliculas, tamPeliculas, codigo);
            }
            else if(confirmacion == 'n')
            {
                retorno = 2;
            }
        }
    }
    return retorno;
}
int removePelicula(ePelicula listadoDePeliculas[], int tamPeliculas, int codigoPelicula)
{
    int retorno = -1;
    int i;
    if(tamPeliculas>0)
    {
        for(i=0; i<tamPeliculas; i++)
        {
            if(listadoDePeliculas[i].isEmpty == FALSE)
            {
                if(listadoDePeliculas[i].codigo == codigoPelicula)
                {
                    listadoDePeliculas[i].isEmpty = TRUE;
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
int mostrarPeliculaPorId(ePelicula listadoDePeliculas[], int tamPeliculas, int codigoPelicula)
{
    int retorno = -1;
    int indicePelicula = buscarIndicePelicula(listadoDePeliculas, tamPeliculas, codigoPelicula);
    if(indicePelicula != -1)
    {
        printf("%20s", listadoDePeliculas[indicePelicula].descripcion);
        retorno = 0;
    }
    return retorno;
}
