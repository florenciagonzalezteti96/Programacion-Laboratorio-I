
typedef struct{
    char nombre[50];
    int nota;
    int legajo;
    int isEmpty;//0 para ocupado, 1 para libre -> bandera
}eAlumno;

void mostrar_menu(eAlumno listadoDeAlumnos[], int cantidadDeAlumno, int valorInicial);
void hardcodearEstructura(eAlumno listaDeAlumnos[], int cantidadDeAlumnos);
void listarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, int valorInicial);
void mostrarUnAlumno(eAlumno listadoDeAlumnos);
void inicializarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos, int valorInicial);
int dameElPrimerLugarLibre(eAlumno listaDeAlumnos[], int cantidadDeAlumnos, int valorInicial);
void borrarLegajo(eAlumno listaDeAlumnos[], int cantidadDeAlumnos, int valorInicial);
eAlumno crearUnAlumno ();
int cargarUnAlumno(eAlumno listadoDeAlumnos[], int tam, int valorInicial);
void borrarPorNombre(eAlumno listadoDeAlumno[], int tam);
void buscarPorNombre(eAlumno listadoDeAlumno[], int tam);
void ordenarPorNombreDescente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreAscendente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreLegajoDescendente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreLegajoAscendente(eAlumno listadoDeAlumnos[], int tam);
