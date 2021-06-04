#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

/* ---------------------------------------------------------- */
/* Definiciones globales                                      */
/* ---------------------------------------------------------- */
#define ALUMNOS 10 
 
#include "alumno.h"
#include "clase.h"
#include "auxi.h"

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void ModuloPrincipal (void);
void Presentacion (void);

/* ---------------------------------------------------------- */
   int main (void) {
/* ---------------------------------------------------------- */
     char respuesta;

     system("cls");
     Presentacion();
     do {
         printf("\n");
	     ModuloPrincipal();
	     printf("\n");
	     do
	       { printf("\n¿Otra ejecución (S/N)?: ");
	         fflush(stdin); /* Limpia el buffer de teclado */
	         respuesta = toupper(getchar());
	       }
	     while (respuesta != 'S' && respuesta != 'N');
	     system("cls");

    } while (respuesta != 'N');
    
    return 0;

} /* Fin del main */


/* ---------------------------------------------------------- */
void ModuloPrincipal (void) {
/* ---------------------------------------------------------- */
     int numalumnos;
     float notamedia;
     Alumno clase[ALUMNOS];
     Alumno alum_menor_nfinal;
     Alumno alum_mayor_edad;     
     
     numalumnos = ALUMNOS;

     CargarArrayClaseAleatorio (clase, numalumnos);
     
     printf ("Nombre                              ");
     printf ("F.Nacim.   Notas                     Final\n");
     printf ("----------------------------------- ");
     printf ("---------- ------------------------- ------\n");
     MostrarArrayClase (clase, numalumnos);
     
     notamedia = NotaMediaArrayClase (clase, numalumnos);
     printf("\nNota media del total de la clase: %.1f\n", notamedia);    
     
     alum_menor_nfinal = MenorNotaArrayClase (clase, numalumnos);
     printf("\nAlumno con menor nota final:\n");    
     MostrarArrayClase (&alum_menor_nfinal, 1);
     printf("Nota final del alumno: %.1f\n", NotaFinalAlumno (&alum_menor_nfinal));    
     
     printf("\n");    
     MayorEdadArrayClase (clase, numalumnos, &alum_mayor_edad);
     printf("\nAlumno de mayor edad:\n");  
     MostrarArrayClase (&alum_mayor_edad, 1);
     printf("La fecha de nacimiento del alumno:  ");    
     ImprimeFechaDD_MM_AAAA (alum_mayor_edad.fnacimiento);

}

/* ---------------------------------------------------------- */
   void Presentacion (void) {
/* ---------------------------------------------------------- */
     puts("DATOS DE UNA CLASE DE ALUMNOS");
     puts("=============================");
     puts("El programa define una clase de alumnos y ...");
     puts("   - la inicia con valores aleatorios,");
     puts("   - la presenta en pantalla, indicando los datos de cada alumno,");
     puts("   - presenta en pantalla los datos del alumno con la menor nota media,");
     puts("   - presenta en pantalla los datos del alumno con la mayor edad.");
     puts("");
}

