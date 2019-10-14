#define TRUE 0
#define FALSE 1

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

void mostrar_menu(Employee list[], int len);
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
Employee crearUnEmpleado();
int cargarUnEmpleado(Employee list[], int len);
int dameElPrimerLugarLibre(Employee list[], int len);
int getValidInt(int *number);
int getInt(char mensaje[]);
void pedirCadena (char mensaje[], char cadena[]);
void firstToUpper(char cadena[]);
char getChar(char mensaje[]);
void getString(char mensaje[], char cadena[]);
int getFloat(char mensaje[]);
