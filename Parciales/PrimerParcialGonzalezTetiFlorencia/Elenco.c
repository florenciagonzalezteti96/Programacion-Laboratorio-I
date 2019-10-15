#include "Elenco.h"

void mostrarMenuElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores)
{
    int option;
    int retorno;
    char option_continue = 'n';
    inicializarElencos(listadoDeElencos, tamElencos);
    hardcodearElencos(listadoDeElencos, 20);
    do
    {
        system("cls");
        printf("\t\t\t******* MENU PARA GESTION DE ELENCOS *******\n");
        option = getInt("Opciones:\n1. Altas.\n2. Listado\n3. Salir del menu.\n");
        switch(option)
        {
        case 1:
            retorno = agregarUnElenco(listadoDeElencos,tamElencos, listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeActores, tamActores);
            switch(retorno)
            {
            case -1:
                printf("No se ha podido acceder a la carga de datos.\n");
                break;
            case 0:
                printf("Se ha cargado el elenco.\n");
                break;
            case 1:
                printf("Error. El elenco ya existe.\n");
                break;
            case 2:
                printf("El usuario ha cancelado la accion.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 2:
            retorno = ordenarElencos(listadoDeElencos,tamElencos, listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores);
            switch(retorno)
            {
            case -1:
                printf("No se ha podido acceder a la opcion de ordenamiento y listar.\n");
            case 0:
                printf("Se ha realizado el ordenamiento por pelicula:\n");
                mostrarListaElencos(listadoDeElencos,tamElencos, listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeActores, tamActores);
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            option_continue = getChar("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
            printf("\n");
            system("pause");
            break;
        default:
            printf("Ha ingresado una opcion incorrecta.\n");
            printf("\n");
            system("pause");
            break;
        }
    }
    while(option_continue=='n');
    printf("\n");
}
void mostrarMenus(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores)
{
    int option;
    int retorno;
    char option_continue = 'n';

    initPeliculas(listadoDePeliculas, tamPeliculas);
    initActor(listadoDeActores, tamActores);
    inicializarElencos(listadoDeElenco, tamElencos);

    hardcodearPeliculas(listadoDePeliculas, 20);
    hardcodearGeneros(listadoDeGeneros, tamGeneros);
    hardcodearActores(listadoDeActores, 30);
    hardcodearElencos(listadoDeElenco, 20);

    do
    {
        system("cls");
        printf("\t\t\t******* MENU PARA GESTION DE ELENCOS Y ACTORES *******\n");
        option = getInt("Opciones:\n1. Gestion de actores.\n2. Gestion de elencos.\n3. Salir del programa.\n");
        switch(option)
        {
        case 1:
            mostrarMenuActores(listadoDeActores, tamActores, listadoDePeliculas, tamPeliculas);
            printf("\n");
            system("pause");
            break;
        case 2:
            mostrarMenuElencos(listadoDeElencos, tamElencos, listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeActores, tamActores);
            printf("\n");
            system("pause");
            break;
        case 3:
            option_continue = getChar("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
            printf("\n");
            system("pause");
            break;
        default:
            printf("Ha ingresado una opcion incorrecta.\n");
            printf("\n");
            system("pause");
            break;
        }
    }
    while(option_continue=='n');
    printf("\n");
}
int inicializarElencos(eElenco listaDeElencos[], int tamElencos)
{
    int i;
    int retorno = -1;
    if(tamElencos>0)
    {
        for(i=0; i<tamElencos; i++)
        {
            listaDeElencos[i].isEmpty = TRUE;
            retorno = 0;
        }
    }
    return retorno;
}
void hardcodearElencos(eElenco listadoDeElencos[], int tamElencos)
{
    int i;
    int codigoPelicula[] = {101,101,101,111,107,101,113,122,113,122,109,122,109,110,113,109,117,122,113,117};
    int codigoActor[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int valorContrato[] = {10000,12000,16000,10000,15000,12400,16000,18000,19000,20000,21000,18500,12900,17500,14500,16500,13500,12500,15200,12500};
    for(i=0; i<tamElencos; i++)
    {
        listadoDeElencos[i].codigoPelicula = codigoPelicula[i];
        listadoDeElencos[i].codigoActor = codigoActor[i];
        listadoDeElencos[i].valorContrato = valorContrato[i];
        listadoDeElencos[i].isEmpty = FALSE;
    }
}
int obtenerLugarDisponibleElenco(eElenco listadoDeElencos[], int tamElencos)
{
    int i;
    int retorno = -1;
    if(tamElencos>0)
    {
        for(i=0; i<tamElencos; i++)
        {
            if(listadoDeElencos[i].isEmpty == TRUE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int agregarUnElenco(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores)
{
    int retorno = -1;
    eElenco auxElenco;
    int codigoPelicula;
    int valorContrato;
    int lugarDisponible;
    char confirmacion;
    char opcion_continuar;

    if(tamElencos>0)
    {
        codigoPelicula = obtenerUnaPelicula(listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros);
        do
        {
            system("pause");
            system("cls");
            lugarDisponible = obtenerLugarDisponibleElenco(listadoDeElencos, tamElencos);
            if(lugarDisponible!= -1)
            {
                valorContrato = getFloat("Ingrese el valor del contrato: ");
                auxElenco = agregarUnActorAElenco(listadoDeElencos, tamElencos, listadoDeActores, tamActores, codigoPelicula, valorContrato);
                printf("\n");
                if(validarSiExiste(listadoDeElencos, tamElencos, auxElenco)== -1)
                {
                    retorno = 1;
                    opcion_continuar = 'n';
                }
                else
                {
                    printf("Estos son los datos ingresados:\n");
                    mostrarUnElenco(auxElenco, listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores);
                    printf("\n");
                    confirmacion = getConfirmacion("Desea cargar los datos? Ingrese s para SI o n para NO:");
                    if(confirmacion == 's')
                    {
                        listadoDeElencos[lugarDisponible] = auxElenco;
                        retorno = 0;
                    }
                    else if(confirmacion == 'n')
                    {
                        retorno = 2;
                    }
                }
                printf("\n");
                opcion_continuar = getConfirmacion("Desea seguir ingresando actores para esta pelicula? Ingrese s para SI o n para NO: ");
                printf("\n");
            }
        }
        while(opcion_continuar == 's');
    }
    return retorno;
}
eElenco agregarUnActorAElenco(eElenco listadoDeElencos[], int tamElencos, eActor listadoDeActores[], int tamActores, int idPelicula, int valorContrato)
{
    eElenco nuevoElenco;
    nuevoElenco.codigoActor = obtenerUnActor(listadoDeActores, tamActores);
    nuevoElenco.codigoPelicula = idPelicula;
    nuevoElenco.valorContrato = valorContrato;
    nuevoElenco.isEmpty = FALSE;

    return nuevoElenco;
}
void mostrarUnElenco(eElenco unElenco, ePelicula listadoDePeliculas[], int tamPelicula, eActor listadoDeActores[], int tamActores)
{
    mostrarPeliculaPorId(listadoDePeliculas, tamPelicula, unElenco.codigoPelicula);
    mostrarActorPorId(listadoDeActores, tamActores, unElenco.codigoActor);
    printf("%25.2f\n", unElenco.valorContrato);
}
void mostrarListaElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores)
{
    int i;
    printf("%20s %30s %25s\n","Pelicula:","Apellido y nombre:","Valor Contrato:");
    for(i=0; i<tamElencos; i++)
    {
        if(listadoDeElencos[i].isEmpty == FALSE)
        {
            mostrarUnElenco(listadoDeElencos[i], listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores);
        }
    }
}
int validarSiExiste(eElenco listadoDeElencos[], int tamElencos, eElenco unElenco)
{
    int retorno = 0;
    int i;
    for(i=0; i<tamElencos; i++)
    {
        if(listadoDeElencos[i].isEmpty == FALSE)
        {
            if(listadoDeElencos[i].codigoPelicula == unElenco.codigoPelicula && listadoDeElencos[i].codigoActor == unElenco.codigoActor)
            {
                retorno = -1;
                break;
            }
        }
    }
    return retorno;
}
int ordenarElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eActor listadoDeActores[], int tamActores)
{
    int i;
    int j;
    int a;

    int retorno = -1;

    eElenco auxElenco;
    ePelicula auxPeliculaUno;
    ePelicula auxPeliculaDos;
    eActor auxActorUno;
    eActor auxActorDos;

    if(tamActores>0 && tamElencos>0 && tamPeliculas>0)
    {
        for(i=0; i<tamElencos-1; i++)
        {
            for(j=i+1; j<tamElencos; j++)
            {
                for(a=0; a<tamPeliculas; a++)
                {
                    if(listadoDeElencos[i].codigoPelicula == listadoDePeliculas[a].codigo && listadoDePeliculas[a].isEmpty == FALSE)
                    {
                        auxPeliculaUno = listadoDePeliculas[a];
                    }
                    else if(listadoDeElencos[j].codigoPelicula == listadoDePeliculas[a].codigo && listadoDePeliculas[a].isEmpty == FALSE)
                    {
                        auxPeliculaDos = listadoDePeliculas[a];
                    }
                }
                for(a=0; a<tamActores; a++)
                {
                    if(listadoDeElencos[i].codigoActor == listadoDeActores[a].codigo && listadoDeActores[a].isEmpty == FALSE)
                    {
                        auxActorUno = listadoDeActores[a];
                    }
                    else if(listadoDeElencos[j].codigoActor == listadoDeActores[a].codigo && listadoDeActores[a].isEmpty == FALSE)
                    {
                        auxActorDos = listadoDeActores[a];
                    }
                }
                if(stricmp(auxPeliculaUno.descripcion, auxPeliculaDos.descripcion)<0)
                {
                    auxElenco = listadoDeElencos[i];
                    listadoDeElencos[i] = listadoDeElencos[j];
                    listadoDeElencos[j] = auxElenco;
                }
                else
                {
                    if(stricmp(auxPeliculaUno.descripcion, auxPeliculaDos.descripcion)== 0)
                    {
                        if(stricmp(auxActorUno.apellido, auxActorDos.apellido)>0)
                        {
                            auxElenco = listadoDeElencos[i];
                            listadoDeElencos[i] = listadoDeElencos[j];
                            listadoDeElencos[j] = auxElenco;
                        }
                    }
                }
                retorno = 0;
            }
        }
    }
    return retorno;
}

