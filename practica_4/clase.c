#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "clase.h"
#include "alumno.h"

void CargarArrayClaseAleatorio(Alumno *cla, int n)
{
	int i;
	static char apellidos[][15] = {"ALONSO", "ALVAREZ", "ARBESU",
																 "DOMINGUEZ", "FERNANDEZ", "FLORIANO",
																 "GONZALEZ", "GOMEZ", "GUTIERREZ",
																 "MARTIN", "MORO", "PEREZ", "TURRION",
																 "ZAMBRANO"};
	static char nombres[][15] = {"ALVARO", "ARSENIO", "DOMINGO",
															 "FELIPE", "FATIMA", "FABIAN",
															 "GONZALO", "PEDRO", "PATRICIA",
															 "TOMAS", "ZOILO"};

	int numApellidos = sizeof(apellidos) / 15;
	int numNombres = sizeof(nombres) / 15;
	char buffer[5];
	int numeromes, numeroanio, numerodia, notasn, notasd, notast;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		sprintf(cla[i].apellidos, "%s %s", apellidos[rand() % numApellidos],
						apellidos[rand() % numApellidos]);
		sprintf(cla[i].nombre, "%s", nombres[rand() % numNombres]);
		//numero = rand() % (N - M + 1) + M; // Este está entre M y N
		Fecha fech;
		numeromes = rand() % (12 - 1 + 1) + 1;
		fech.mes = numeromes;
		numeroanio = rand() % (1995 - 1983 + 1) + 1983;
		fech.anio = numeroanio;
		numerodia = rand() % (DiaMaximoMesAnio(numeromes, numeroanio) - 1 + 1) + 1;
		fech.dia = numerodia;
		ImprimeFechaDD_MM_AAAA(fech);
		notasn = rand() % 11;
		notasd = (rand() % 11) / 10;
		notast = notasn + notasd;
		sprintf(cla[i].notas, "%s", notast);
	}
}
/* void MostrarArrayClase(const Alumno *cla, int n)
{

} */
float NotaMediaArrayClase(const Alumno *cla, int n)
{
}
Alumno MenorNotaArrayClase(const Alumno *cla, int n)
{
}
void MayorEdadArrayClase(const Alumno *cla, int n, Alumno *alu)
{
}
float NotaFinalAlumno(const Alumno *alu1)
{
}
