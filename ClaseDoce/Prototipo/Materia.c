#include "Materia.h"

void hardCodearMaterias(eMateria listadoDeMaterias[], int tam){
    int i;
    int idMateria[]= {100,101,102,103};
    char descripcion[][25]= {"Programacion I","Laboratorio I","Matematica I","SPD"};
    int cargaHoraria[]= {4,4,6,4};
    for(i=0; i<tam; i++)
    {
        listadoDeMaterias[i].idMateria = idMateria[i];
        strcpy(listadoDeMaterias[i].descripcion, descripcion[i]);
        listadoDeMaterias[i].cargaHoraria = cargaHoraria[i];
    }
}
void mostrarMaterias(eMateria listadoDeMaterias[], int tam){
    int i;
    for(i=0;i<4;i++){
        printf("id de la materia: %d\t",listadoDeMaterias[i].idMateria);
        printf("descripcion: %s\t",listadoDeMaterias[i].descripcion);
        printf("cargahoraria: %d\t\n",listadoDeMaterias[i].cargaHoraria);
    }
}
