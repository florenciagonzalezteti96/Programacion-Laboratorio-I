//ID_Llamada, Fecha, Numero_Cliente, ID_Problema, Solucionado

typedef struct
{
    int id_Llamada;
    char fecha[12];
    int numero_Cliente;
    int id_Problema;
    char solucionado[2];
}eLlamada;

eLlamada* llamada_new();
eLlamada* llamada_newParametros(char* id_Llamada, char* fecha, char* numero_Cliente, char* id_Problema, char* solucionado);

void llamada_delete(eLlamada* unaLlamada);
int mostrarUnaLlamada(eLlamada* unaLlamada);
void pedirDatosLlamada(char* idProblema, char* fecha, char* numero_Cliente, char* id_Problema, char* solucionado);

int eLlamada_set_IdLlamada(eLlamada* unaLlamada,int id_Llamada);
int eLlamada_get_IdLlamada(eLlamada* unaLlamada,int* id_Llamada);
int eLlamada_set_fecha(eLlamada* unaLlamada, char* fecha);
int eLlamada_get_fecha(eLlamada* unaLlamada,char* fecha);
int eLlamada_set_numeroCliente(eLlamada* unaLlamada,int numeroCliente);
int eLlamada_get_numeroCliente(eLlamada* unaLlamada, int* numeroCliente);
int eLlamada_set_idProblema(eLlamada* unaLlamada,int id_Problema);
int eLlamada_get_idProblema(eLlamada* unaLlamada,int* id_Problema);
int eLlamada_set_solucionado(eLlamada* unaLlamada,char* solucionado);
int eLlamada_get_solucionado(eLlamada* unaLlamada,char* solucionado);

int compararPor_IdProblema(void* pElementOne, void* pElementTwo);




