
typedef struct{
    int idMateria;
    char descripcion[50];
    int cargaHoraria;
}eMateria;

void hardCodearMaterias(eMateria listadoDeMaterias[], int tam);
void mostrarMaterias(eMateria listadoDeMaterias[], int tam);
