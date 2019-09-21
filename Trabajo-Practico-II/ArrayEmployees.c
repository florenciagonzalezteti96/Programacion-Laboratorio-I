#include "ArrayEmployees.h"

void mostrar_menu(Employee list[], int len){
    int option;
    char option_continue='s';
    //inicializarAlumnos(listadoDeAlumnos, tam);
    do{
        printf("\nOpciones:\n1. ALTAS.\n2. MODIFICAR.\n3. BAJA.\n4. INFORMAR.\n5. SALIR.\n");
        fflush(stdin);
        scanf("%d", &option);
        initEmployees(list, len);
        switch(option){
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            printf("Esta seguro que desea salir? Ingrese s para SI o n para NO");
            scanf("%c", &option_continue);
            if(option_continue != 's' && option_continue != 'n'){
                printf("La opcion ingresada es incorrecta. Seleccione 5 e ingrese de nuevo la opcion.");
            }else if(option_continue == 'n'){
            system("pause");
            system("cls");
            }
            break;
        default:
            printf("Ha ingresado una opcion incorrecta.\n");
            break;
        }
    }while(option_continue=='s');
    printf("\n");
}
int initEmployees(Employee* list, int len){
    int i;
    int retorno = -1;
    int lenValido = getValidInt(&len);
    if(lenValido != -1){
        for(i=0;i<len;i++){
            list[i].isEmpty = TRUE;
            retorno = 0;
        }
    }
    return retorno;
}
int getValidInt(int *number)
{
    int sePudo = 1;
    char cadenaCargada [1001];
    int i;
    sprintf(cadenaCargada, "%d", *number);
    printf("%s", cadenaCargada);
    for(i=0; i<strlen(cadenaCargada) ; i++)
    {
        if(cadenaCargada[i] < '0' || cadenaCargada[i] > '9')
        {
            sePudo = -1;
        }
    }
    if(sePudo == 1)
    {
        *number = atoi (cadenaCargada);
    }

    return sePudo;
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
    int retorno = -1;







    return retorno;
}
int cargarUnEmpleado(Employee list[], int len){
    int indice;
    int retorno = -1;
    indice = dameElPrimerLugarLibre(list, len);
    if(indice != -1){
        list[indice] = crearUnEmpleado();
        retorno = 0;
    }
    return retorno;
}
Employee crearUnEmpleado(){
    Employee auxEmployee;
    pedirCadena("Ingrese el nombre del empleado: ", auxEmployee.name);
    pedirCadena("Ingrese el apellido del empleado: ", auxEmployee.lastName);
    auxEmployee.salary = getFloat("Ingrese un salario: ");
    auxEmployee.sector = getFloat("Ingrese el sector del empleado: ");
    auxEmployee.isEmpty = TRUE;
    return auxEmployee;
}
int dameElPrimerLugarLibre(Employee list[], int len){
    int i;
    int retorno = -1;
    for(i=0;i<len;i++){
        if(list[i].isEmpty == TRUE){
            retorno = i;
            break;
        }
    }
    return retorno;
}
void firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(i=0;i<tam;i++){
        if(cadena[i]!='\0'){
            if(isspace(cadena[i])){
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}
void pedirCadena (char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    firstToUpper(cadena);
}
int getInt(char mensaje[]){
    int numero;
    printf("%s: ", mensaje);
    scanf("%d", &numero);
    return numero;
}
int getInt(char mensaje[]){
    int numero;
    printf("%s: ", mensaje);
    scanf("%d", &numero);
    return numero;
}
char getChar(char mensaje[]){
    char letter;
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    return letter;
}
void getString(char mensaje[], char cadena[]){
    char auxCadena[200];
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%[^\n]", auxCadena);
    strcpy(cadena, auxCadena);
}
int getFloat(char mensaje[]){
    float numero;
    printf("%s: ", mensaje);
    scanf("%f", &numero);
    return numero;
}
