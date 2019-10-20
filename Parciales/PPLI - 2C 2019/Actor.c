#include "Actor.h"

void mostrarMenuActores(eActor listadoDeActores[], int tamActores, ePelicula listaDePeliculas[], int tamPeliculas)
{
    int option;
    int retorno;
    char option_continue = 'n';
    do
    {
        system("cls");
        printf("******* MENU PARA GESTION DE ACTORES *******\n");
        option = getInt("Opciones:\n1. Altas.\n2. Modificaciones.\n3. Bajas\n4. Listar\n5. Salir del menu.\n");
        switch(option)
        {
        case 1:
            retorno = cargarUnActor(listadoDeActores, tamActores);
            switch(retorno)
            {
            case -1:
                printf("No hay lugar disponible en la lista\n");
                break;
            case 0:
                printf("Se cargo al actor.\n");
                break;
            case 1:
                printf("No se pudo acceder a la opcion para cargar al actor.\n");
                break;
            case 2:
                printf("El usuario cancelo la accion.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 2:
            retorno = modificarUnActor(listadoDeActores, tamActores, listaDePeliculas, tamPeliculas);
            switch(retorno)
            {
            case -1:
                printf("No se encontro al actor\n");
                break;
            case 0:
                printf("El usuario cancelo la accion.\n");
                break;
            case 1:
                printf("Se modifico al actor.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            retorno = eliminarActor(listadoDeActores, tamActores, listaDePeliculas, tamPeliculas);
            switch(retorno)
            {
            case -1:
                printf("No se pudo cargar acceder al menu.\n");
                break;
            case 0:
                printf("Se elimino al actor.\n");
                break;
            case 1:
                printf("No se pudo encontrar al actor.\n");
                break;
            case 2:
                printf("El usuario cancelo la accion.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            retorno = ordenarActores(listadoDeActores, tamActores);
            switch(retorno)
            {
            case -1:
                printf("No se ha podido acceder a la opcion de ordenamiento.\n");
                break;
            case 0:
                printf("Se han ordenado los actores.\n\n");
                mostrarListaDeActores(listadoDeActores, tamActores);
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 5:
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
int inicializarActores(eActor listadoDeActores[], int tamActor)
{
    int i;
    int retorno = -1;
    if(tamActor>0)
    {
        for(i=0; i<tamActor; i++)
        {
            listadoDeActores[i].isEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;
}
int inicializarCodigosActores(eActor listadoDeActores[], int tamActor)
{
    int i;
    int retorno = -1;
    if(tamActor>0)
    {
        for(i=0; i<tamActor; i++)
        {
            listadoDeActores[i].codigo = 0;
            retorno = 0;
        }
    }
    return retorno;
}
void hardcodearActores(eActor listadoDeActores[], int tamActores)
{
    int i;
    int codigo[]= {         1,        2,        3,        4,        5,       31,      6,      7,      8,        9,      10,      11,       12,      13,      14,      15,      16,     17,       18,        19,      20,         21,          22,       23,       24,         25,        26,       27,    28,      29,       30};
    char nombre[][52]= {"Karlen","Pay","Morrie","Lorette","Andre","Daryn","Linnie","Jewis","Herman","Sibylle","Ado","Jessica","Sherline","Laura","Arel","Veronika","Orrin","Costa","Brinna","Mitchael","Glenda","Bernice","Louisette","Henka","Danella","Oliver","Roselin","Karly","Marcelle","Violeta", "Camila"};
    char apellido[][52]= {"Cotton","Hayward","Zarfai","Lowerson","Humes","Swains","Lomas","Patten","Guidelli","Lumbly","Deboy","Wraggs","Marley","Dunbain","Teal","Mikalski","Atwel","Gable","Applewhite","Conway","Chaster","Rosentholer","Coneron","Hacket","Ollarenshaw","Packman","Brinson","Massie","Edney","Barends", "Gomez"};
    char sexo[]= {'f','f','m','m','f','f','f','m','f','m','f','m','f','m','f','m','f','m','f','m','m','m','m','m','f','m','f','f','f','f'};
    for(i=0; i<tamActores; i++)
    {
        listadoDeActores[i].codigo = codigo[i];
        strcpy(listadoDeActores[i].nombre, nombre[i]);
        strcpy(listadoDeActores[i].apellido, apellido[i]);
        listadoDeActores[i].sexo = sexo[i];
        listadoDeActores[i].isEmpty = OCUPADO;
    }
}
void mostrarUnActor(eActor unActor)
{
    printf("%2d", unActor.codigo);
    printf("%29s", unActor.nombre);
    printf("%25s", unActor.apellido);
    printf("%13c\n", unActor.sexo);
}
void mostrarListaDeActores(eActor listadoDeActores[], int tamActores)
{
    int i;
    printf("ID:\t\t\tNombre:\t\t\tApellido:\tSexo:\t\n");
    if(tamActores >= 0){
        for(i=0; i<tamActores; i++)
        {
            if(listadoDeActores[i].isEmpty==OCUPADO)
            {
                mostrarUnActor(listadoDeActores[i]);
            }
        }
    }
}
void mostrarActorPorId(eActor listadoDeActores[], int tamActores, int idActor)
{
    int i;
    for(i=0; i<tamActores; i++)
    {
        if(idActor == listadoDeActores[i].codigo && listadoDeActores[i].isEmpty == OCUPADO)
        {
            printf("%19s, %10s", listadoDeActores[i].apellido, listadoDeActores[i].nombre);
            break;
        }
    }

}
int cargarUnActor(eActor listadoDeActores[], int tamActores)
{
    int retorno = 1;
    char name[52];
    char lastName[52];
    char sexo;
    int codigo;
    char confirmacion;
    char opcion_continuar;

    if(tamActores>=0)
    {
        do
        {
            obtenerDatosActor(name, lastName, &sexo);
            printf("\n");
            printf("Estos son los datos ingresados:\n");
            mostrarDatosActor(name, lastName, sexo);
            printf("\n");
            confirmacion = getConfirmacion("Desea cargar los datos? Ingrese s para SI o n para NO: \n");
            if(confirmacion == 's')
            {
                codigo = obtenerNuevoCodigo(listadoDeActores, tamActores);
                retorno = agregarActor(listadoDeActores, tamActores, codigo, name, lastName, sexo);
            }
            else if(confirmacion == 'n')
            {
                retorno = 2;
            }
            printf("\n");
            opcion_continuar = getConfirmacion("Desea ingresar otro actor? Ingrese s para SI o n para NO: ");
            printf("\n");
        }
        while(opcion_continuar == 's');
    }
    return retorno;
}
void obtenerDatosActor(char name[],char lastName[], char* sexo)
{
    printf("Ingrese los datos del actor: ");
    pedirCadena("\nNombre del actor: ", name);
    pedirCadena("\nApellido del actor: ", lastName);
    *sexo = getSexo("\nSexo del actor (f/m): ");
}
void mostrarDatosActor(char name[],char lastName[], char sexo)
{
    printf("\n");
    printf("Nombre: %s\n", name);
    printf("Apellido %s\n", lastName);
    printf("Sexo: %c\n", sexo);
}
int agregarActor(eActor listadoDeActores[], int tamActores, int codigo, char name[],char lastName[], char sexo)
{
    int retorno = -1;
    int lugar_Disponible = obtenerLugarDisponibleActor(listadoDeActores, tamActores);
    if(lugar_Disponible!= -1)
    {
        listadoDeActores[lugar_Disponible].codigo = codigo;
        strcpy(listadoDeActores[lugar_Disponible].nombre, name);
        strcpy(listadoDeActores[lugar_Disponible].apellido, lastName);
        listadoDeActores[lugar_Disponible].sexo = sexo;
        listadoDeActores[lugar_Disponible].isEmpty = OCUPADO;
        retorno = 0;
    }
    return retorno;
}
int obtenerNuevoCodigo(eActor listadoDeActores[], int tamActores)
{
    int retorno = -1;
    int flag = 0;
    int newId;
    if(tamActores>=0)
    {
        int i;
        for(i=0; i<tamActores; i++)
        {
            if(flag == 0 || listadoDeActores[i].codigo>newId)
            {
                newId = listadoDeActores[i].codigo;
                flag = 1;
            }
        }
        retorno = newId++;
    }
    return retorno;
}
int obtenerLugarDisponibleActor(eActor listadoDeActores[], int tamActores)
{
    int i;
    int retorno = -1;

    if(tamActores>=0)
    {
        for(i=0; i<tamActores; i++)
        {
            if(listadoDeActores[i].isEmpty == VACIO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int modificarUnActor(eActor listadoDeActores[], int tamActores, ePelicula listadoDePeliculas[], int tamPeliculas)
{
    int retorno = -1;
    int flag = -1;
    int codigo;
    int indice;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';
    eActor aux;

    mostrarListaDeActores(listadoDeActores, tamActores);

    codigo = getInt("\nIngrese el id del actor a modificar:");
    indice = encontrarActorPorCodigo(listadoDeActores, tamActores, codigo);

    if(indice != -1)
    {
        aux = listadoDeActores[indice];
        do
        {
            system("cls");
            opcion = getInt("Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar apellido.\n3. Cambiar sexo.\n4. Salir al menu principal.\n");
            switch(opcion)
            {
            case 1:
                pedirCadena("Ingrese un nombre: ", aux.nombre);
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                flag = 0;
                printf("\n");
                system("pause");
                break;
            case 2:
                pedirCadena("Ingrese un apellido: ", aux.apellido);
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO:");
                flag = 0;
                printf("\n");
                system("pause");
                break;
            case 3:
                aux.sexo = getSexo("Ingrese el sexo nuevo:");
                confirmacion = getConfirmacion("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                flag = 0;
                printf("\n");
                system("pause");
                break;
            case 4:
                confirmacion='n';
                printf("\n");
                //system("pause");
                break;
            default:
                printf("Ingreso una opcion incorrecta.\n");
                printf("\n");
                system("pause");
                break;
            }
        }
        while(confirmacion == 's');

        if(flag != -1)
        {
            printf("Este es el actor:\n");
            printf("\n");
            mostrarUnActor(aux);
            printf("\n");
            cargar = getConfirmacion("\nDesea guardar estos datos? Ingrese s para SI o n para NO:");
            if(cargar == 's')
            {
                listadoDeActores[indice]=aux;
                retorno = 1;
            }
            else
            {
                retorno = 0;
            }
        }else{
            retorno = 0;

        }

    }return retorno;
}
int encontrarActorPorCodigo(eActor listadoDeActores[], int tamActores,int codigo)
{
    int retorno = -1;
    int i;
    if(tamActores>0)
    {
        for(i=0; i<tamActores; i++)
        {
            if(listadoDeActores[i].codigo == codigo && listadoDeActores[i].isEmpty == OCUPADO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int eliminarActor(eActor listadoDeActores[], int tamActores, ePelicula listaDePeliculas[], int tamPeliculas)
{
    int retorno = -1;
    int id = 0;
    int index = 0;
    char confirmacion;
    if(tamActores>0)
    {
        printf("Estos son los actores:\n");
        mostrarListaDeActores(listadoDeActores, tamActores);
        id = getInt("\nIngrese el codigo del actor que desea dar de baja:");
        printf("\n");
        index = encontrarActorPorCodigo(listadoDeActores, tamActores, id);
        if(index == -1)
        {
            retorno = 1;
        }
        else
        {
            mostrarUnActor(listadoDeActores[index]);
            confirmacion = getChar("\nEsta seguro que quiere eliminar al actor? Ingrese s para SI o n para NO:");
            if(confirmacion == 's')
            {
                retorno = darBajaActor(listadoDeActores, tamActores, id);
            }
            else if(confirmacion == 'n')
            {
                retorno = 2;
            }
        }
    }
    return retorno;
}
int darBajaActor(eActor listadoDeActores[], int tamActores, int id)
{
    int retorno = -1;
    int i;
    if(tamActores>0)
    {
        for(i=0; i<tamActores; i++)
        {
            if(listadoDeActores[i].isEmpty == OCUPADO)
            {
                if(listadoDeActores[i].codigo == id)
                {
                    listadoDeActores[i].isEmpty = VACIO;
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
int ordenarActores(eActor listadoDeActores[], int tamActores)
{
    int i;
    int j;
    int retorno = -1;
    eActor auxActor;

    if(tamActores>=0)
    {
        for(i=0; i<tamActores-1; i++)
        {
            for(j=i+1; j<tamActores; j++)
            {
                if(stricmp(listadoDeActores[i].apellido,listadoDeActores[j].apellido)>0)
                {
                    auxActor = listadoDeActores[i];
                    listadoDeActores[i] = listadoDeActores[j]; //dentro del mismo sector, organizo por apellido.
                    listadoDeActores[j] = auxActor;
                }
                else if(stricmp(listadoDeActores[i].apellido,listadoDeActores[j].apellido)==0)
                {
                    if(stricmp(listadoDeActores[i].nombre,listadoDeActores[j].nombre)>0)
                    {
                        auxActor = listadoDeActores[i];
                        listadoDeActores[i] = listadoDeActores[j]; //dentro del mismo sector, organizo por apellido.
                        listadoDeActores[j] = auxActor;
                    }
                }
                retorno = 0;
            }
        }
    }
    return retorno;
}
int obtenerIdActor(eActor listadoDeActores[], int tamActores)
{
    int idActor;
    mostrarListaDeActores(listadoDeActores, tamActores);
    idActor = getInt("Ingrese el codigo del actor: \n");
    while((validarIdActor(listadoDeActores, tamActores, idActor)== -1))
    {
        idActor = getInt("El codigo de actor es invalido. Reingrese: ");
        printf("\n");
    }
    return idActor;
}
int validarIdActor(eActor listadoDeActores[], int tamActores, int idActor)
{
    int i;
    int retorno = -1;
    for(i=0; i<tamActores; i++)
    {
        if(idActor == listadoDeActores[i].codigo && listadoDeActores[i].isEmpty == OCUPADO)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
eActor obtenerActor(eActor listadoDeActores[],int tamActor,int codigo)
{
    eActor retorno;
    int i;
    if(tamActor>=0 && codigo>=0)
    {
        for(i=0; i<tamActor; i++)
        {
            if(listadoDeActores[i].codigo == codigo && listadoDeActores[i].isEmpty == OCUPADO)
            {
                retorno=listadoDeActores[i];
                break;
            }
        }
    }
    return retorno;
}
int validarSiExisteActor(eActor listadoDeActores[], int tamActores, int codigoActor)
{
    int retorno = -1;
    eActor auxActor;
    if(tamActores>=0)
    {
        auxActor = obtenerActor(listadoDeActores, tamActores, codigoActor);
        if(auxActor.isEmpty == OCUPADO)
        {
            retorno = 0;
        }
    }
    return retorno;
}
