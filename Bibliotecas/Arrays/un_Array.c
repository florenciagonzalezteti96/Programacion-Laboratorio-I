/** FUNCIONES BASICAS */
void inicializarArray(int arrayDeEnteros[], int tam, int valorInicial){
    int i;
    for(i=0;i<tam;i++){
        arrayDeEnteros[i]=valorInicial;
    }
}
void cargarArray(int arrayDeEnteros[], int tam, char mensajeDeIngreso[]){
    int i;
    printf("%s", mensajeDeIngreso);
    for(i=0; i<tam; i++){
        scanf("%d", arrayDeEnteros[i]);
    }
    printf("\n");
}
void mostrarArray(int arrayDeEnteros[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n", arrayDeEnteros[i]);
    }
    printf("\n");
}
/** FUNCIONES DE ENTEROS */
int buscarValorInt(int arrayDeEnteros[], int tam, int num){
    int i;
    int retorno = 0;
    for(i=0; i<tam; i++){
        if(arrayDeEnteros[i]==num){
            retorno = 1;
        }
    }
    return retorno;
}
void mostrarPosicionNumero(int arrayDeEnteros[], int tam, int num){
    int i;
    int numero = buscarValorInt(arrayDeEnteros, tam, num);
    if(numero!=0){
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
void ordenarDeMayorAMenor(int arrayDeEnteros[], int tam){
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
void ordenarDeMenorAMayor(int arrayDeEnteros[], int tam){
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
void menu_Ordenar_Vector(int vectorDeEnteros[], int tam){
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
void mostrarNumerosNegativos(int vectorDeEnteros[], int tam){
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
void mostrarNumerosPositivos(int vectorDeEnteros[], int tam){
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
void mostrarPromedioDeNegativos(int vectorDeEnteros[], int tam){
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
void mostrarPromedioDePositivos(int vectorDeEnteros[], int tam){
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
/** MINIMOS Y MAXIMOS */
int calcularMaximo (int vectorDeEnteros[], int tam){
    int i;
    int max;
    int flag;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]>max || flag == 0){
            max=vectorDeEnteros[i];
        }
    }
    return max;
}
void mostrarMaximo(int vectorDeEnteros[], int tam){
    int max = calcularMaximo(vectorDeEnteros, tam);
    printf("El max es: %d\n", max);
}
void mostrarPosicionMaximo (int vectorDeEnteros[], int tam){
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
int calcularMinimo(int vectorDeEnteros[], int tam){
    int i;
    int min;
    int flag;
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]<min || flag == 0){
            min=vectorDeEnteros[i];
        }
    }
 return min;
}
void mostrarMinimo(int vectorDeEnteros[], int tam){
    int min = calcularMinimo(vectorDeEnteros, tam);
    printf("El min es: %d\n", min);
}
void mostrarPosicionMinimo(int vectorDeEnteros[], int tam){
    int i;
    int min = calcularMinimo(vectorDeEnteros, tam);
    printf("\nLa/s posicion/es del minimo es/son:");
    for(i=0; i<tam; i++){
        if(vectorDeEnteros[i]==min){
            printf("%d\n", i);
        }
    }
}
void menu_Mostrar_Minimo_O_Maximo(int vectorDeEnteros[], int tam){
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

