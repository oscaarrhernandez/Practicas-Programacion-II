#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tipoDNI{
	int numero;
	char letra;
}tipoDNI;
typedef struct tipoExamen{
	char nombre[30];
	float nota;
	char asignatura[30];
	tipoDNI dni;
}tipoExamen;
int main(void){
	tipoExamen examen;
	char arch1="listanotas1.dat";
	char arch2="listanotas2.dat";
	
	FILE *f1,*f2,*f3;

	if ((f1 = fopen(arch1, "ab")) == NULL)
	{
		printf("Error al abrir el archivo %s",arch1);
		return -1;
	}
	fread(&examen, sizeof(tipoExamen), 1, f1);
	while(!feof(f1)){
		printf("Nombre: %s \t DNI: %d%c \t Asignatura: %s \t Nota: %.2f\n",examen.nombre,examen.dni.numero,examen.dni.letra,examen.asignatura,examen.nota);
		fread(&examen, sizeof(tipoExamen),1,f1);
	}

	fclose(f1);
}