#include "Elenco.h"

void showMenuElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores){
    int option;
    int retorno;
    char option_continue = 'n';
    initElencos(listadoDeElencos, tamElencos);
    do{
        system("cls");
        printf("\t\t\t******* MENU PARA GESTION DE ELENCOS *******\n");
        option = getInt("Opciones:\n1. Altas.\n2. Listado\n3. Salir del menu.\n");
        switch(option){
        case 1:
            retorno = agregarUnElenco(listadoDeElencos,tamElencos, listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeActores, tamActores);
            switch(retorno){
                case 1:
                break;

            }
            printf("\n");
            system("pause");
            break;
        case 2:
            //listarElenco
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
    }while(option_continue=='n');
    printf("\n");
}
int initElencos(eElenco listaDeElencos[], int tamElencos){
    int i;
    int retorno = -1;
    if(tamElencos>0){
        for(i=0; i<tamElencos; i++){
            listaDeElencos[i].isEmpty = TRUE;
            retorno = 0;
        }
    }
    return retorno;
}
int agregarUnElenco(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores){
    int retorno = -1;
    eElenco auxElenco;
    int codigoPelicula;
    int valorContrato;
    int lugarDisponible;
    char confirmacion;
    char opcion_continuar;

    if(tamElencos>0){
        codigoPelicula = obtenerUnaPelicula(listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros);
        do{
            system("pause");
            system("cls");
            lugarDisponible = getIsEmptyElenco(listadoDeElencos, tamElencos);
            if(lugarDisponible!= -1){
                valorContrato = getFloat("Ingrese el valor del contrato: ");
                auxElenco = agregarActoresAElenco(listadoDeElencos, tamElencos, listadoDeActores, tamActores, codigoPelicula, valorContrato);
                printf("\n");
                if(buscarYaExistente(listadoDeElencos, tamElencos));
                printf("Estos son los datos ingresados:\n");
                mostrarUnElenco(auxElenco, listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores);
                printf("\n");
                confirmacion = getConfirmacion("Desea cargar los datos? Ingrese s para SI o n para NO:");
                if(confirmacion == 's'){
                    listadoDeElencos[lugarDisponible] = auxElenco;
                }else if(confirmacion == 'n'){
                    retorno = 2;
                }
                printf("\n");
                opcion_continuar = getConfirmacion("Desea seguir ingresando actores para esta pelicula? Ingrese s para SI o n para NO: ");
                printf("\n");
            }
        }while(opcion_continuar == 's');
    }
    return retorno;
}
int getIsEmptyElenco(eElenco listadoDeElencos[], int tamElencos){
    int i;
    int retorno = -1;
    if(tamElencos>0){
        for(i=0; i<tamElencos; i++){
            if(listadoDeElencos[i].isEmpty == TRUE){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int buscarYaExistente(eElenco listadoDeElencos[],int tamElencos,eActor unActor,ePelicula unaPelicula)
{
    int retorno = 0;
    int i;
    for(i=0; i<tamElencos; i++)
    {
        if(listadoDeElencos[i].isEmpty==FALSE)
        {
            if(listadoDeElencos[i].codigoActor==unActor.codigo && listadoDeElencos[i].codigoPelicula==unaPelicula.codigo)
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}
eElenco agregarActoresAElenco(eElenco listadoDeElencos[], int tamElencos, eActor listadoDeActores[], int tamActores, int idPelicula, int valorContrato){
    eElenco nuevoElenco;
    nuevoElenco.codigoActor = obtenerUnActor(listadoDeActores, tamActores);
    nuevoElenco.codigoPelicula = idPelicula;
    nuevoElenco.valorContrato = valorContrato;
    nuevoElenco.isEmpty = FALSE;

    return nuevoElenco;
}
void mostrarUnElenco(eElenco unElenco, ePelicula listadoDePeliculas[], int tamPelicula, eActor listadoDeActores[], int tamActores){
    mostrarActorPorId(listadoDeActores, tamActores, unElenco.codigoActor);
    mostrarPeliculaPorId(listadoDePeliculas, tamPelicula, unElenco.codigoPelicula);
    printf("%15.2f\n", unElenco.valorContrato);
}
void mostrarListaElenco(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores){
    int i;
    printf("ID del reparto:\tPelicula:\t\tActores:\t\tValor del contrato:");
    for(i=0;i<tamElencos;i++){
        if(listadoDeElencos[i].isEmpty == FALSE){
            mostrarUnElenco(listadoDeElencos[i], listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores);
        }
    }
}

