/** \brief Esta funcion inicializa los valores de cada posicion del vector con un valor especifico.
 *
 * \param array[] int Un array de enteros a inicializar.
 * \param tam int El tamaño del array de enteros a inicializar.
 * \param valorInicial int El valor con el cual se va a inicializar todos los valores del array.
 * \return void
 *
 */
void inicializarArray(int array[], int tam, int valorInicial);
/** \brief Esta funcion permite que el usuario cargue valores nuevos a un vector ya inicializado.
 *
 * \param array[] int El array de enteros a cargar.
 * \param tam int El tamaño del array de enteros.
 * \param mensajeDeIngreso[] char Un mensaje para que el usuario comienze la carga de datos.
 * \param valorInicial int El valor inicial que valida que el lugar no este ocupado.
 * \return void
 *
 */
void cargarArrayInicializado(int array[], int tam, char mensajeDeIngreso[], int valorInicial);
/** \brief Esta funcion permite que el usuario cargue valores en un array.
 *
 * \param array[] int El array de enteros para cargar.
 * \param tam int El tamaño del array de enteros.
 * \param mensajeDeIngreso[] char Un mensaje para que el usuario comienze la carga de datos.
 * \return void
 *
 */
void cargarArray(int array[], int tam, char mensajeDeIngreso[]);
/** \brief Esta funcion muestra los valores dentro de un array.
 *
 * \param array[] int El array de enteros a mostrar.
 * \param tam int El tamaño del array de enteros.
 * \return void
 *
 */
void mostrarArray(int array[], int tam);
/** \brief Esta funcion permite hardcodear los datos de un array de enteros.
 *
 * \param array[] int El array de enteros que recibe los valores.
 * \param tam int El tamaño del array.
 * \return void
 *
 */
void hardcodearArray(int array[], int tam);
/** \brief Esta funcion informa si una posicion dentro de un array de enteros ya esta ocupada. Si no lo esta, se carga un valor nuevo.
 *
 * \param array[] int El array de enteros.
 * \param tam int El tamaño del array.
 * \param posicion int La posicion en la que se quiere cargar el dato nuevo.
 * \param nuevoValor int El nuevo valor que se quiere dar a la posicion.
 * \param valorInicial int El valor con el cual el vector fue inicializado, para señalar que esa posicion esta libre para cargar un dato nuevo.
 * \return int Devuelve 0 si logro cargar el dato, es decir, la posicion estaba libre. Si no, devuelve 1.
 *
 */
int estaOcupado(int array[], int tam, int posicion, int nuevoValor, int valorInicial);
/** \brief Esta funcion informa si una posicion dentro de un array de enteros ya esta ocupada.
 *
 * \param array[] int El array de enteros.
 * \param tam int El tamaño del array
 * \param posicion int La posicion a verificar
 * \param valorInicial int El valor con el cual fueron inicializadas todas las posisiones dentro del array.
 * \return int Devuelve 0 si esta ocupada, si no devuelve 1.
 *
 */
int estaLibre(int array[], int tam, int posicion, int valorInicial);
/** \brief Esta funcion informa cual es la primera posicion libre dentro de un array.
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \param valorInicial int El valor con el cual fue inicializado el array.
 * \return int Devuelve -1 si no encontro ninguna posicion libre, si no devuelve el indice dentro del array de la primera posision libre
 *
 */
int encontrarPrimeraPosicionLibre(int array[], int tam, int valorInicial);
/** \brief Esta funcion informa cuantas posiciones libres hay dentro de un array.
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \param valorInicial int El valor con el cual se inicializaron todas las posiciones del array
 * \return int Devuelve 0 si no hay posiciones libres, si no devuelve el numero de posiciones libres encontradas
 *
 */
int cantidadPosicionesOcupados(int array[], int tam, int valorInicial);
/** \brief Esta funcion informa cuantas posiciones ocupadas hay dentro de un array.
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \param valorInicial int El valor con el cual se inicializaron todas las posiciones del array
 * \return int Devuelve 0 si no hay posiciones ocupadas, si no devuelve el numero de posiciones ocupadas encontradas
 *
 */
