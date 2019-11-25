#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "inputs.h"

int main()
{
    LinkedList* listaDeLlamadas = ll_newLinkedList();

    int opcion;
    char opcion_continuar = 's';
    int retorno;

    if(listaDeLlamadas != NULL)
    {
        do
        {
            system("cls");
            opcion = getInt("MENU DE LLAMADAS:\nIngrese una opcion:\n1.Cargar archivo.\n2.Imprimir llamadas.\n3.Generar archivo de llamadas.\n4.Salir\n");
            switch(opcion)
            {
                case 1:
                    retorno = controller_loadFromText("llamadas.txt", listaDeLlamadas);
                    //retorno = controller_loadFromBinary("listaLlamadas.bin", listaDeLlamadas);
                    switch(retorno)
                    {
                    case -1:
                        printf("No se pudieron cargar los datos.");
                        break;
                    case 0:
                        printf("Se cargaron los datos.");
                        break;
                    case 1:
                        printf("La lista es nula.");
                        break;
                    case 2:
                        printf("La lista ya esta cargada");
                        break;
                    }
                    printf("\n");
                    system("pause");
                    break;
                case 2:
                    controller_ListarLlamadas(listaDeLlamadas);
                    printf("\n");
                    system("pause");
                    break;
                case 3:
                    printf("todavia no!");
                    break;
                case 4:
                    opcion_continuar = getConfirmacion("¿Desea salir del programa? Ingrese s para SI o n para NO: ");
                    controller_saveAsBinary("listaLlamadas.bin", listaDeLlamadas);
                    controller_saveAsText("listaLlamadas.cvs", listaDeLlamadas);
                    printf("\n");
                    system("pause");
                    break;
            }


        }
        while(opcion_continuar != 'n');
    }

    return 0;
}
