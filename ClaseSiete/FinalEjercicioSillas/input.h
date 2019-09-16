/** \brief Esta funcion obtiene un numero entero.
 *
 * \param mensaje[] char Mensaje de ingreso
 * \return int El numero ingresado
 *
 */
int getInt(char mensaje[]);
/** \brief Esta funcion obtiene un caracter
 *
 * \param mensaje[] char El mensaje de ingreso
 * \return char El caracter ingresado
 *
 */
char getChar(char mensaje[]);
/** \brief Esta funcion obtiene una cadena de caracteres
 *
 * \param mensaje[] char Mensaje de ingreso
 * \param cadena[] char Cadena en la que se va a copiar la cadena ingresada
 * \return void
 *
 */
void getString(char mensaje[], char cadena[]);
/** \brief Esta funcion obtiene un numero flotante
 *
 * \param mensaje[] char Mensaje de ingreso
 * \return int El numero ingresado
 *
 */
float getFloat(char mensaje[]);
/** \brief Esta funcion obtiene un numero entero y luego valida que ese mismo numero este dentro de un rango determinado
 *
 * \param valor int* Variable puntero en donde guardar el entero a validar
 * \param mensaje[] char Mensaje de ingreso
 * \param mensajeError[] char Mensaje de error (por si el numero ingresado no se encuentra dentro del rango)
 * \param min int Minimo valor aceptable
 * \param max int Maximo valor aceptable
 * \return int Retorna 0 o -1 si el numero ingresado esta dentro del rango, en caso contrario retorna 1
 *
 */
int getIntConRango(int* valor, char mensaje[], char mensajeError[], int min, int max);
/** \brief Esta funcion obtiene un numero flotante y luego valida que ese mismo numero este dentro de un rango determinado
 *
 * \param valor int* Variable puntero en donde guardar el flotante a validar
 * \param mensaje[] char Mensaje de ingreso
 * \param mensajeError[] char Mensaje de error (por si el numero ingresado no se encuentra dentro del rango)
 * \param min int Minimo valor aceptable
 * \param max int Maximo valor aceptable
 * \return int Retorna 0 o -1 si el numero ingresado esta dentro del rango, en caso contrario retorna 1
 *
 */
int getFloatConRango(float* valor, char mensaje[], char mensajeError[], float min, float max);
/** \brief Esta funcion recibe una cadena y
 *
 * \param cadena[] char
 * \return int
 *
 */
int getStringLetras(char cadena[]);
int getStringNumeros(int cadena[]);
int getStringNumeros_Dos(char cadena[]);
