#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "empleado.h"

tipoEmpleado *crearVectorRegistros(int numEmpleados, int *errNum)
{
	tipoEmpleado *res;
	if (numEmpleados < 1) //Primero comprobamos que el numero de empleados sea mayor a 1 para que no de error la malloc
	{
		fprintf(stderr, "Error: Numero de empleados invalido.\n");
		*errNum = -1;
		return NULL;
	}
	if ((res = malloc(numEmpleados * sizeof(tipoEmpleado))) == NULL) //Si no tiene exito la reserva de memoria ocurre este if
	{
		fprintf(stderr, "Error: Creacion de memoria dinamica.\n");
		*errNum = -2;
		return NULL;
	}
	*errNum = 0;
	return res;
}

tipoEmpleado **crearRegistrosRef(int numEmpleados, int *errNum)
{
	tipoEmpleado **res; //Primero comprobamos que el numero de empleados sea mayor a 1 para que no de error la malloc
	if (numEmpleados < 1)
	{
		fprintf(stderr, "Error: Numero de empleados invalido.\n");
		*errNum = -1;
		return NULL;
	}
	if ((res = malloc(numEmpleados * sizeof(tipoEmpleado *))) == NULL) //Si no tiene exito la reserva de memoria ocurre este if
	{
		fprintf(stderr, "Error: Creacion memoria dinamica.\n");
		*errNum = -2;
		return NULL;
	}
	else //Si tiene exito:
	{
		for (int i = 0; i < numEmpleados; i++) //Comprobamos uno a uno que no haya ninguno mal
		{
			if ((res[i] = malloc(sizeof(tipoEmpleado))) == NULL) //Si da alguno error:
			{
				fprintf(stderr, "Error: Creacion memoria dinamica.\n");
				for (--i; i >= 0; i--) //Recorremos desde el ultimo guardado hasta el 0 limpiando la memoria
				{
					free(res[i]);
				}
				free(res); //Limpiamos el vector
				*errNum = -3;
				return NULL;
			}
		}
	}
	*errNum = 0;
	return res;
}

int liberarMemRegistrosRef(tipoEmpleado **empleadosRef, size_t numEmpleados) //Libera toda la memoria reservada.
																																						 //Recordad que estamos haciendo un vector de vectores
{
	if (empleadosRef == NULL)
	{
		fprintf(stderr, "Error: Liberar memoria registros ref.\n");
		return -1;
	}
	for (int i = 0; i < numEmpleados; i++)
	{
		free(empleadosRef[i]);
	}
	free(empleadosRef);
	empleadosRef = NULL;

	return 0;
}

int cargarRegistroAleatorio(tipoEmpleado *empleado)
{
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

	if (empleado == NULL)
	{
#ifdef DEBUG
		fprintf(stderr, "Error: registro no válido!\n");
#endif
		return -1;
	}

	sprintf(empleado->apellidos, "%s %s", apellidos[rand() % numApellidos],
					apellidos[rand() % numApellidos]);
	sprintf(empleado->nombre, "%s", nombres[rand() % numNombres]);
	sprintf(buffer, "%c%c%c%c", (char)('0' + rand() % 10),
					(char)('0' + rand() % 10),
					(char)('0' + rand() % 10),
					(char)('0' + rand() % 10));
	empleado->matricula = atoi(buffer);
	return 0;
}

int cargarRegistrosAleatorios(tipoEmpleado *empleados, int numEmpleados)
{
	if (empleados == NULL) //Si no hay empleados no hay nada que cargar
	{
		fprintf(stderr, "Error:Carga registros.\n");
		return -1;
	}
	for (int i = 0; i < numEmpleados; i++) //Cargamos a través de un for los registros usando la func. cargarRegistroAleatorio
	{
		cargarRegistroAleatorio(empleados + i);
	}
	return 0;
}

int cargarRegistrosAleatoriosRef(tipoEmpleado **empleados, int numEmpleados)
{
	if (empleados == NULL) //Si no hay empleados no hay nada que cargar
	{
		fprintf(stderr, "Error: Carga registros.\n");
		return -1;
	}
	for (int i = 0; i < numEmpleados; i++) //Cargamos a través de un for los registros usando la func. cargarRegistroAleatorio
	{
		cargarRegistroAleatorio(*(empleados + i));
	}
	return 0;
}

void cargarUnRegistro(tipoEmpleado *empleado)
{
	printf("Introducir el apellido \n");
	gets(empleado->apellidos);
	printf("Introducir el nombre \n");
	gets(empleado->nombre);
	printf("Introducir el número de matrícula \n");
	scanf("%d%*c", &(empleado->matricula));
}

void mostrarRegistro(tipoEmpleado empleado)
{
	printf("%s, %s %d\n", empleado.apellidos, empleado.nombre, empleado.matricula);
}

void mostrarRegistros(tipoEmpleado *empleados, int numEmpleados)
{
	int i;
	for (i = 0; i < numEmpleados; i++)
		printf("%s, %s %d\n", empleados[i].apellidos, empleados[i].nombre, empleados[i].matricula);
}

void mostrarRegistrosRef(tipoEmpleado **refsEmpleados, int numEmpleados)
{
	int i;

	for (i = 0; i < numEmpleados; i++)
	{
		printf("%s, %s %d\n", refsEmpleados[i]->apellidos, refsEmpleados[i]->nombre, refsEmpleados[i]->matricula);
	}
}

void ordenarRegistrosApellido(tipoEmpleado *empleados, int numEmpleados)
{
	int i, j;
	tipoEmpleado temp;

	for (i = 0; i < numEmpleados - 1; i++)
	{
		for (j = numEmpleados - 1; j > i; j--)
		{
			if ((strcmp(empleados[j].apellidos, empleados[j - 1].apellidos)) < 0)
			{
				temp = empleados[j];
				empleados[j] = empleados[j - 1];
				empleados[j - 1] = temp;
			}
		}
	}
}

void ordenarRegistrosRefApellido(tipoEmpleado **refsEmpleados, int numEmpleados)
{
	int i, j;
	tipoEmpleado *temp;

	for (i = 0; i < numEmpleados - 1; i++)
	{
		for (j = numEmpleados - 1; j > i; j--)
		{
			if ((strcmp(refsEmpleados[j]->apellidos, refsEmpleados[j - 1]->apellidos)) < 0)
			{
				temp = refsEmpleados[j];
				refsEmpleados[j] = refsEmpleados[j - 1];
				refsEmpleados[j - 1] = temp;
			}
		}
	}
}
