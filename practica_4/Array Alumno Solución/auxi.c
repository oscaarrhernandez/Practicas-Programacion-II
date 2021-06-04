#include <stdio.h>
#include <stdlib.h>

#include "alumno.h"
#include "auxi.h"

/* ---------------------------------------------------------- */
   int Bisiesto (int anio) {
/* ---------------------------------------------------------- */
   int esbisiesto = 0;
   
   if (anio % 4 != 0)    
       esbisiesto = 0;             // No es múltiplo de 4
   else if (anio % 100 != 0)
            esbisiesto = 1;        // Múltiplo de 4, no de 100
        else if (anio % 400 != 0)
                  esbisiesto = 0;  // Múltiplo de 4 y de 100, no de 400
             else esbisiesto = 1;  // Múltiplo de 4, de 100 y de 400

   return esbisiesto;
}

/* ---------------------------------------------------------- */
   int DiaMaximoMesAnio (int mes, int anio) {
/* ---------------------------------------------------------- */
// Recibe un mes y un año y devuelve el dia maximo permitido 
// para ese mes y año. Tienen en cuenta los meses de 30 y 31 
// y para Febrero 28, o 29 para años bisiestos

   if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
       return 30;
       
   if (mes == 2)
      if (Bisiesto(anio))
           return 29;
      else return 28;
      
   return 31;
   
}





/* ---------------------------------------------------------- */
   long FechaAAAAMMDD (Fecha fech) {
/* ---------------------------------------------------------- */
   long fechaAAAAMMDD;

   fechaAAAAMMDD = fech.anio * 10000 +  fech.mes * 100 + fech.dia;

   return fechaAAAAMMDD;
}

/* ---------------------------------------------------------- */
   void ImprimeFechaDD_MM_AAAA (Fecha fech) {
/* ---------------------------------------------------------- */
   printf("%2d/%02d/%4d", fech.dia, fech.mes, fech.anio);
}

/* ---------------------------------------------------------- */
   int ComparaFechas (Fecha fe1, Fecha fe2) {
/* ---------------------------------------------------------- */
// Retorna -1 si la primera fecha es menor que la segunda
// Retorna  0 si ambas fechas son iguales
// Retorna  1 si la primera fecha es mayor que la segunda
   long fecha1, fecha2;
   
   fecha1 = FechaAAAAMMDD (fe1);
   fecha2 = FechaAAAAMMDD (fe2);
   
   if (fecha1 < fecha2) 
       return -1;
   else if (fecha2 == fecha1) 
             return  0;
        else return  1;
}
