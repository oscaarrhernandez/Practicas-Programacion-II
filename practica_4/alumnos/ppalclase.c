#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <ctype.h>

#include "alumno.h"
#include "auxi.h"
#include "clase.h"

#define ALUMNOS 15

void moduloprincipal(void);
void presentacion(void);

int main (void) {
    char respuesta;

    system("cls");
    presentacion();
    do { 
        printf("\n");
	    moduloprincipal();
	    printf("\n");
	    do {
            printf("Otra ejecucion (S/N)?: ");
            fflush(stdin);
	        respuesta = toupper(getchar());
	    } while (respuesta != 'S' && respuesta != 'N');
    } while (respuesta != 'N');
    
    return 0;
} /* Fin del main */

void moduloprincipal(void) {
	Alumno clase[ALUMNOS], menorNota, mayorEdad;
	int i;
    float notaMediaClase;
		
	void presentacion(void);
		
	CargarArrayClaseAleatorio(clase, ALUMNOS);
	MostrarArrayClase (clase, ALUMNOS);
		
    puts("");
    // Nota media del total de la clase
    notaMediaClase = NotaMediaArrayClase(clase, ALUMNOS);
    printf("Nota media del total de la clase: %3.2f", notaMediaClase);
    

    puts("");
	// Alumno con menor nota final
	menorNota = MenorNotaArrayClase (clase, ALUMNOS, &menorNota);
	printf("\nAlumno con menor nota final: \n");
	printf("%s  ", menorNota.nombre);
		
	ImprimeFechaDD_MM_AAAA (menorNota.fnacimiento);
		
	printf("     ");
		
	for (i = 0; i < NOTAS; i++) printf("%3.1f ", menorNota.notas[i]);
	printf("(%4.1f)", NotaFinalAlumno(&menorNota));
    printf("\nNota final del alumno: %3.2f", NotaFinalAlumno(&menorNota));
		
    puts("");
	// Alumno de ayor de edad.
	MayorEdadArrayClase (clase, ALUMNOS, &mayorEdad);
	printf("\nAlumno de mayor edad: \n");
	printf("%s  ", mayorEdad.nombre);
		
	ImprimeFechaDD_MM_AAAA (mayorEdad.fnacimiento);
		
	printf("     ");
		
	for (i = 0; i < NOTAS; i++) printf("%3.1f ", mayorEdad.notas[i]);
	printf("(%4.1f)", NotaFinalAlumno (&mayorEdad));
	printf("\nLa fecha de nacimiento del alumno: ");
	ImprimeFechaDD_MM_AAAA (mayorEdad.fnacimiento);
	puts("");
}
	
void presentacion(void) {
	puts("DATO DE UNA CLASE DE ALUMNOS");
	puts("============================");
	puts("El programa define una clase de alumnos y...");
	puts(" - la inicia con valores aleatorios,");
	puts(" - la presenta en pantalla, indicando los datos de cada alumno,");
	puts(" - presenta en pantalla los datos del alumno con la menor nota media");
	puts(" - presenta en pantalla los datos del alumno con mayor edad");
}