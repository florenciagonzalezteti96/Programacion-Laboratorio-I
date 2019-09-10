#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[16];
    char apellido[16];
    char apellidoNombre[40]="";
    int largoNombre;
    int largoApellido;
    int flag = 0;

    //ingreso de nombre, apellido y la variable nombreAPelido guarda el apellido con la primera letra en mayuscula,
    //espacio y nombre con la primera letra en mayuscula. EJ: Gonzalez, Florencia.

    /**pido nombre y apellido*/
    printf("Ingrese su nombre: ");
    fflush(stdin);
    fgets(nombre, 15, stdin);

    printf("\nIngrese su apellido: ");
    fflush(stdin);
    fgets(nombre, 15, stdin);

    /**valido el largo de la cadena y quito el \n de mas que agrega el fflush*/
    largoNombre = strlen(nombre);
    largoApellido = strlen(apellido);

    if(largoNombre>15)
    {
        printf("ERROR. Ingrese el nombre de nuevo.");
    }
    else
    {
        if(largoApellido>15)
        {
            printf("ERROR. Ingrese el apellido de nuevo.");
        }
        else
        {
            nombre[largoNombre - 1] = '\0';
            apellido[largoApellido - 1] = '\0';

            /**paso todo a minuscula*/
            int i;
            for(i=0; i<15; i++)
            {
                nombre[i]=tolower(nombre[i]);
                apellido[i]=tolower(apellido[i]);
            }

            /**la primera letra a mayuscula*/
            for(i=0; i<15; i++)
            {
                if(i==0)
                {
                    nombre[i]=toupper(nombre[i]);
                }
                else
                {
                    if(nombre[i]==' ')
                    {
                        nombre[i+1]=toupper(nombre[i+1]);
                    }
                }
                if(i==0)
                {
                    apellido[i]=toupper(apellido[i]);
                }
                else
                {
                    if(apellido[i]==' ')
                    {
                        apellido[i+1]=toupper(apellido[i+1]);
                    }

                }

                strcpy(apellidoNombre, apellido);
                strcat(apellidoNombre, ", ");
                strcat(apellidoNombre, nombre);

                flag = 1;



            }
        }


    }

    if(flag == 1){
        printf("%s", apellidoNombre);
    }else{
    printf("error. intente de nuevo");
    }


return 0;
}
