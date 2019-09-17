/**
ESTRUCTURAS:

typedef define un tipo de dato

typedef [DEFINICION DEL DATO]{

    //subconjunto de variables.
    char nombre[50];
    int nota[]
}eDato;

para guardar y mostrar:

    scanf("%d", unAlumno.CAMPOELEGIDO);
    printf("%d\n", unAlumno.CAMPOELEGIDO);

    EJ1:
    asigno valores a alumno
    scanf("%d", &unAlumno.nota);
    printf("La nota es: %d\n", unAlumno.nota);
    scanf("%s", unAlumno.nombre);
    printf("El nombre es: %s\n", unAlumno.nombre);

    asigno valores a otroAlumno
    scanf("%d", &otroAlumno.nota);
    printf("La nota del otro alumno es: %d\n", otroAlumno.nota);
    scanf("%s", otroAlumno.nombre);
    printf("El nombre del otro alumno es: %s\n", otroAlumno.nombre);

    asigno valores de unAlumno a otroAlumno
    otroAlumno = unAlumno; // en memoria RAM uno es una copia del otro, ocupan lugares distintos en memoria RAM

    muestro los nuevos valores de otroAlumno
    printf("El nombre es: %s\nLa nota es: %d", otroAlumno.nombre, otroAlumno.nota);
 ------------------------------------------------------------------------------------
    //guardo struc en un aux, hago el swap y asigno el aux a una estructura de alumno -> ordenamiento

    las bajas pueden ser fisicas o logicas (memoria dinamica o usando un flag como isEmpty)

    CARGAR ALUMNO LLAMA A BUSCAR LIBRE Y UTILIZO ESE INDICE PARA VER DONDE GUARDO AL NUEVO ALUMNO

    CARGAR ALUMNO ME DEVUELVE UN ALUMNO Y EN LA FUNCION TENGO QUE UTILIZAR UN FOR





*/


