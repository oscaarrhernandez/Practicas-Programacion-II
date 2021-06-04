#ifndef __AUXI_H__
#define __AUXI_H__
#include "alumno.h"

int Bisiesto (int anio);
int DiaMaximoMesAnio (int mes, int anio);//Recibe un mes y un año y devuelve el día máximo permitido para ese mes y
																				 //año. Tienen en cuenta los meses de 30 y 31, y para Febrero 28, o 29 para años
																				 //bisiestos.
long FechaAAAAMMDD (Fecha fech);				 //Convierte una Fecha a un long.
void ImprimeFechaDD_MM_AAAA (Fecha fech);//Imprime una Fecha en formato %2d/%02d/%4d
int ComparaFechas (Fecha fe1, Fecha fe2);//Compara dos Fechas y retorna -1 si la primera fecha es menor que la
																				 //segunda; 0 si ambas fechas son iguales; 1 si la primera fecha es mayor que la
																				 //segunda

#endif
