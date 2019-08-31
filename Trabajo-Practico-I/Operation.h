/** \brief Suma los numeros ingresados.
 *
 * \param float first_number Primer numero ingresado.
 * \param float second_number Segundo numero ingresado.
 * \return int return El resultado de la suma entre los dos numeros ingresados.
 *
 */
int add_numbers (float first_number, float second_number);

/** \brief Resta los numeros ingresados.
 *
 * \param float first_number Primer numero ingresado.
 * \param float second_number Segundo numero ingresado.
 * \return int return El resultado de la resta entre los dos numeros ingresados.
 *
 */
int subtract_numbers (float first_number, float second_number);

 /** \brief Divide los numeros ingresados.
 *
 * \param float first_number Primer numero ingresado.
 * \param float y Segundo numero ingresado.
 * \return int return El resultado de la division entre los dos numeros ingresados.
 *
 */
int divide_numbers (float first_number, float second_number, char* error_message);

 /** \brief Multiplica los numeros ingresados.
 *
 * \param float first_number Primer numero ingresado.
 * \param float y Segundo numero ingresado.
 * \return int return El resultado de la multiplicacion entre los dos numeros ingresados.
 *
 */
int multiply_numbers (float first_number, float second_number);

/** \brief Calcula el factorial del numero ingresado.
 *
 * \param float first_number El numero ingresado para factorizar.
 * \return int return El resultado de la factorizacion del numero ingresado.
 *
 */
int get_factorial (float number);


 /** \brief Esta funcion valida que el retorno de una funcion int sea 0 (no hubo error) o no (muestra mensaje de error).
  *
  * \param variable_to_validate Esta es la variable a validar.
  * \return int retorno Retorna 0 si no hubo error o 1 si hubo un error.
  *
  */
int validate (int variable_to_validate)


