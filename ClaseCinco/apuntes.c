/**

    \\PUNTEROS:
    --El main declaro la variable numero con el valor 4. esta tiene una direccion de memoria.
    --cuando se apila la funcion "funcion" y devuelve la variable  numero con su direccion de memoria,
    que vale 100.
    --le da una copia de ese mismo valor a numero en main y se desapila.
    --si yo quiero que cmabie el valor siendo una funcion void, necesito que vea la variable que existe en el main
    y lo hago con punteros y pasaje por referencia NO CON VARIABLES GOBLALES.
    --como la variable en function() es un puntero, directamente trae la direcc de memoria de la variable que quiero cambiar.
    --tengo que usar el operador de inacceso.

    \\EJEMPLO:

        void function (int* numero); //modifica el valor que recibe y lo devuelve

        int main()
        {
            int numero = 4;
            printf("El numero antes de modificar es %d\n", numero);
            function(&numero);
            printf("El numero despues de modificar es %d\n", numero);

            return 0;
        }

        void function (int* numero)
        {
            printf("Ingrese un numero: ");
            scanf("%d", numero);//no hace falta poner el ampersand o el *, porque el *numero ya es una direcc de memoria.


        }


\\RECURSIVIDAD

--Una funcion recursiva tiene que tener una clausula de salida,
si no, puede desbordar el programa, porque las funciones se empiezan a apilar porque no tienen un corte.
--La funcion recursiva tambien tiene un limite (12), de rango del entero. por eso la variable de resultado
se tiene que guardan en un dato de tipo long long int.



*/
