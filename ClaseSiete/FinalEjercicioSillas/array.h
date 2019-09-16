/** \brief Esta funcion inicializa los valores de cada posicion del vector con un valor especifico.
 *
 * \param cadena[] int Un cadena de enteros a inicializar.
 * \param tam int El tamaño del cadena de enteros a inicializar.
 * \param valorInicial int El valor con el cual se va a inicializar todos los valores del cadena.
 * \return void
 *
 */
void inicializarcadena(int cadena[], int tam, int valorInicial);
/** \brief Esta funcion permite que el usuario cargue valores nuevos a un vector ya inicializado.
 *
 * \param cadena[] int El cadena de enteros a cargar.
 * \param tam int El tamaño del cadena de enteros.
 * \param mensajeDeIngreso[] char Un mensaje para que el usuario comienze la carga de datos.
 * \param valorInicial int El valor inicial que valida que el lugar no este ocupado.
 * \return void
 *
 */
void cargarcadenaInicializado(int cadena[], int tam, char mensajeDeIngreso[], int valorInicial);
/** \brief Esta funcion permite que el usuario cargue valores en un cadena.
 *
 * \param cadena[] int El cadena de enteros para cargar.
 * \param tam int El tamaño del cadena de enteros.
 * \param mensajeDeIngreso[] char Un mensaje para que el usuario comienze la carga de datos.
 * \return void
 *
 */
void cargarcadena(int cadena[], int tam, char mensajeDeIngreso[]);
/** \brief Esta funcion muestra los valores dentro de un cadena.
 *
 * \param cadena[] int El cadena de enteros a mostrar.
 * \param tam int El tamaño del cadena de enteros.
 * \return void
 *
 */
void mostrarcadena(int cadena[], int tam);
/** \brief Esta funcion permite hardcodear los datos de un cadena de enteros.
 *
 * \param cadena[] int El cadena de enteros que recibe los valores.
 * \param tam int El tamaño del cadena.
 * \return void
 *
 */
void hardcodearcadena(int cadena[], int tam);
/** \brief Esta funcion informa si una posicion dentro de un cadena de enteros ya esta ocupada. Si no lo esta, se carga un valor nuevo.
 *
 * \param cadena[] int El cadena de enteros.
 * \param tam int El tamaño del cadena.
 * \param posicion int La posicion en la que se quiere cargar el dato nuevo.
 * \param nuevoValor int El nuevo valor que se quiere dar a la posicion.
 * \param valorInicial int El valor con el cual el vector fue inicializado, para señalar que esa posicion esta libre para cargar un dato nuevo.
 * \return int Devuelve 0 si logro cargar el dato, es decir, la posicion estaba libre. Si no, devuelve 1.
 *
 */
int estaOcupado(int cadena[], int tam, int posicion, int nuevoValor, int valorInicial);
/** \brief Esta funcion informa si una posicion dentro de un cadena de enteros ya esta ocupada.
 *
 * \param cadena[] int El cadena de enteros.
 * \param tam int El tamaño del cadena
 * \param posicion int La posicion a verificar
 * \param valorInicial int El valor con el cual fueron inicializadas todas las posisiones dentro del cadena.
 * \return int Devuelve 0 si esta ocupada, si no devuelve 1.
 *
 */
int estaLibre(int cadena[], int tam, int posicion, int valorInicial);
/** \brief Esta funcion informa cual es la primera posicion libre dentro de un cadena.
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \param valorInicial int El valor con el cual fue inicializado el cadena.
 * \return int Devuelve -1 si no encontro ninguna posicion libre, si no devuelve el indice dentro del cadena de la primera posision libre
 *
 */
int encontrarPrimeraPosicionLibre(int cadena[], int tam, int valorInicial);
/** \brief Esta funcion informa cuantas posiciones libres hay dentro de un cadena.
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \param valorInicial int El valor con el cual se inicializaron todas las posiciones del cadena
 * \return int Devuelve 0 si no hay posiciones libres, si no devuelve el numero de posiciones libres encontradas
 *
 */
int cantidadPosicionesOcupados(int cadena[], int tam, int valorInicial);
/** \brief Esta funcion informa cuantas posiciones ocupadas hay dentro de un cadena.
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \param valorInicial int El valor con el cual se inicializaron todas las posiciones del cadena
 * \return int Devuelve 0 si no hay posiciones ocupadas, si no devuelve el numero de posiciones ocupadas encontradas
 *
 */
int cantidadPosicionesLibres(int cadena[], int tam, int valorInicial);
/** \brief Esta funcion busca un valor dentro de un cadena e informa si existe en el mismo o no.
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \param num int El numero a encontrar
 * \return int Devuelve 0 si no lo encontro. Si lo encontro devuelve 1.
 *
 */
int buscarValorInt(int cadena[], int tam, int num);
/** \brief Esta funcion muestra en la pantalla la posicion de un numero dentro de un cadena.
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \param num int El numero del que se quiere saber la posicion
 * \return void
 *
 */
void mostrarPosicionNumero(int cadena[], int tam, int num);
/** \brief Esta funcion utiliza el burbujeo como criterio para ordenar de mayor a menor un cadena de enteros
 *
 * \param cadena[] int El cadena de enteros a ordenar
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void ordenarDeMayorAMenor(int cadena[], int tam);
/** \brief Esta funcion utiliza el burbujeo como criterio para ordenar de menor a mayor un cadena de enteros
 *
 * \param cadena[] int El cadena de enteros a ordenar
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void ordenarDeMenorAMayor(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla un menu para seleccionar si el usuario quiere ordenar de mayor a menor o viceversa
 *
 * \param cadena[] int El cadena de enteros a ordenar
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void menu_Ordenar_Vector(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla los numeros negativos que existen dentro de un cadena (si no los hay muestra lo avisa mediante un mensaje)
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void mostrarNumerosNegativos(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla los numeros positivos que existen dentro de un cadena (si no los hay muestra lo avisa mediante un mensaje)
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void mostrarNumerosPositivos(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla el promedio de numeros negativos
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void mostrarPromedioDeNegativos(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla el promedio de numeros positivos
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void mostrarPromedioDePositivos(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla la cantidad de numeros positivos dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return int La cantidad de numeros positivos encontrados.
 *
 */
int mostrarCantidadPositivos(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla la cantidad de numeros negativos dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return int La cantidad de numeros negativos encontrados.
 *
 */
int mostrarCantidadNegativos(int cadena[], int tam);
/** \brief Esta funcion calcula el valor maximo dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return max int El valor maximo encontrado en el cadena
 *
 */
int calcularMaximo (int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla el valor maximo dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void mostrarMaximo(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla la posicion del valor maximo dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void mostrarPosicionMaximo (int cadena[], int tam);
/** \brief Esta funcion calcula el valor minimo dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return max int El valor minimo encontrado en el cadena
 *
 */
int calcularMinimo(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla el valor minimo dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void mostrarMinimo(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla la posicion del valor minimo dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void mostrarPosicionMinimo(int cadena[], int tam);
/** \brief Esta funcion muestra en pantalla un menu para seleccionar si el usuario quiere mostrar el valor minimo o maximo dentro de un cadena
 *
 * \param cadena[] int El cadena de enteros a ordenar
 * \param tam int El tamaño del cadena
 * \return void
 *
 */
void menu_Mostrar_Minimo_O_Maximo(int cadena[], int tam);


