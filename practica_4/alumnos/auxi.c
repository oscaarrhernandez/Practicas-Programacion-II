#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "alumno.h"
#include "auxi.h"
#include "clase.h"

int Bisiesto (int anio) {
	if (anio % 4 != 0) return 0;
	else if (anio % 100 != 0) return 1;
	else if (anio % 400 != 0) return 0;
	else return 1;
}

long FechaAAAAMMDD (Fecha fech) {
	return (fech.anio*1000 + fech.mes*100 + fech.dia);
}

int ComparaFechas (Fecha fe1, Fecha fe2) {
	long fecha1, fecha2;
	
	fecha1 = FechaAAAAMMDD(fe1);
	fecha2 = FechaAAAAMMDD(fe2);
	
	if (fecha1 > fecha2) return 1;
	else if (fecha1 < fecha2) return -1;
	else return 0;
}

int DiaMaximoMesAnio (int mes, int anio) {
	switch (mes){
		case 1:  return 31;
		case 2:  if (Bisiesto(anio)) return 29;
				 else return 28;
		case 3:  return 31;
		case 4:  return 30;
		case 5:  return 31;
		case 6:  return 30;
		case 7:  return 31;
		case 8:  return 31;
		case 9:  return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
	}
	return -1;
}

void ImprimeFechaDD_MM_AAAA (Fecha fech) {
	printf("%2d/%02d/%4d", fech.dia, fech.mes, fech.anio);
}