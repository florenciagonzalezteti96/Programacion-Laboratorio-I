#include "Pelicula.h"

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
    }
}
int obtenerIndicePelicula(ePelicula listadoDePeliculas[], int tamPeliculas, int idPelicula)
{
    int i;
    int retorno = -1;
    for(i=0;i<tamPeliculas;i++){
        if(idPelicula == listadoDePeliculas[i].codigo){
            retorno = i;
            break;
        }
    }
    return retorno;

}
void mostrarPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, ePelicula unaPelicula, eGenero listadoDeGeneros[],int tamGeneros, eFecha listadoDeFechas[], int tamFechas)
{
    int indicePelicula = obtenerIndicePelicula(listadoDePeliculas, tamPeliculas, unaPelicula.codigo);
    printf("%7d", unaPelicula.codigo);
    printf("%28s", unaPelicula.descripcion);
    printf("%24d", unaPelicula.duracion);
    mostrarGeneroPorId(listadoDeGeneros, tamGeneros, unaPelicula.idGenero);
    mostrarUnaFecha(listadoDeFechas[indicePelicula]);
    printf("\n");
}
void mostrarListaPeliculas(ePelicula listadoDePeliculas[],int tamPeliculas,eGenero listadoDeGeneros[],int tamGeneros, eFecha listadoDeFechas[], int tamFechas)
{
    printf("Codigo:\t\t\tDescripcion:\tDuracion (minutos) :\tGenero:\t Fecha de Estreno:\n");
    int i;
    for(i=0; i<tamPeliculas; i++)
    {
        mostrarPelicula(listadoDePeliculas, tamPeliculas, listadoDePeliculas[i], listadoDeGeneros, tamGeneros, listadoDeFechas, tamFechas);
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
int obtenerIdPelicula(ePelicula listadoDePeliculas[],int tamPeliculas, eGenero listadoDeGeneros[], int tamGeneros, eFecha listadoDeFechas[], int tamFechas)
{
    int idPelicula;
    mostrarListaPeliculas(listadoDePeliculas,tamPeliculas,listadoDeGeneros, tamGeneros, listadoDeFechas, tamFechas);
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
int mostrarPeliculaPorId(ePelicula listadoDePeliculas[], int tamPeliculas, int idPelicula)
{
    int retorno = -1;
    int indicePelicula = buscarIndicePelicula(listadoDePeliculas, tamPeliculas, idPelicula);
    if(indicePelicula != -1)
    {
        printf("%20s", listadoDePeliculas[indicePelicula].descripcion);
        retorno = 0;
    }
    return retorno;
}
ePelicula obtenerPelicula(ePelicula listadoDePeliculas[], int tamPeliculas, int codigo)
{
    ePelicula auxPelicula;
    int i;
    if(tamPeliculas >= 0)
    {
        for(i=0; i<tamPeliculas; i++)
        {
            if(listadoDePeliculas[i].codigo == codigo)
            {
                auxPelicula = listadoDePeliculas[i];
                break;
            }
        }
    }
    return auxPelicula;
}