int cantidadPosicionesLibres(int array[], int tam, int valorInicial);
/** \brief Esta funcion busca un valor dentro de un array e informa si existe en el mismo o no.
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \param num int El numero a encontrar
 * \return int Devuelve 0 si no lo encontro. Si lo encontro devuelve 1.
 *
 */
int buscarValorInt(int array[], int tam, int num);
/** \brief Esta funcion muestra en la pantalla la posicion de un numero dentro de un array.
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \param num int El numero del que se quiere saber la posicion
 * \return void
 *
 */
void mostrarPosicionNumero(int array[], int tam, int num);
/** \brief Esta funcion utiliza el burbujeo como criterio para ordenar de mayor a menor un array de enteros
 *
 * \param array[] int El array de enteros a ordenar
 * \param tam int El tamaño del array
 * \return void
 *
 */
void ordenarDeMayorAMenor(int array[], int tam);
/** \brief Esta funcion utiliza el burbujeo como criterio para ordenar de menor a mayor un array de enteros
 *
 * \param array[] int El array de enteros a ordenar
 * \param tam int El tamaño del array
 * \return void
 *
 */
void ordenarDeMenorAMayor(int array[], int tam);
/** \brief Esta funcion muestra en pantalla un menu para seleccionar si el usuario quiere ordenar de mayor a menor o viceversa
 *
 * \param array[] int El array de enteros a ordenar
 * \param tam int El tamaño del array
 * \return void
 *
 */
void menu_Ordenar_Vector(int array[], int tam);
/** \brief Esta funcion muestra en pantalla los numeros negativos que existen dentro de un array (si no los hay muestra lo avisa mediante un mensaje)
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return void
 *
 */
void mostrarNumerosNegativos(int array[], int tam);
/** \brief Esta funcion muestra en pantalla los numeros positivos que existen dentro de un array (si no los hay muestra lo avisa mediante un mensaje)
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return void
 *
 */
void mostrarNumerosPositivos(int array[], int tam);
/** \brief Esta funcion muestra en pantalla el promedio de numeros negativos
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return void
 *
 */
void mostrarPromedioDeNegativos(int array[], int tam);
/** \brief Esta funcion muestra en pantalla el promedio de numeros positivos
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return void
 *
 */
void mostrarPromedioDePositivos(int array[], int tam);
/** \brief Esta funcion muestra en pantalla la cantidad de numeros positivos dentro de un array
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return int La cantidad de numeros positivos encontrados.
 *
 */
int mostrarCantidadPositivos(int array[], int tam);
/** \brief Esta funcion muestra en pantalla la cantidad de numeros negativos dentro de un array
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return int La cantidad de numeros negativos encontrados.
 *
 */
int mostrarCantidadNegativos(int array[], int tam);
/** \brief Esta funcion calcula el valor maximo dentro de un array
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return max int El valor maximo encontrado en el array
 *
 */
int calcularMaximo (int array[], int tam);
/** \brief Esta funcion muestra en pantalla el valor maximo dentro de un array
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return void
 *
 */
void mostrarMaximo(int array[], int tam);
/** \brief Esta funcion muestra en pantalla la posicion del valor maximo dentro de un array
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return void
 *
 */
void mostrarPosicionMaximo (int array[], int tam);
/** \brief Esta funcion calcula el valor minimo dentro de un array
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return max int El valor minimo encontrado en el array
 *
 */
int calcularMinimo(int array[], int tam);
/** \brief Esta funcion muestra en pantalla el valor minimo dentro de un array
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return void
 *
 */
void mostrarMinimo(int array[], int tam);
/** \brief Esta funcion muestra en pantalla la posicion del valor minimo dentro de un array
 *
 * \param array[] int El array de enteros
 * \param tam int El tamaño del array
 * \return void
 *
 */
void mostrarPosicionMinimo(int array[], int tam);
/** \brief Esta funcion muestra en pantalla un menu para seleccionar si el usuario quiere mostrar el valor minimo o maximo dentro de un array
 *
 * \param array[] int El array de enteros a ordenar
 * \param tam int El tamaño del array
 * \return void
 *
 */
void menu_Mostrar_Minimo_O_Maximo(int array[], int tam);

