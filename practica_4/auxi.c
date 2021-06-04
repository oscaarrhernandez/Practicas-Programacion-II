#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "auxi.h"

int Bisiesto(int anio)
{
	/*
	Si (resto división año/4 <> 0)
			bisiesto  0 // No es múltiplo de 4
	Sino Si (resto división año/100 <> 0)
					bisiesto  1 // Múltiplo de 4, no de 100
			Sino Si (resto división año/400 <> 0)
							bisiesto  0 // Múltiplo de 4 y de 100, no de 400
					Sino bisiesto  1 // Múltiplo de 4, de 100 y de 400
	*/
	int bisiesto;
	if ((anio % 4) != 0)
	{
		bisiesto = 0; //No es multiplo de 4
	}
	else if ((anio % 100) != 0)
	{
		bisiesto = 1; //Multiplo de 4 pero no de 100
	}
	else if ((anio % 400) != 0)
	{
		bisiesto = 0; //Multiplo de 4, de 100, no de 400
	}
	else
		(bisiesto = 1);
	return bisiesto;
}
int DiaMaximoMesAnio(int mes, int anio)
{
	/*
	Recibe un mes y un año y devuelve el día máximo permitido para ese mes y
	año. Tienen en cuenta los meses de 30 y 31, y para Febrero 28, o 29 para años
	bisiestos.
	*/
	if (mes == 1 | 3 | 5 | 7 | 8 | 10 | 12)
	{
		return 31;
	}
	else if (mes == 4 | 6 | 9 | 11)
	{
		return 30;
	}
	else if (mes == 2)
	{
		if (Bisiesto(anio) == 1)
		{
			return 29;
		}
		else
			return 28;
	}
}
long FechaAAAAMMDD(Fecha fech)
{
	//año*10000 + mes*100 + día
	long AAAAMMDD;
	AAAAMMDD = (fech.anio * 10000) + (fech.mes * 100) + (fech.dia);
	return AAAAMMDD;
}
void ImprimeFechaDD_MM_AAAA(Fecha fech)
{
	//Imprime una Fecha en formato %2d/%02d/%4d
	printf("%2d/%02d/%4d", fech.dia, fech.mes, fech.anio);
}
int ComparaFechas(Fecha fe1, Fecha fe2)
{
	//Compara dos Fechas y retorna - 1 si la primera fecha es menor que la
	//segunda; 0 si ambas fechas son iguales; 1 si la primera fecha es mayor que la segunda

	if ((FechaAAAAMMDD(fe1)) > (FechaAAAAMMDD(fe2)))
	{
		return 1;
	}
	else if ((FechaAAAAMMDD(fe1)) < (FechaAAAAMMDD(fe2)))
	{
		return -1;
	}
	else
		return 0;
}
