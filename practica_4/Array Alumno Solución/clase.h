// Fichero de cabecera clase.h
#ifndef __CLASE_H__
#define __CLASE_H__

#include "alumno.h"

void CargarArrayClaseAleatorio (Alumno *cla, int n);
void MostrarArrayClase (const Alumno *cla, int n);
float NotaMediaArrayClase (const Alumno *cla, int n);
Alumno MenorNotaArrayClase (const Alumno *cla, int n);
void MayorEdadArrayClase (const Alumno *cla, int n, Alumno *alu);

float NotaFinalAlumno (const Alumno *alu1);

#endif
