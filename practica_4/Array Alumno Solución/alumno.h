// Fichero de cabecera alumno.h
#ifndef __ALUMNO_H__
#define __ALUMNO_H__

#define NOTAS 5

typedef struct {
   int dia;
   int mes;
   int anio;
} Fecha;

typedef struct {
   char  nombre [81];
   Fecha fnacimiento;
   float notas[NOTAS];
} Alumno;

#endif
