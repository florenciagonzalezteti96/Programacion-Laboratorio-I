/** FUNCIONES BASICAS */
void inicializarArray(int array[], int tam, int valorInicial){
    int i;
    for(i=0;i<tam;i++){
        arrayDeEnteros[i]=valorInicial;
    }
}
void cargarArrayInicializado(int array[], int tam, char mensajeDeIngreso[], int valorInicial){
    int i;
    printf("%s", mensajeDeIngreso);
    for(i=0; i<tam; i++){
        if(estaLibre(array, tam, i, valorInicial)==1){
            scanf("%d", &array[i]); //si esta libre se guarda un valor.
        }
    }
    printf("\n");
}
void cargarArray(int array[], int tam, char mensajeDeIngreso[]){
    int i;
    printf("%s", mensajeDeIngreso);
    for(i=0; i<tam; i++){
        scanf("%d", arrayDeEnteros[i]);
    }
    printf("\n");
}
void mostrarArray(int array[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n", arrayDeEnteros[i]);
    }
    printf("\n");
}
void hardcodearArray(int array[], int tam){
    int arrayAux[]={0,0,0,0,0};
    int i;
    for(i=0; i<tam; i++){
        array[i] = arrayAux[i];
    }
}
int estaOcupado(int array[], int tam, int posicion, int nuevoValor, int valorInicial){
    int retorno = -1;
    if(posicion<tam){
        if(estaLibre(array, tam, posicion,valorInicial)==1){
            array[posicion]=nuevoValor;
            retorno = 0;
        }
    }
    return retorno;
}
int estaLibre(int array[], int tam, int posicion, int valorInicial){
    int retorno = 0;
    if(array[posicion] == valorInicial){
        retorno = 1;
    }
    return retorno;
}
int encontrarPrimeraPosicionLibre(int array[], int tam, int valorInicial){
    int i;
    int retorno = -1;
    for(i=0;i<tam;i++){
        if(array[i]==valorInicial){
            retorno = i;
            break;
        }
    }
    return retorno;
}
int cantidadPosicionesOcupados(int array[], int tam, int valorInicial){
    int i;
    int contador = 0;
    for(i=0; i<tam; i++){
        if(array[i]!=valorInicial){
            contador++;
        }
    }
    return contador;
}
int cantidadPosicionesLibres(int array[], int tam, int valorInicial){
    int i;
    int contador = 0;
    for(i=0; i<tam; i++){
        if(array[i]==valorInicial){
            contador++;
        }
    }
    return contador;
}
/** FUNCIONES DE ENTEROS */
int buscarValorInt(int array[], int tam, int num){
    int i;
    int retorno = 0;
    for(i=0; i<tam; i++){
        if(arrayDeEnteros[i]==num){
            retorno = 1;
        }
    }
    return retorno;
}
void mostrarPosicionNumero(int array[], int tam, int num){
    int i;
    int si_Existe = buscarValorInt(arrayDeEnteros, tam, num);
    if(si_Existe!=0){
        printf("\nLa posicion del numero es:");
        for(i=0; i<tam; i++){
            if(arrayDeEnteros[i]==num){
                printf("%d\n", i);
            }
        }
    }else{
        printf("El numero no existe en la lista.\n");
    }

}
/** CRITERIOS DE ORDENAMIENTO */
void ordenarDeMayorAMenor(int array[], int tam){
    int indicePrimerArray;
    int indiceSegundoArray;
    int aux;
    for(indicePrimerArray=0;indicePrimerArray<tam-1;indicePrimerArray++){
        for(indiceSegundoArray=indicePrimerArray+1;indiceSegundoArray<tam;indiceSegundoArray++){
            if(arrayDeEnteros[indicePrimerArray]<arrayDeEnteros[indiceSegundoArray]){
                /*C = A
                A = B criterio de ordenamiento
                B = C */
                aux = arrayDeEnteros[indicePrimerArray];
                arrayDeEnteros[indicePrimerArray] = arrayDeEnteros[indiceSegundoArray];
                arrayDeEnteros[indiceSegundoArray] = aux;
            }
        }
    }
    mostrarArray(arrayDeEnteros, tam);
}
void ordenarDeMenorAMayor(int array[], int tam){
    int indicePrimerArray;
    int indiceSegundoArray;
    int aux;
    for(indicePrimerArray=0;indicePrimerArray<tam-1;indicePrimerArray++){
        for(indiceSegundoArray=indicePrimerArray+1;indiceSegundoArray<tam;indiceSegundoArray++){
            if(arrayDeEnteros[indicePrimerArray]>arrayDeEnteros[indiceSegundoArray]){
                /*C = A
                A = B criterio de ordenamiento
                B = C */
                aux = arrayDeEnteros[indicePrimerArray];
                arrayDeEnteros[indicePrimerArray] = arrayDeEnteros[indiceSegundoArray];
                arrayDeEnteros[indiceSegundoArray] = aux;
            }
        }
    }
    mostrarArray(arrayDeEnteros, tam);
}
void menu_Ordenar_Vector(int array[], int tam){
    int option;
    char option_continue='s';
    do{
        printf("\nIngrese 1 para ordenar de menor a mayor o 2 para ordenar de mayor a menor:\nPresione 3 para volver al menu principal.\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("El vector ordenado de menor a mayor es: \n");
            ordenarDeMenorAMayor(vectorDeEnteros, tam);
            break;
        case 2:
            printf("El vector ordenado de mayor a menor es: \n");
            ordenarDeMayorAMenor(vectorDeEnteros, tam);
            break;
        default:
            option_continue='n';
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}
/** NUMEROS POSITIVOS Y NEGATIVOS */
void mostrarNumerosNegativos(int array[], int tam){
    printf("Estos son los numeros negativos:\n");
    int i;
    int flagNo_Negatives = 0;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]<0){
            printf("%d\n",vectorDeEnteros[i]);
            flagNo_Negatives = 1;
        }
    }
    if(flagNo_Negatives == 0){
        printf("No hay numeros negativos.\n");
    }
    printf("\n");
}
void mostrarNumerosPositivos(int array[], int tam){
    printf("Estos son los numeros positivos:\n");
    int i;
    int flagNo_Positivos = 0;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]>0){
            printf("%d\n",vectorDeEnteros[i]);
            flagNo_Negatives = 1;
        }
    }
    if(flagNo_Positivos == 0){
        printf("No hay numeros positivos.\n");
    }
    printf("\n");
}
void mostrarPromedioDeNegativos(int array[], int tam){
    int i;
    int acumuladorNegativos = 0;
    int contadorNegativos = 0;
    float promedioNegativos;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]>0){
            acumuladorNegativos = acumuladorNegativos + vectorDeEnteros[i];
            contadorNegativos++;
        }
    }
    promedioNegativos = (float) acumuladorNegativos / contadorNegativos;
    printf("Promedio de positivos: %.2f\n", promedioNegativos);
    printf("\n");
}
void mostrarPromedioDePositivos(int array[], int tam){
    int i;
    int acumuladorPositivos = 0;
    int contadorPositivos = 0;
    float promedioPositivos;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]>0){
            acumuladorPositivos = acumuladorPositivos + vectorDeEnteros[i];
            contadorPositivos++;
        }
    }
    promedioPositivos = (float) acumuladorPositivos / contadorPositivos;
    printf("Promedio de positivos: %.2f\n", promedioPositivos);
    printf("\n");
}
int mostrarCantidadPositivos(int array[], int tam){
    int contadorPositivos = 0;
    int i;
    for(i=0;i<tam;i++){
        if(array[i]>0){
            contadorPositivos++;
        }
    }
    return contadorPositivos;
}
int mostrarCantidadNegativos(int array[], int tam){
    int contadorNegativos = 0;
    int i;
    for(i=0;i<tam;i++){
        if(array[i]<0){
            contadorNegativos++;
        }
    }
    return contadorNegativos;
}
/** MINIMOS Y MAXIMOS */
int calcularMaximo (int array[], int tam){
    int i;
    int max;
    int flag;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]>max || flag == 0){
            max=vectorDeEnteros[i];
            flag = 1;
        }
    }
    return max;
}
void mostrarMaximo(int array[], int tam){
    int max = calcularMaximo(vectorDeEnteros, tam);
    printf("El max es: %d\n", max);
}
void mostrarPosicionMaximo (int array[], int tam){
    int i;
    int max = calcularMaximo(vectorDeEnteros, tam);
    printf("\nLa/s posicion/es del maximo es/son:");
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]==max){
            printf("%d\n", i);
        }
    }
    printf("\n");
}
int calcularMinimo(int array[], int tam){
    int i;
    int min;
    int flag;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]<min || flag == 0){
            min=vectorDeEnteros[i];
            flag = 1;
        }
    }
 return min;
}
void mostrarMinimo(int array[], int tam){
    int min = calcularMinimo(vectorDeEnteros, tam);
    printf("El min es: %d\n", min);
}
void mostrarPosicionMinimo(int array[], int tam){
    int i;
    int min = calcularMinimo(vectorDeEnteros, tam);
    printf("\nLa/s posicion/es del minimo es/son:");
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]==min){
            printf("%d\n", i);
        }
    }
}
void menu_Mostrar_Minimo_O_Maximo(int array[], int tam){
    int min = calcularMinimo(vectorDeEnteros, tam);
    int max = calcularMaximo(vectorDeEnteros, tam);
    int option;
    char option_continue='s';
    do{
        printf("\nIngrese 1 para mostrar minimo o 2 para mostrar maximo:\nPresione 3 para volver al menu principal.\n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("El minimo es: %d.\n", min);
            mostrarPosicionMinimo(vectorDeEnteros, tam);
            break;
        case 2:
            printf("El maximo es: %d.\n", max);
            mostrarPosicionMaximo(vectorDeEnteros, tam);
            break;
        default:
            option_continue='n';
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}

