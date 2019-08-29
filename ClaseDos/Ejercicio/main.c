/*mayor importe en dolares*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dinero;
    int contador;
    int contadorPesos = 0;
    int maximoP = 0;
    int minimoP = 0;
    int flagP = 0;
    int maximoD = 0;
    int minimoD = 0;
    int flagD = 0;
    int maximoB = 0;
    int minimoB = 0;
    int flagB = 0;
    int maximoL = 0;
    int minimoL = 0;
    int flagL = 0;
    char tipo;//P, D, L, B
    int acumuladorPesos=0;
    float promedioPesos;
    int contadorDeIntentos = 5;
    int porcentajePesos;

    while(contadorDeIntentos>0)
    {
        for(contador=0; contador<5; contador++)
        {
            printf("Ingrese un importe: ");
            scanf("%d", &dinero);
            fflush(stdin);

            printf("Ingrese P para pesos, L para libra, D para dolar, B para bitcoin:");
            scanf("%c", &tipo);
            fflush(stdin);

            if(tipo=='P'||tipo=='D'||tipo=='L'||tipo=='B')
            {
                if(tipo=='P')//en caso de que ingrese pesos
                {
                    if(flagP==0)
                    {
                        maximoP = dinero;
                        minimoP = dinero;  //establezco un maximo y un minimo.
                        flagP = 1;
                    }
                    else
                    {
                        if(dinero<minimoP)
                        {
                            minimoP = dinero; //cambio por el valor minimo.
                        }
                        else
                        {
                            if(dinero>maximoP)
                            {
                                maximoP = dinero;  //cambio por el valor maximo.
                            }
                        }
                    }
                    acumuladorPesos = acumuladorPesos + dinero;
                    contadorPesos++;
                }
                if(tipo=='L')//en caso de que ingrese pesos
                {
                    if(flagL==0)
                    {
                        maximoL = dinero;
                        minimoL = dinero;  //establezco un maximo y un minimo.
                        flagL = 1;
                    }
                    else
                    {
                        if(dinero<minimoL)
                        {
                            minimoL = dinero; //cambio por el valor minimo.
                        }
                        else
                        {
                            if(dinero>maximoL)
                            {
                                maximoL = dinero;  //cambio por el valor maximo.
                            }
                        }
                    }
                }
                if(tipo=='B')//en caso de que ingrese pesos
                {
                    if(flagB==0)
                    {
                        maximoB = dinero;
                        minimoB = dinero;  //establezco un maximo y un minimo.
                        flagB = 1;
                    }
                    else
                    {
                        if(dinero<minimoB)
                        {
                            minimoB = dinero; //cambio por el valor minimo.
                        }
                        else
                        {
                            if(dinero>maximoB)
                            {
                                maximoB = dinero;  //cambio por el valor maximo.
                            }
                        }
                    }
                }
                if(tipo=='D')//en caso de que ingrese pesos
                {
                    if(flagD==0)
                    {
                        maximoD = dinero;
                        minimoD = dinero;  //establezco un maximo y un minimo.
                        flagD = 1;
                    }
                    else
                    {
                        if(dinero<minimoD)
                        {
                            minimoD = dinero; //cambio por el valor minimo.
                        }
                        else
                        {
                            if(dinero>maximoD)
                            {
                                maximoD = dinero;  //cambio por el valor maximo.
                            }
                        }
                    }
                }
                promedioPesos = (float) acumuladorPesos / contadorPesos ;//casteo explicito
                //casteo implicito. p.e: int x = 9, float y. y = x;
                porcentajePesos = contadorPesos*100/5;
            }
            else
            {
                //si no ingreso un dato valido
                printf("El tipo de dinero ingresado es invalido.\nLe quedan %d intentos\n", contadorDeIntentos);
            }//IF VALIDACION
            contadorDeIntentos--;
        }//FOR
    }//WHILE

    printf("El maximo de dolares es: %d\n", maximoD);
    printf("El promedio de pesos es: %.1f\n", promedioPesos);
    printf("El porcentaje de pesos es: %d\n", porcentajePesos);

    return 0;
}
