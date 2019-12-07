#include "Elenco.h"

void mostrarMenuElencos(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores, eFecha listadoDeFechas[], int tamFechas, ePais listadoDePaises[], int tamPaises)
{
    int option;
    int retorno;
    char option_continue = 'n';
    do
    {
        system("cls");
        printf("\t\t\t******* MENU PARA GESTION DE ELENCOS *******\n");
        option = getInt("Opciones:\n1. Altas.\n2. Listado\n3. Salir del menu.\n");
        switch(option)
        {
        case 1:
            retorno = agregarUnElenco(listadoDeElencos,tamElencos, listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeActores, tamActores, listadoDeFechas, tamFechas, listadoDePaises, tamPaises);
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
            retorno = ordenarElencos(listadoDeElencos,tamElencos,listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores);
            switch(retorno)
            {
            case -1:
                printf("No se ha podido acceder a la opcion de ordenamiento y listar.\n");
            case 0:
                printf("Se ha realizado el ordenamiento de los elencos:\n");
                mostrarListaElencos(listadoDeElencos,tamElencos, listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeActores, tamActores);
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            option_continue = getConfirmacion("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
            printf("\n");
            //system("pause");
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
void mostrarMenus(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores, eFecha listadoDeFechas[], int tamFechas, ePais listadoDePaises[], int tamPaises)
{
    int option;
    char option_continue = 'n';

    inicializarActores(listadoDeActores, tamActores);
    inicializarCodigosActores(listadoDeActores, tamActores);
    inicializarElencos(listadoDeElencos, tamElencos);

    hardcodearPeliculas(listadoDePeliculas, 20);
    hardcodearGeneros(listadoDeGeneros, tamGeneros);
    hardcodearActores(listadoDeActores, 30);
    hardcodearElencos(listadoDeElencos, 20);
    hardcodearFechas(listadoDeFechas, 20);
    hardcodearPaises(listadoDePaises, 5);

    do
    {
        system("cls");
        printf("\t\t\t******* MENU PARA GESTION DE ELENCOS Y ACTORES *******\n");
        option = getInt("Opciones:\n1. Gestion de actores.\n2. Gestion de elencos.\n3. Informes.\n4. Salir del programa.\n");
        switch(option)
        {
        case 1:
            mostrarMenuActores(listadoDeActores, tamActores, listadoDePeliculas, tamPeliculas, listadoDePaises, tamPaises);
            printf("\n");
            system("pause");
            break;
        case 2:
            mostrarMenuElencos(listadoDeElencos, tamElencos, listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeActores, tamActores, listadoDeFechas, tamFechas, listadoDePaises, tamPaises);
            printf("\n");
            system("pause");
            break;
        case 3:
            mostrarMenuInformes(listadoDeElencos, tamElencos, listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeActores, tamActores, listadoDeFechas, tamFechas, listadoDePaises, tamPaises);
            break;
        case 4:
            option_continue = getConfirmacion("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
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
void mostrarMenuInformes(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores, eFecha listadoDeFechas[], int tamFechas, ePais listadoDePaises[], int tamPaises)
{
    int option;
    int retorno;
    char option_continue = 'n';
    do
    {
        system("cls");
        printf("\t\t\t******* MENU DE INFORMES *******\n");
        option = getInt("Opciones:\n1. Mostrar peliculas de terror estrenadas despues del 2002.\n2. Mostrar peliculas donde haya participado un actor argentino.\n3. Mostrar peliculas donde participo un actor seleccionado.\n4. Seleccionar un actor y determinar cuando recaudo en todas las peliculas romanticas en las que participo.\n5. Listar actores que no participaron en ninguna pelicula.\n6. Peliculas en las que participa un actor de avellaneda.\n7. Actores mayores a 30 y con al menos un premio.\n8. Seleccionar un elenco y mostrar total de premios entre todos sus actores.\n9. Listar actores y mostrar la edad de cada uno.\n10. Salir del menu de informes.\n");
        switch(option)
        {
        case 1:
            retorno = listarPeliculasDeTerrorEstrenadasPos2002(listadoDeFechas, tamFechas, listadoDeGeneros, tamGeneros, listadoDePeliculas, tamPeliculas);
            switch(retorno)
            {
            case -1:
                printf("No hay peliculas para mostrar.\n");
                break;
            case 0:
                printf("Se han listado todas las peliculas.\n");
            }
            printf("\n");
            system("pause");
            break;
        case 2:
            retorno = mostrarPeliculasConActorArgentino(listadoDeElencos, tamElencos, listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores, listadoDePaises, tamPaises);
            switch(retorno)
            {
            case -1:
                printf("No se han encontrado actores argentinos que trabajen en las peliculas disponibles.\n");
                break;
            case 0:
                printf("Se han listado todos los actores argentinos que trabajan en las peliculas disponibles.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            retorno = mostrarPeliculasDelActorSeleccionado(listadoDeElencos, tamElencos, listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores, listadoDePaises, tamPaises, listadoDeGeneros, tamGeneros, listadoDeFechas, tamFechas);
            switch(retorno)
            {
            case -1:
                printf("El actor seleccionado no trabaja en ninguna de las peliculas disponibles.\n");
                break;
            case 0:
                printf("Se han listado todas las peliculas en las que trabaja el actor seleccionado.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            retorno = mostrarTotalGananciasDeActorRomance(listadoDeElencos, tamElencos, listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores,listadoDeGeneros, tamGeneros, listadoDePaises, tamPaises);
            switch(retorno)
            {
            case -1:
                printf("El actor no ha obtenido ganancias en ninguna pelicula romantica.\n");
                break;
            case 0:
                printf("Se han mostrado el total de ganancias del actor seleccionado.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 5:
            retorno = mostrarSiNoActua(listadoDeActores, tamActores, listadoDeElencos, tamElencos, listadoDePaises, tamPaises);
            switch(retorno)
            {
            case -1:
                printf("No hay actores que no trabajen en las peliculas disponibles.\n");
                break;
            case 0:
                printf("Se han mostrado todos los actores que no trabajan en ninguna pelicula.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
            case 6:
                mostrarPeliculasConActoresDeAvellaneda(listadoDeElencos, tamElencos, listadoDePeliculas, tamPeliculas, listadoDeActores, tamActores);
                printf("\n");
                system("pause");
                break;
            case 7:
                mostrarActoresMayoresA30YConAlMenosUnPremio(listadoDeActores, tamActores);
                printf("\n");
                system("pause");
                break;
            case 8:
                mostrarCantidadDePremiosEnUnElenco(listadoDeGeneros, tamGeneros, listadoDeFechas, tamFechas, listadoDeElencos, tamElencos,listadoDeActores, tamActores, listadoDePeliculas, tamPeliculas);
                printf("\n");
                system("pause");
                break;
            case 9:
                mostrarEdadDeCadaActor(listadoDeActores, tamActores);
                printf("\n");
                system("pause");
                break;
        case 10:
            option_continue = getConfirmacion("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
            printf("\n");
            //system("pause");
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
/**Sexto filtro*/
void mostrarPeliculasConActoresDeAvellaneda(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores)
{
    eActor unActor;
    ePelicula unaPelicula;
    int i;

    for(i=0; i<tamElencos; i++)
    {
        if(listaDeElencos[i].isEmpty == OCUPADO)
        {
            //obtengo todo los datos que necesito
            unaPelicula = obtenerPelicula(listaDePeliculas, tamPeliculas, listaDeElencos[i].codigoPelicula);//guardo la pelicula de ese elenco
            unActor = obtenerActor(listaDeActores, tamActores, listaDeElencos[i].codigoActor);//obtengo el actor de ese elenco

            if(stricmp(unActor.unaDireccion.localidad,"Avellaneda")== 0)
            {
                printf("%s:\n", unaPelicula.descripcion);
                printf("%10s %10s\n", "Nombre del actor: ", "Apellido del actor: ");
                printf("%17s %19s\n", unActor.nombre, unActor.apellido);
                printf("\n");
            }
        }
    }
    //return isEmpty;
}
/**7 filtro*/
void mostrarActoresMayoresA30YConAlMenosUnPremio(eActor listadoDeActores[], int tamActores)
{
    int i;
    int edadTotal;
    int anio;

    anio = getInt("Ingrese el anio actual:");
    printf("Actores con edad mayor a 30 y con mas de un premio: \n");
    for(i=0;i<tamActores;i++)
    {
        if(listadoDeActores[i].isEmpty == OCUPADO)
        {

            edadTotal = anio - listadoDeActores[i].fechaNacimiento.anio;

            if(edadTotal>30 && listadoDeActores[i].cantidadPremios>=1)
            {
                printf("%10s %10s %18s %25s\n", "Nombre del actor: ", "Apellido del actor: ", "Edad: ", "Cantidad De Premios: ");
                printf("%17s %19s %20d %20d\n", listadoDeActores[i].nombre, listadoDeActores[i].apellido, edadTotal, listadoDeActores[i].cantidadPremios);
                printf("\n\n");
            }
        }
    }
}
/**octavo*/
void mostrarCantidadDePremiosEnUnElenco(eGenero listaDeGeneros[], int tamGeneros, eFecha listaDeFechas[], int tamFechas, eElenco listadoDeElencos[], int tamElencos, eActor listadoDeActores[], int tamActores, ePelicula listadoDePeliculas[], int tamPeliculas)
{
    int i;
    int j;
    int idPelicula;
    int totalPremios = 0;
    ePelicula unaPelicula;

    mostrarListaPeliculas(listadoDePeliculas, tamPeliculas, listaDeGeneros, tamGeneros, listaDeFechas, tamFechas);
    idPelicula = obtenerIdPelicula(listadoDePeliculas, tamPeliculas, listaDeGeneros, tamGeneros, listaDeFechas, tamFechas);

    unaPelicula = obtenerPelicula(listadoDePeliculas, tamPeliculas, idPelicula);//ya tengo la pelicula para calcular el elenco

    for(i=0;i<tamElencos;i++)
    {
        if(listadoDeElencos[i].codigoPelicula == unaPelicula.codigo && listadoDeElencos[i].isEmpty == OCUPADO)//ya tengo el elenco
        {
            for(j=0;j<tamActores;j++)
            {
                if((listadoDeElencos[i].codigoActor == listadoDeActores[j].codigo) && (listadoDeActores[j].isEmpty == OCUPADO))
                {
                    totalPremios = totalPremios + listadoDeActores[j].cantidadPremios;
                }
            }
        }
    }
    printf("El total de premios del elenco de la pelicula %s es: %d", unaPelicula.descripcion, totalPremios);
}
/**noveno*/
void mostrarEdadDeCadaActor(eActor listadoDeActores[], int tamActores)
{
    int i;
    int edadTotal;
    int anio;

    anio = getInt("Ingrese el anio actual:");
    printf("Los actores y sus edades son: \n\n\n");
    for(i=0;i<tamActores;i++)
    {
        if(listadoDeActores[i].isEmpty == OCUPADO)
        {
            edadTotal = anio - listadoDeActores[i].fechaNacimiento.anio;
            printf("%10s %10s %18s\n", "Nombre del actor: ", "Apellido del actor: ", "Edad: ");
            printf("%17s %19s %20d\n", listadoDeActores[i].nombre, listadoDeActores[i].apellido, edadTotal);
            printf("\n\n");
        }
    }
}

/**PRIMER FILTRO*/
int listarPeliculasDeTerrorEstrenadasPos2002(eFecha listaDeFechas[], int tamFechas, eGenero listaDeGeneros[], int tamGeneros, ePelicula listaDePeliculas[], int tamPeliculas)
{
    int retorno;

    retorno = encontrarPeliculasDeTerrorEstrenadasPos2002(listaDeFechas, tamFechas, listaDeGeneros, tamGeneros, listaDePeliculas, tamPeliculas);

    if(retorno != -1)
    {
        printf("\n");
        printf("Estas son las peliculas de terror estrenadas posterior a 2002: \n");
        printf("\n");
        printf("Codigo:\t\t\tDescripcion:\tDuracion (minutos) :\tGenero:\t Fecha de Estreno:\n");
        printf("\n");
        mostrarPeliculasDeTerrorEstrenadasPos2002(listaDeFechas, tamFechas, listaDeGeneros, tamGeneros, listaDePeliculas, tamPeliculas);
    }

    return retorno;/**retorna -1 si no hay ninguna pelicula para mostrar, de otra manera retorna 0*/
}

void mostrarPeliculasDeTerrorEstrenadasPos2002(eFecha listaDeFechas[], int tamFechas, eGenero listaDeGeneros[], int tamGeneros, ePelicula listaDePeliculas[], int tamPeliculas)
{
    int i;
    ePelicula auxPelicula;
    eFecha auxFecha;
    eGenero auxGenero;

    auxGenero = obtenerUnGeneroPorId(listaDeGeneros, tamGeneros, 2);//obtengo el genero de terror con el id para comparar con el idGenero de Pelicula

    for(i=0; i<tamPeliculas; i++)
    {
        auxPelicula = obtenerPelicula(listaDePeliculas, tamPeliculas, listaDePeliculas[i].codigo);//obtengo la pelicula
        auxFecha = obtenerFechaPorIndice(listaDeFechas, tamFechas, i);//obtengo la fecha

        if(auxPelicula.idGenero == auxGenero.id && auxFecha.anio>2002)//realizo las validaciones necesarias
        {
            mostrarPelicula(listaDePeliculas, tamPeliculas, listaDePeliculas[i],listaDeGeneros,tamGeneros,listaDeFechas,tamFechas);
        }
    }
}

int encontrarPeliculasDeTerrorEstrenadasPos2002(eFecha listaDeFechas[], int tamFechas, eGenero listaDeGeneros[], int tamGeneros, ePelicula listaDePeliculas[], int tamPeliculas)
{
    int i;
    int isEmpty = -1;
    ePelicula auxPelicula;
    eFecha auxFecha;
    eGenero auxGenero;

    auxGenero = obtenerUnGeneroPorId(listaDeGeneros, tamGeneros, 2);//obtengo el genero de terror con el id para comparar con el idGenero de Pelicula

    for(i=0; i<tamPeliculas; i++)
    {
        auxPelicula = obtenerPelicula(listaDePeliculas, tamPeliculas, listaDePeliculas[i].codigo);//obtengo la pelicula
        auxFecha = obtenerFechaPorIndice(listaDeFechas, tamFechas, i);//obtengo la fecha

        if(auxPelicula.idGenero == auxGenero.id && auxFecha.anio>2002)//realizo las validaciones necesarias
        {
            isEmpty = 0;//para chequear que al menos se muestre una.
        }
    }

    return isEmpty;
}
/**SEGUNDO FILTRO*/
int mostrarPeliculasConActorArgentino(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores, ePais listaDePaises[], int tamPais)
{
    ePais unPais;
    eActor unActor;
    ePelicula unaPelicula;
    int i;
    int isEmpty = -1;

    unPais = obtenerUnPaisPorId(listaDePaises, tamPais, 1);//obtengo argentina

    for(i=0; i<tamElencos; i++)
    {
        if(listaDeElencos[i].isEmpty == OCUPADO)
        {
            //obtengo todo los datos que necesito
            unaPelicula = obtenerPelicula(listaDePeliculas, tamPeliculas, listaDeElencos[i].codigoPelicula);//guardo la pelicula de ese elenco
            unActor = obtenerActor(listaDeActores, tamActores, listaDeElencos[i].codigoActor);//obtengo el actor de ese elenco

            if(unActor.idNacionalidad == unPais.id)
            {
                isEmpty = 0;
                printf("%s:\n", unaPelicula.descripcion);
                printf("%10s %10s\n", "Nombre del actor: ", "Apellido del actor: ");
                printf("%17s %19s\n", unActor.nombre, unActor.apellido);
                printf("\n");
            }
        }
    }
    return isEmpty;
}
/**TERCER FILTRO*/
int mostrarPeliculasDelActorSeleccionado(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores, ePais listaDePaises[], int tamPais, eGenero listaDeGeneros[], int tamGeneros, eFecha listaDeFechas[], int tamFechas)
{
    ePelicula unaPelicula;
    eElenco unElenco;
    int i;
    int id;
    int isEmpty = -1;

    id = obtenerIdActor(listaDeActores,tamActores,listaDePaises, tamPais);//obtengo el actor
    printf("\n");
    printf("El actor seleccionado es: \n");
    mostrarActorPorId(listaDeActores, tamActores, id);
    printf("\n");
    printf("\n");

    for(i=0; i<tamElencos; i++)
    {
        if(listaDeElencos[i].isEmpty == OCUPADO)
        {
            //obtengo todo los datos que necesito
            unElenco = obtenerElencoPorIndice(listaDeElencos, tamElencos, i);//obtengo el primer elenco
            if(unElenco.codigoActor == id)
            {
                isEmpty = 0;
                unaPelicula = obtenerPelicula(listaDePeliculas, tamPeliculas, listaDeElencos[i].codigoPelicula);//guardo la pelicula de ese elenco
                printf("Codigo:\t\t\tDescripcion:\tDuracion (minutos) :\tGenero:\t Fecha de Estreno:\n");
                mostrarPelicula(listaDePeliculas, tamPeliculas, unaPelicula, listaDeGeneros, tamGeneros, listaDeFechas, tamFechas);
            }
        }
    }
    return isEmpty;
}
/**CUARTO FILTRO*/
float calcularTotalContratoEnRomanticasActorSeleccionado(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores, eGenero listaDeGeneros[], int tamGeneros, ePais listaDePaises[], int tamPaises)
{
    int i;
    eActor auxActor;
    eGenero auxGenero;
    ePelicula auxPelicula;
    int idActor;
    float totalGanancias = 0;

    idActor = obtenerIdActor(listaDeActores,tamActores,listaDePaises,tamPaises);
    auxActor = obtenerActor(listaDeActores,tamActores,idActor);

    printf("El actor seleccionado es: \n");
    printf("\n");
    printf("ID:\t\t\tNombre:\t\t\tApellido:\tSexo:\tPais De Origen:\n");
    mostrarUnActor(auxActor, listaDePaises, tamPaises);
    printf("\n");

    for(i=0; i<tamElencos; i++) //entro el array de elencos
    {
        if(listaDeElencos[i].isEmpty == OCUPADO)//me fijo que este ocupado
        {
            if(auxActor.codigo == listaDeElencos[i].codigoActor)//si el actor es el mismo que el del elenco
            {
                auxGenero = obtenerUnGeneroPorId(listaDeGeneros,tamGeneros,3);//obtengo el genero romance
                auxPelicula = obtenerPelicula(listaDePeliculas,tamPeliculas,listaDeElencos[i].codigoPelicula);//obtengo la pelicula de ese elenco

                if(auxPelicula.idGenero == auxGenero.id)//si la pelicula en la que trabajo el actor es del genero romance
                {
                    totalGanancias = listaDeElencos[i].valorContrato + totalGanancias;
                }
            }
        }
    }

    return totalGanancias;
}

int mostrarTotalGananciasDeActorRomance(eElenco listaDeElencos[], int tamElencos, ePelicula listaDePeliculas[], int tamPeliculas, eActor listaDeActores[], int tamActores, eGenero listaDeGeneros[], int tamGeneros,ePais listaDePaises[], int tamPaises)
{
    int retorno = -1;
    float totalGanancias;

    totalGanancias = calcularTotalContratoEnRomanticasActorSeleccionado(listaDeElencos, tamElencos, listaDePeliculas, tamPeliculas, listaDeActores, tamActores, listaDeGeneros, tamGeneros,listaDePaises, tamPaises);

    if(totalGanancias != 0)
    {
        printf("El total de las ganancias del actor con las peliculas romanticas es: %.2f\n\n", totalGanancias);
        retorno = 0;
    }

    return retorno;
}

/**QUINTO FILTRO*/
int mostrarSiNoActua(eActor listaDeActores[], int tamActores, eElenco listaDeElencos[], int tamElencos, ePais listaDePaises[], int tamPaises)
{
    int i;
    int noActua;
    int retorno = -1;

    printf("Listado de actores que no trabajan en ninguna pelicula: \n");
    printf("Nombre:\t\t\tApellido:\t\n");
    printf("\n\n");

    for(i=0; i<tamActores; i++) //comienzo con el array de actores
    {
        if(listaDeActores[i].isEmpty == OCUPADO)
        {
            noActua = buscarSiActua(listaDeActores[i], listaDeElencos, tamElencos);//me fijo si actua o no ese actor
            if(noActua != -1)
            {
                retorno = 0;
                printf("%17s", listaDeActores[i].nombre);// si no actua lo muestro
                printf("%25s\n", listaDeActores[i].apellido);
            }
        }
    }
    return retorno;
}

int buscarSiActua(eActor unActor, eElenco listaDeElencos[], int tamElencos)
{
    int i;
    int retorno = 0;

    for(i=0; i<tamElencos; i++) //recorro el array de elencos
    {
        if(listaDeElencos[i].isEmpty == OCUPADO && unActor.isEmpty == OCUPADO)//siempre pregunto que este ocupado
        {
            if(listaDeElencos[i].codigoActor == unActor.codigo)//si el actor trabaja en ese elenco -1
            {
                retorno = -1;//retorna 1- poruqe encontro una incidencia
                break;
            }
        }
    }

    return retorno;
}

eElenco obtenerElencoPorIndice(eElenco listaDeElencos[], int tamElencos, int indice)
{
    int i;
    eElenco unElenco;
    for(i=0; i<tamElencos; i++)
    {
        if(i == indice)
        {
            unElenco = listaDeElencos[i];
            break;
        }
    }
    return unElenco;
}

int inicializarElencos(eElenco listaDeElencos[], int tamElencos)
{
    int i;
    int retorno = -1;
    if(tamElencos>0)
    {
        for(i=0; i<tamElencos; i++)
        {
            listaDeElencos[i].isEmpty = VACIO;
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
        listadoDeElencos[i].isEmpty = OCUPADO;
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
            if(listadoDeElencos[i].isEmpty == VACIO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int agregarUnElenco(eElenco listadoDeElencos[], int tamElencos, ePelicula listadoDePeliculas[], int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eActor listadoDeActores[], int tamActores, eFecha listadoDeFechas[], int tamFechas, ePais listadoDePaises[], int tamPaises)
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
        codigoPelicula = obtenerIdPelicula(listadoDePeliculas, tamPeliculas, listadoDeGeneros, tamGeneros, listadoDeFechas, tamFechas);
        do
        {
            system("pause");
            system("cls");
            lugarDisponible = obtenerLugarDisponibleElenco(listadoDeElencos, tamElencos);
            if(lugarDisponible!= -1)
            {
                valorContrato = getFloat("Ingrese el valor del contrato: ");
                auxElenco = agregarUnActorAElenco(listadoDeElencos, tamElencos, listadoDeActores, tamActores, codigoPelicula, valorContrato, listadoDePaises, tamPaises);
                printf("\n");
                if(validarSiExiste(listadoDeElencos, tamElencos, auxElenco)== -1)
                {
                    retorno = 1;
                    opcion_continuar = 'n';
                }
                else
                {
                    printf("Estos son los datos ingresados:\n");
                    printf("%20s %30s %25s\n","Pelicula:","Apellido y nombre:","Valor Contrato:");
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
eElenco agregarUnActorAElenco(eElenco listadoDeElencos[], int tamElencos, eActor listadoDeActores[], int tamActores, int idPelicula, int valorContrato, ePais listadoDePaises[], int tamPaises)
{
    eElenco nuevoElenco;
    nuevoElenco.codigoActor = obtenerIdActor(listadoDeActores, tamActores, listadoDePaises, tamPaises);
    nuevoElenco.codigoPelicula = idPelicula;
    nuevoElenco.valorContrato = valorContrato;
    nuevoElenco.isEmpty = OCUPADO;

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
        if(listadoDeElencos[i].isEmpty == OCUPADO && validarSiExisteActor(listadoDeActores, tamActores, listadoDeElencos[i].codigoActor) != -1)
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
        if(listadoDeElencos[i].isEmpty == OCUPADO)
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
    int retorno = -1;

    eElenco auxElenco;
    ePelicula auxPelicula;
    ePelicula auxPelicula2;
    eActor auxActor;
    eActor auxActor2;

    for(i=0; i<tamElencos-1; i++)
    {
        for(j=i+1; j<tamElencos; j++)
        {
            auxPelicula = obtenerPelicula(listadoDePeliculas,tamPeliculas,listadoDeElencos[i].codigoPelicula);
            auxPelicula2 = obtenerPelicula(listadoDePeliculas,tamPeliculas,listadoDeElencos[j].codigoPelicula);
            if(stricmp(auxPelicula.descripcion,auxPelicula2.descripcion)>0)
            {
                auxElenco = listadoDeElencos[i];
                listadoDeElencos[i] = listadoDeElencos[j];
                listadoDeElencos[j] = auxElenco;
            }
            else
            {
                if(stricmp(auxPelicula.descripcion,auxPelicula2.descripcion)==0)
                {
                    auxActor = obtenerActor(listadoDeActores,tamActores,listadoDeElencos[i].codigoActor);
                    auxActor2 = obtenerActor(listadoDeActores,tamActores,listadoDeElencos[j].codigoActor);
                    if(stricmp(auxActor.apellido,auxActor2.apellido)>0)
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
    return retorno;
}

