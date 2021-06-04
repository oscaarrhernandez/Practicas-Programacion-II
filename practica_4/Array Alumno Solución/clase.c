#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#include "alumno.h"
#include "clase.h"

#define NOM       15
#define ANIO_MIN  1983
#define ANIO_MAX  1995

/* ---------------------------------------------------------- */
   void CargarArrayClaseAleatorio (Alumno *cla, int n) {
/* ---------------------------------------------------------- */

    int i, j;
    int valido;
    int elmes, eldia, elanio;
    char apellidos [][NOM] = {
    	"ALONSO", "ALVAREZ", "ARBESU",
        "DOMINGUEZ", "FERNANDEZ", "FLORIANO",
        "GONZALEZ", "GOMEZ", "GUTIERREZ",
        "MARTIN", "MORO", "PEREZ", "TURRION",
        "ZAMBRANO"};
    char nombres [][NOM] = {
    	"ALVARO", "ARSENIO", "DOMINGO",
        "FELIPE", "FATIMA", "FABIAN",
        "GONZALO", "PEDRO", "PATRICIA",
        "TOMAS", "ZOILO"};

    int num_apellidos = sizeof(apellidos)/NOM;  // Numero de apellidos
    int num_nombres   = sizeof(nombres)/NOM;    // Numero de nombres 
       // sizeof(apellidos), sizeof(nombres) devuelve el numero de bytes de la tabla.
       // Al dividirlo por lo que ocupa una fila, obtenemos el numero de filas.

    srand(time(NULL));
    
    for (i=0; i < n; i++) { // (**1**)
        sprintf(cla[i].nombre, "%s %s %s", apellidos[rand() % num_apellidos],
                                           apellidos[rand() % num_apellidos],
                                           nombres[rand() % num_nombres]);
                 // [rand() % num_apellidos] obtiene un numero entre 0 y 
                 // num_apellidos-1, es decir los indices validos del array apellidos[]
                 
                 // sprintf es equivalente a printf, pero la salida se almacene en
                 // la cadena aportada como primer argumento.

        cla[i].fnacimiento.anio = elanio = (rand() % (ANIO_MAX-ANIO_MIN+1)) + ANIO_MIN;
                 // anio de nacimiento entre ANIO_MIN y ANIO_MAX
        cla[i].fnacimiento.mes = elmes = (rand() % 12) + 1;
                 // mes de nacimiento entre 1 y 12

       /* Una opcion es generar aleatoriamente un día entre 1 y 31 y validar que es 
          correcto segun el mes y año, y en caso de que no lo sea se vuelve a generar
          ----------------------------------------------------------------------------
        do {         
           valido = 1; // Flag a cierto
           cla[i].fnacimiento.dia = eldia = (rand() % 31)+ 1;
                    // dia de nacimiento entre 1 y 31
           if (eldia == 31 && (elmes == 4 || elmes == 6 || elmes == 9 || elmes == 11))
               valido = 0;
           else if (eldia >= 30 && elmes == 2)
               valido = 0;
           else if (eldia == 29 && !Bisiesto(elanio))
               valido = 0;
                    
        } while (!valido);
       */

       /* Otra opcion es primero calcular el día maximo que tiene ese mes y dia, y 
          generar posteriormente un dia de forma aleatoria en el rango 1 y el valor
          maximo antes calculado
          ----------------------------------------------------------------------------  */
        cla[i].fnacimiento.dia = (rand() % DiaMaximoMesAnio(elmes, elanio))+1;


        for (j=0; j<NOTAS; j++)
             cla[i].notas[j] = ((rand()%101)/10.0); 
                 // Nota entre 0 y 10 con un decimal
                                                 
    } // Final del for (**1**)

}

/* ---------------------------------------------------------- */
   float NotaFinalAlumno (const Alumno *alu1) {
/* ---------------------------------------------------------- */
   float notafinal = 0;
   int j;

   for (j=0; j<NOTAS; j++)
      notafinal += alu1->notas[j];
      
   notafinal /= NOTAS;
   
   return (notafinal);

}

/* ---------------------------------------------------------- */
   void MostrarArrayClase (const Alumno *cla, int n) {
/* ---------------------------------------------------------- */
   int i, j;
     
   for (i=0; i < n; i++) { // (**1**)
      printf("%-35s ", cla[i].nombre);
      ImprimeFechaDD_MM_AAAA (cla[i].fnacimiento);
      printf(" ");
      for (j=0; j<NOTAS; j++) 
          printf("%5.1f", cla[i].notas[j]);
      printf(" (%4.1f)\n", NotaFinalAlumno (&cla[i]));    
   } // Final del for (**1**)

}
 
/* ---------------------------------------------------------- */
   float NotaMediaArrayClase (const Alumno *cla, int n) {
/* ---------------------------------------------------------- */
   int i, j;
   float notamedia_total;
   int tot;

   notamedia_total = 0;
   tot = 0;
   
   for (i=0; i < n; i++) 
      for (j=0; j<NOTAS; j++) {
         notamedia_total+= cla[i].notas[j];
         tot++;
      }
   
   notamedia_total /= tot;
   
   return (notamedia_total);
}  

/* ---------------------------------------------------------- */
   Alumno MenorNotaArrayClase (const Alumno *cla, int n) {
/* ---------------------------------------------------------- */
   int ind; // Indice del alumno del array con menor nota
   int i, j;
   float notafinal;
   float notafinal_minima;

   // La nota final minima sera por ahora la del primer alumno
   notafinal_minima =  NotaFinalAlumno (&cla[0]);
   ind = 0;

   for (i=1; i < n; i++) {
      notafinal = NotaFinalAlumno (&cla[i]);
      if (notafinal <= notafinal_minima) { // Con <= nos quedamos con el ultimo
          notafinal_minima = notafinal;    // en caso de que varios tengan la 
          ind = i;                         // misma nota final
      }
   }
   
   return (cla[ind]);
}  

/* ---------------------------------------------------------- */
   void MayorEdadArrayClase (const Alumno *cla, int n, Alumno *alu) {
/* ---------------------------------------------------------- */
   int i;
   Fecha  fnac_min;
   Fecha  fnac;

   // El alumno con mayor edad es el que tiene la fecha de nacimiento menor
   // El alumno con mayor edad sera por ahora el primero
   fnac_min = cla[0].fnacimiento;
   *alu = cla[0];

   for (i=1; i < n; i++) {
      if (ComparaFechas(fnac_min, cla[i].fnacimiento) == 1 ) { // La primera fecha es mayor que la segunda
          fnac_min = cla[i].fnacimiento;             // No preguntamos por valor devuelto 0 por lo que siempre
          *alu = cla[i];                             // nos quedamos con el primer alumno localizado 
      }
   }
   
}  
