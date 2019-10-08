#include "fechas.h"

eFecha pedirFecha(){
       eFecha laFecha;
       laFecha.day = getInt("Ingrese el dia: ");
       laFecha.month = getInt("Ingrese el mes: ");
       laFecha.year = getInt("Ingresre el anio: ");
    return laFecha;
}
