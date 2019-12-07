#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "inputs.h"

int main()
{
    LinkedList* listaDeVuelos = ll_newLinkedList();
    LinkedList* listaDeVuelosAPortugal = ll_newLinkedList();
    LinkedList* listaDeVuelosMenoresATresHoras = ll_newLinkedList();
    LinkedList* listaDeVuelosSinAlex = ll_newLinkedList();

    int opcion;
    char opcion_continuar = 's';
    int len;
    int retorno;

    if(listaDeVuelos != NULL)
    {
        do
        {
            system("cls");
            opcion = getInt("MENU DE LLAMADAS:\nIngrese una opcion:\n1.Cargar archivo de texto.\n2.Imprimir vuelos.\n3.crear lista de vuelos menores a 3 horas\n4.--\n5.Vuelos sin alex\n");
            switch(opcion)
            {
            case 1:
                /**CARGA DE TEXTO*/
                retorno = controller_loadFromText("Vuelos.csv", listaDeVuelos);
                switch(retorno)
                {
                case -1:
                    printf("Error: el archivo no puede ser abierto.\n");
                    break;
                case 0:
                    len = ll_len(listaDeVuelos);
                    printf("Se cargaron un total de %d vuelos.\n",len);
                    printf("\n");
                    printf("El archivo se ha abierto exitosamente en modo texto.\n");
                    break;
                case 1:
                    printf("Error: no se pudo acceder a la opcion de carga desde archivo Vuelos.csv (modo texto)");
                    break;
                case 2:
                    printf("Error: La lista ya esta cargada.\n");
                    break;
                }
                printf("\n");
                system("pause");
                break;
                break;
            case 2:
                retorno = controller_ListarVuelos(listaDeVuelos);
                switch(retorno)
                {
                case -1:
                    printf("Error: no se puede acceder al listado de vuelos.\n");
                    break;
                case 0:
                    printf("Se han listado todos los vuelos.\n");
                    break;
                case 1:
                    printf("Error: No se han agregado vuelos a la lista.\n");
                    break;
                }
                printf("\n");
                system("pause");
                break;
            case 3:
                listaDeVuelosMenoresATresHoras = ll_filter(listaDeVuelos, filtrar_EsMenorA3Horas);
                if(listaDeVuelosMenoresATresHoras != NULL)
                {
                    controller_saveAsText("VuelosMenoresATresHoras.txt", listaDeVuelosMenoresATresHoras);
                    printf("se hizo la lista");
                }
                printf("\n");
                system("pause");
                break;
            case 4:
                listaDeVuelosAPortugal = ll_filter(listaDeVuelos, filtrarPorPortugal);
                if(listaDeVuelosAPortugal != NULL)
                {
                    controller_ListarVuelos(listaDeVuelosAPortugal);
                }
                else
                {
                    printf("Error: no se han encontrado vuelos a portugal o ha habido un error en la lista.\n");
                }
                printf("\n");
                system("pause");
                break;
            case 5:
                listaDeVuelosSinAlex = ll_filter(listaDeVuelos, filtrarPorAlex);
                if(listaDeVuelosSinAlex != NULL)
                {
                    controller_ListarVuelos(listaDeVuelosSinAlex);
                }
                else
                {
                    printf("Error: no se han encontrado vuelos a portugal o ha habido un error en la lista.\n");
                }
                system("pause");
                printf("\n");
            }


        }
        while(opcion_continuar != 'n');
    }

    return 0;
}
