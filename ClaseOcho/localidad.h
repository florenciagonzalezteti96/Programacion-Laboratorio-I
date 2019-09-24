typedef struct{
    char nombreLocalidad[30];
    int codigoPostal;
    int idLocalidad;
}eLocalidad;
void hardcodearLocalidades(eLocalidad listaDeLocalidades[], int cantidadDeLocalidades);
int buscarLocalidadPorId(eLocalidad[], int, int);
void mostrarLocalidad(eLocalidad listaDeLocalidades[], int cantidadDeLocalidades);
