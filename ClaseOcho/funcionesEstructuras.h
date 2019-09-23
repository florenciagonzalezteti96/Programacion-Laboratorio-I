#define LIBRE 0
#define OCUPADO 1
typedef struct{
    char nombre[50];
    int nota;
    int legajo;
    int isEmpty;//0 para ocupado, 1 para libre -> bandera
}eAlumno;

void mostrar_menu(eAlumno listadoDeAlumnos[], int cantidadDeAlumno);
void hardcodearEstructura(eAlumno listaDeAlumnos[], int cantidadDeAlumnos);
void listarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos);
void mostrarUnAlumno(eAlumno listadoDeAlumnos);
void inicializarAlumnos(eAlumno listadoDeAlumnos[], int cantidadDeAlumnos);
int dameElPrimerLugarLibre(eAlumno listaDeAlumnos[], int cantidadDeAlumnos);
void borrarLegajo(eAlumno listaDeAlumnos[], int cantidadDeAlumnos);
eAlumno crearUnAlumno ();
int cargarUnAlumno(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreDescente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreAscendente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreLegajoDescendente(eAlumno listadoDeAlumnos[], int tam);
void ordenarPorNombreLegajoAscendente(eAlumno listadoDeAlumnos[], int tam);
void firstToUpper(char cadena[]);
void pedirCadena (char mensaje[], char cadena[]);
int getInt(char mensaje[]);
int buscarPorLegajo(eAlumno listadoDeAlumno[], int tam);
void borrarPorNombre(eAlumno listadoDeAlumno[], int tam);
int modificarAlumno(eAlumno listadoDeAlumno[], int tam);
