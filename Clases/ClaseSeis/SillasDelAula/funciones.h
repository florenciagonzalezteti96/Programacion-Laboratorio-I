#include <stdio.h>
#include <stdlib.h>

void inicializarVector(int vectorDeEnteros[], int tam, int valorDeInicializacion);
void cargarVectorInicializado(int vectorDeEnteros[], int tam, char mensajeDeIngreso[], int valorDeInicializacion);
void mostrarVector(int vectorDeEnteros[], int tam);
void hardcodearVector(int vectorDeEnteros[], int tam);
int calcularMinimo(int vectorDeEnteros[], int tam);
int calcularMaximo (int vectorDeEnteros[], int tam);
int estaLibre(int vectorDeEnteros[], int tam, int posicionAValidar, int valorInicializado);
int estaOcupado(int vectorDeEnteros[], int tam, int posicion, int nuevoValor, int valorInicial);
void cargarVector(int vectorDeEnteros[], int tam, char mensajeDeIngreso[]);
int cantidadLugaresOcupados(int vectorDeEnteros[], int tam, int valorInicial);
int cantidadLugaresLibres(int vectorDeEnteros[], int tam, int valorInicial);
int encontrarPrimeraPosicionLibre(int vectorDeEnteros[], int tam, int valorInicial);
int show_option_menu(int vectorDeEnteros[], int tam);
void mostrar_Minimo_O_Maximo(int vectorDeEnteros[], int tam);
int estaOcupadoConEdad(int vectorDeEnteros[], int tam, int posicion, int legajo, int edad, int edades[], int valorInicial);
void hardcodearVectorEdades(int vectorDeEnteros[], int tam);
int mostrarMaximaEdadYLegajo(int edades[], int legajo[], int tam);
void cargarVectorNombresYApellidos(char cadena[],char mensajeDeIngresoNombre[], char mensajeDeIngresoApellido[]);
void firstToUpper(char cadena[]);
void pedirCadena (char mensaje[], char cadena[], int tam);
void validarTamCadena (char mensajeError[], char cadena[], int tam);
void getString(char mensaje[], char cadena[]);
