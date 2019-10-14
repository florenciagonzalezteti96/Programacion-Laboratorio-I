    /**los arrays son datos. agrupaciones fijas de elementos y eso es mucho mas dinamico trabajarlo con vectores.
    --parte abstracta: como agrupar los datos.
    --parte de hardware: entender como existe en la memoria RAM, como se manipula eso y como se puede crear.
    --los corchetes me indican que lo que le estoy dando es una direccion de memoria.
    --tiene indice cero y la cantidad de elementos es cantDeElemn-1
    --para mostrar los datos de un vector, tambien tengo que usar una estructura repetitiva. Tengo que acompañar al vector cone
    el subindice del elemento que quiero mostrar.
    --

    INICIALIZACION POR EXTENSION:
    --harcodeo. meto datos en el programa desde el codigo.
    int vectorDeNumeros[10]={0,0,0,0,0,0,0,0,0,0};
    --inicializa todo en cero.
    int vectorDeNumeros[10]={0};
    int vectorDeNumeros[10]={};
    --inicializo el valor del PRIMER DATO:
    int vectorDeNumeros[10]={1};

    SETEO EL VECTOR:
    --carga secuencial (se usa un for)
    int i;
    for(i=0;i<10;i++){
        vectorDeNumeros[i] = 0;
        --la linea par inicializar una veriable es la misma que para iniciar un vector.
        --sin inicializar el vector, los capacitores que existen en la computadora, le dan un valor binario random para que tengan un valor. SIEMPRE HAY QUE INICIALIZARLO.
        --para modificar el vector en cualquier lugar, uso un for()
    }

    MUESTRO EL VECTOR:
    for(i=0;i<10;i++){
        printf("%d\n",vectorDeNumeros[i]);

    Paso por referencia y por valor.
    REF: Arrays y punteros.
    VALOR: valores primitivos.

    Un precompilador incluye archivos como #include y #define; Busca cada incidencia del define y la reemplaza.
    cuando compila, compila el codigo con el valor reemplazado por el precompilador.

    tambien se pueden usar constantes como
    int const P = 5;
    es un elemento que me permite definir un valr que se va a mantener de la misma manera durante todo el ciclo del programa.
    es una variable de SOLO LECTURA.
    El define (precompilacion), no ocupa espacio en memoria.


    }*/

