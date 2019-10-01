#include "Fechas.h"

eFechas dameUnaFecha (){

    eFechas unaFecha;
    getValidInt("Ingrese un anio: ", "\nError, solo numeros", 2000, 2019, &unaFecha.anio);
    getValidInt("Ingrese un anio: ", "\nError, solo numeros", 2000, 2019, &unaFecha.mes);
    getValidInt("Ingrese un anio: ", "\nError, solo numeros", 2000, 2019, &unaFecha.dia);

    return unaFecha;
}
