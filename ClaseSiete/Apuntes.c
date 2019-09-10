/**
CADENAS:

--no hay datos string en C, asi que lo que hacemos es crear un vector de caracteres.
--El contrabarra cero \0 indica el final de la palabra, entonces al array hay que asignarle siempre un espacio mas para el \0
***************************
    scanf("%s", &palabra);//el ampersand le da la direccion de memoria del primer elemento
    es lo mismo:
    palabra --> es la mejor opcion.
    &palabra
    &palabra[0]
***************************
    int i;
    for(i=0;i<5;i++){
        printf("Ingrese una palabra:");
        fflush(stdin);    --> para que al leer una cadena no me tire error o basura, uso un fflush antes de leer de la consola.
        scanf("%s", palabra);
        printf("%s", palabra);
    }
*************************
    FUNCIONES DE LECTURA DE LA CONSOLA:

    --el scanf no sabe discriminar el \0 o el espacio

    como leer una frase o palabras separadas por espacios:

    1. FUNCION GETS: me permite leer una cadena de caracteres sin importar que tenga espacios o no.

    gets(palabra); //recibe un puntero a char, un vector de caracteres.

    2. FUNCION FGETS: lee desde un archivo.

    recibe un puntero a char, un tamaño del puntero, y un archivo desde donde yo lo leo (en este caso el buffer, stdin);

    3. CAMBIO LA MASCARA EN SCANF:

        scanf("%[^\n]", palabra); -> le digo al programa que lea hasta el \n, lo cual incluye los espacios, lee hasta que el usuario presione enter.

*************************
palabra = "hola"; -> no se puede asignar una constante a un puntero a char.
palabra == "hola"; -> el operador no sabe comparar cadenas

utilizo las funciones de la biblioteca string:

1.para ver cual es el largo de una cadena: STRLEN ->  me devuelve la cantidad de caracteres que tiene una palabra (un int). Sirve para validar que una cadena no se vaya del largo permitido

PERO SI USO FGETS PARA GUARDAR -> esta preparado para leer un archivo, un en ese puedo tener muchas lineas, entonces lo que hace el fgets
me guarda un \n dentro del vector antes del \0. lo que tengo que hacer es que dentro de una funcion, tengo que buscar EL ULTIMO \N y cambiarlo por \0

    char palabra [10];
    int largo;
    printf("Ingrese una palabra:");
    fflush(stdin);
    fgets(palabra, 10, stdin);
    printf("%s", palabra);

    largo = strlen(palabra);
    palabra [largo - 1] = '\0';***

    printf("%d", largo);

2.copiar una cadena en otra cadena. STRCPY -> recibe el destino de los datos, y el origen de los datos.

    char palabra [10];
    strcpy(palabra, "hola");
    printf("%s", palabra);


    char palabra [10];
    char otraPalabra[10] = "Chau";
    strcpy(palabra, otraPalabra);
    printf("%s", palabra);

    El tamaño del origen no puede ser mayor al tamaño del destino, porque sino desborda.

3.para saber si el contenido de los dos es igual (comparacion). STRCMP -> recibe un puntero a char, y otra para comparar. compara letra por letra
los caracteres son en realidad valores ASCII, entonces va comparando cada valor.


cuando las dos son iguales, strcmp devuelve 0.
si la primera es anterior a la segunda da -1, por ejemplo "adios" y "chau"
si la primera es posterior a la segunda da 1, por ejemplo "chau" y "adios"

DISCRIMINA ENTRE MAYUSCULAS Y MINUSCULAS. para que no haga eso tengo que usar stricmp(); porque no es case sensitive.

    char palabra [10];
    char otraPalabra[10] = "Chau";
    int comp;

    printf("Ingrese una palabra");
    fflush(stdin);
    fgets(palabra, 10, stdin);

    comp = strcmp(palabra, otraPalabra);

    printf("%d", comp);

4.para pasar todo a mayusculas o minusculas: strupr o strlwr -> esta funcion trabaja

    char palabra [10];
    char otraPalabra[10] = "Chau";

    printf("Ingrese una palabra");
    fflush(stdin);
    scanf("%[^\n]", palabra);

    strupr(palabra);
    strlwr(palabra);
    printf("%s", palabra);

    tambien puedo usar la biblioteca ctype.h, con la funcion tolower(un char); me retorna un caracter que lo tengo que guardar en una cadena o una variable

5.para concatenar: strcat

    char palabra [10];
    char otraPalabra[10] = "Chau";

    printf("Ingrese una palabra");
    fflush(stdin);
    scanf("%[^\n]", palabra);

    strcat(otraPalabra, palabra);
    printf("%s", otraPalabra);


si la cadena de destino no tiene nada, lo que hace el strcat es poner un valor basura en la variable de destino.
para que no me tire basura lo que puedo hacer es iniciar a la cadena destino asi: palabra[10]=" ";

** isspace() -> me dice si el caracter que le paso es un espacio.
** isdigit
** isalpha


strlwr (apellidoNOmbre)

apellido nombre [0]=toupper

len =

for
if(isspace(apellidoNombre[i]))
                    {
                        nombre[i+1]=toupper(nombre[i+1]);
                    })

    //funcion get string:
    while(strlen(auxString)>15){
        printf("Error. Reingrese su nombre: ");
        fflush(stdin);
        fgets(nombre, 15, stdin);
    }

    strcpy(nombre, auxString);

*/

