#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <ctype.h>

#include "alumno.h"
#include "auxi.h"
#include "clase.h"

void CargarArrayClaseAleatorio(Alumno *cla, int n) {
    int i, j;
    
    static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU",
        "DOMINGUEZ","FERNANDEZ","FLORIANO",
        "GONZALEZ","GOMEZ","GUTIERREZ",
        "MARTIN", "MORO", "PEREZ","TURRION",
        "ZAMBRANO"};
    static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA",
        "TOMAS", "ZOILO"};
        
    int numApellidos = sizeof(apellidos)/15;
    int numNombres = sizeof(nombres)/15;
    char buffer[5];
    
    srand(time(NULL));
    
    for (i = 0; i < n; i++) {
        sprintf(cla[i].nombre,"%s %s %s",	nombres[rand() % numNombres], 
											apellidos[rand() % numApellidos],
											apellidos[rand() % numApellidos]);
        
        cla[i].fnacimiento.anio = (rand() % 13) + 1983;
        cla[i].fnacimiento.mes = (rand() % 12) + 1;
		cla[i].fnacimiento.dia = (rand() % (DiaMaximoMesAnio(cla[i].fnacimiento.mes, cla[i].fnacimiento.anio))) +1;
		
		for (j=0; j<NOTAS; j++) {
		 	cla[i].notas[j] = rand()%11;
			if(cla[i].notas[j] != 10) cla[i].notas[j] += (rand()%10)/10;
		}
    }
}

float NotaFinalAlumno (const Alumno *alul) {
	int i;
	float notafinal = 0;
	
	for (i=0; i<NOTAS; i++) notafinal += alul->notas[i];
	notafinal /= NOTAS;
	return notafinal;	
}

void MostrarArrayClase (const Alumno *cla, int n) {
	int i,j;
	
	printf("Nombre                        F.Nacim.              Notas             Final\n");
	printf("---------------------------- ---------- ---------------------------- ------\n");
	for (i = 0; i < n; i++){
		printf("%-29s", cla[i].nombre);
		
		ImprimeFechaDD_MM_AAAA(cla[i].fnacimiento);
		
		for (j = 0; j < NOTAS; j++) printf("%5.1f ", cla[i].notas[j]);
		printf("(%4.1f)", NotaFinalAlumno(cla+i));
		printf("\n");
	}
}

float NotaMediaArrayClase (const Alumno *cla, int n) {
	int i, j;
	float notamedia = 0;
	
	for (i = 0; i < n; i++) notamedia += NotaFinalAlumno(cla+i);
	notamedia /= n;
	return notamedia;
}

Alumno MenorNotaArrayClase (const Alumno *cla, int n, Alumno *alu) {
	float notamenor;
	int i;
	int alum;
	
	notamenor = NotaFinalAlumno(cla);
	
	for (i = 1; i < n; i++) {
		if (notamenor > NotaFinalAlumno(cla+i)) {
			notamenor = NotaFinalAlumno(cla+i);
			alum = i;
		} 
	}
	return cla[alum];
}

void MayorEdadArrayClase (const Alumno *cla, int n, Alumno *alu) {
	int i;
	
	*alu = cla[0];
	
	for (i = 1; i < n; i++) {
		if ((ComparaFechas((*alu).fnacimiento, cla[i].fnacimiento)) == 1) *alu = cla[i];
        else;
	}
}