#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

typedef struct empleados
{
	char apellidos[30];
	char nombre[15];
	int matricula;
	//char bufferRelleno[50000];
} tipoEmpleado;

void cargarRegistrosAleatorios(tipoEmpleado *empleados, int numEmpleados);
void cargarUnRegistro(tipoEmpleado *empleado);

void mostrarRegistro(tipoEmpleado empleado);
void mostrarRegistrosRef(tipoEmpleado **refsEmpleados, int numEmpleados);
void mostrarRegistros(tipoEmpleado *empleados, int numEmpleados);

void ordenarRegistrosRefApellido(tipoEmpleado **refsEmpleados, int numEmpleados);
void ordenarRegistrosApellido(tipoEmpleado *empleados, int numEmpleados);

//parte mejora-------------------------------------------------------------------------
void ordenarRegistrosRefNombre(tipoEmpleado **refsEmpleados, int numEmpleados);
void ordenarRegistrosNombre(tipoEmpleado *empleados, int numEmpleados);
void ordenarRegistrosRefMatricula(tipoEmpleado **refsEmpleados, int numEmpleados);
void ordenarRegistrosMatricula(tipoEmpleado *empleados, int numEmpleados);
int buscarRegistroNombre(char *nombre, tipoEmpleado *empleados, int numEmpleados);
int buscarRegistroRefNombre(char *nombre, tipoEmpleado **refsEmpleados, int numEmpleados);
//-------------------------------------------------------------------------------------

#define NUM_EMPLEADOS 10

int main(void)
{
	tipoEmpleado regEmpleados[NUM_EMPLEADOS] /*vector tipo struct tipoEmpleado de NUM_EMPLEADOS de dimension*/, unEmpleado;
	tipoEmpleado *regEmpleadosRef[NUM_EMPLEADOS] /*vector por referencia tipo struct tipoEmpleado de NUM_EMPLEADOS de dimension*/;
	int i;
	clock_t tiempoInicial, tiempoFinal;
	char nombreABuscar[15];
	int nombreEncontrado = 0;

	cargarRegistrosAleatorios(regEmpleados, NUM_EMPLEADOS);

	//mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

	printf("\n\n Jugando con un único registro: \n");
	unEmpleado = regEmpleados[2];
	mostrarRegistro(unEmpleado);
	mostrarRegistro(regEmpleados[2]);
	mostrarRegistros(&unEmpleado, 1);

	//    cargarUnRegistro(&unEmpleado);
	//    printf("\n\nEl registrocargado es: \n");
	//    mostrarRegistro(unEmpleado);
	//    printf("\ny el registro regEmpleados[2] es: \n");
	//    mostrarRegistro(regEmpleados[2]);

	for (i = 0; i < NUM_EMPLEADOS; i++)
		regEmpleadosRef[i] = &regEmpleados[i];

	printf("\n\nValores no clasificados (a través matriz punteros): \n");
	mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

	tiempoInicial = tiempoFinal = clock();
	ordenarRegistrosRefApellido(regEmpleadosRef, NUM_EMPLEADOS);
	tiempoFinal = clock();

	printf("\n\nValores clasificados (a través matriz punteros): \n");
	printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
	mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

	printf("\n\nAhora valores no clasificados matriz de registros original: \n");
	mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

	tiempoInicial = tiempoFinal = clock();
	ordenarRegistrosApellido(regEmpleados, NUM_EMPLEADOS);
	tiempoFinal = clock();

	printf("\n\nAhora valores clasificados matriz de registros original: \n");
	printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
	mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

	//mejora----------------------------------------------------------------------------------
	puts("\n\n");
	printf("\n\nValores no clasificados (a través matriz punteros): \n");
	mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

	tiempoInicial = tiempoFinal = clock();
	ordenarRegistrosRefNombre(regEmpleadosRef, NUM_EMPLEADOS);
	tiempoFinal = clock();

	printf("\n\nValores clasificados (a través matriz punteros): \n");
	printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
	mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

	printf("\n\nAhora valores no clasificados matriz de registros original: \n");
	mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

	tiempoInicial = tiempoFinal = clock();
	ordenarRegistrosNombre(regEmpleados, NUM_EMPLEADOS);
	tiempoFinal = clock();

	printf("\n\nAhora valores clasificados matriz de registros original: \n");
	printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
	mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

	puts("\n\n");
	printf("\n\nValores no clasificados (a través matriz punteros): \n");
	mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

	tiempoInicial = tiempoFinal = clock();
	ordenarRegistrosRefMatricula(regEmpleadosRef, NUM_EMPLEADOS);
	tiempoFinal = clock();

	printf("\n\nValores clasificados (a través matriz punteros): \n");
	printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
	mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

	printf("\n\nAhora valores no clasificados matriz de registros original: \n");
	mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

	tiempoInicial = tiempoFinal = clock();
	ordenarRegistrosMatricula(regEmpleados, NUM_EMPLEADOS);
	tiempoFinal = clock();

	printf("\n\nAhora valores clasificados matriz de registros original: \n");
	printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
	mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

	printf("\n\nIntroduzca el nombre del usuario a buscar y modificar:\n");
	gets(nombreABuscar);

	nombreEncontrado = buscarRegistroNombre(nombreABuscar, regEmpleados, NUM_EMPLEADOS);

	if (nombreEncontrado != -1)
	{
		printf("El primer usuario encontrado se encuentra en el registro numero %d\n", nombreEncontrado + 1);
		printf("Se procede a modificar dicho registro:\n");
		modificarRegistro(&regEmpleados[nombreEncontrado]);
		mostrarRegistros(regEmpleados, NUM_EMPLEADOS);
	}
	else
	{
		printf("No se ha encontrado ningun usuario con ese nombre.\n");
	}
	return 0;
}

void cargarRegistrosAleatorios(tipoEmpleado *empleados, int numEmpleados)
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

	srand(time(NULL));
	for (i = 0; i < numEmpleados; i++)
	{
		sprintf(empleados[i].apellidos, "%s %s", apellidos[rand() % numApellidos],
						apellidos[rand() % numApellidos]);
		sprintf(empleados[i].nombre, "%s", nombres[rand() % numNombres]);
		sprintf(buffer, "%c%c%c%c", (char)('0' + rand() % 10),
						(char)('0' + rand() % 10),
						(char)('0' + rand() % 10),
						(char)('0' + rand() % 10));
		empleados[i].matricula = atoi(buffer);
	}
}

void cargarUnRegistro(tipoEmpleado *empleado)
{
	/*
     * Esta función recibe un ÚNICO REGISTRO de tipo tipoEmpleado
     * y el alumno debe escribir el código necesario para que
     * se pidan los datos necesarios por pantalla y cargar
     * los campos del registro con los datos introducidos 
     * por teclado por el usuario
  */
	printf("Introducir el apellido: \n");
	gets(empleado->apellidos); //recuerda que al ser cadena usamos gets no scanf
	printf("Introducir el nombre: \n");
	gets(empleado->nombre);
	printf("Introducir el numero de matricula: \n");
	scanf("%d%*c", &(empleado->matricula)); // No se porque se usa el %d%*c
}

void mostrarRegistro(tipoEmpleado empleado)
{
	/*
     * Esta función muestra por pantalla y en una única línea 
     * los datos almacenados en los campos del registro
     * recibido
  */
	printf("%c , %c, %d\n", empleado.apellidos, empleado.nombre, empleado.matricula);
}

void mostrarRegistros(tipoEmpleado *empleados, int numEmpleados)
{
	/*
     * Esta función recibe un vector de registros de tipoEmpleado
     * de tamaño numEmpleados, y muestra por pantalla el contenido
     * de los campos de todos los registros de dicho vector, un 
     * registro por línea
  */
	for (int i = 0; i < numEmpleados; i++)
	{
		printf("%s , %s , %d", empleados[i].apellidos, empleados[i].nombre, empleados[i].matricula);
	}
}

void mostrarRegistrosRef(tipoEmpleado **refsEmpleados, int numEmpleados)
{
	/*
     * Esta función recibe un vector de  punteros a registros de
     * tipoEmpleado, de tamaño numEmpleados (el vector), y muestra por pantalla
     * el contenido de los campos de todos los registros referenciados
     * por los punteros del vector, mostrando un registro por línea
     */
	for (int i = 0; i < numEmpleados; i++)
	{
		printf("%s, %s, %d \n", refsEmpleados[i]->apellidos, refsEmpleados[i]->nombre, refsEmpleados[i]->matricula);
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
	/*
         * Esta función es análoga a la función ordenarRegistrosApellido
         * pero con la diferencia que en vez de recibir un vector de 
         * registros, recibe un vector de punteros a registros. La función
         * utiliza el mismo algoritmo de ordenación (burbuja) para ordenar
         * pero en vez de ordenar los registros, se ordenará el vector
         * de punteros, utilzando la información del campo apellidos
         * del registro apuntado. 
  */
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

//EJERCICIO MEJORA
void ordenarRegistrosNombre(tipoEmpleado *empleados, int numEmpleados)
{
	int i, j;
	tipoEmpleado temp;

	for (i = 0; i < numEmpleados - 1; i++)
	{
		for (j = numEmpleados - 1; j > i; j--)
		{
			if ((strcmp(empleados[j].nombre, empleados[j - 1].nombre)) < 0)
			{
				temp = empleados[j];
				empleados[j] = empleados[j - 1];
				empleados[j - 1] = temp;
			}
		}
	}
}

void ordenarRegistrosRefNombre(tipoEmpleado **refsEmpleados, int numEmpleados)
{

	int i, j;
	tipoEmpleado *temp;
	for (i = 0; i < numEmpleados - 1; i++)
	{
		for (j = numEmpleados - 1; j > i; j--)
		{
			if ((strcmp(refsEmpleados[j]->nombre, refsEmpleados[j - 1]->nombre)) < 0)
			{
				temp = refsEmpleados[j];
				refsEmpleados[j] = refsEmpleados[j - 1];
				refsEmpleados[j - 1] = temp;
			}
		}
	}
}

void ordenarRegistrosRefMatricula(tipoEmpleado **refsEmpleados, int numEmpleados)
{

	int i, j;
	tipoEmpleado *temp;
	for (i = 0; i < numEmpleados - 1; i++)
	{
		for (j = numEmpleados - 1; j > i; j--)
		{
			if ((refsEmpleados[j]->matricula, refsEmpleados[j - 1]->matricula) < 0)
			{
				temp = refsEmpleados[j];
				refsEmpleados[j] = refsEmpleados[j - 1];
				refsEmpleados[j - 1] = temp;
			}
		}
	}
}

void ordenarRegistrosMatricula(tipoEmpleado *empleados, int numEmpleados)
{
	int i, j;
	tipoEmpleado temp;
	for (i = 0; i < numEmpleados - 1; i++)
	{
		for (j = numEmpleados - 1; j > i; j--)
		{
			if ((empleados[j].matricula, empleados[j - 1].matricula) < 0)
			{
				temp = empleados[j];
				empleados[j] = empleados[j - 1];
				empleados[j - 1] = temp;
			}
		}
	}
}

int buscarRegistroNombre(char *nombre, tipoEmpleado *empleados, int numEmpleados)
{

	int j = 0;

	for (int i = 0; i < numEmpleados; i++)
	{
		if (strcmp(nombre, empleados[i].nombre) == 0)
		{
			return i;
		}
		else
		{
			j++;
		}
	}

	if (j == numEmpleados)
	{
		return -1;
	}

	return 0;
}

int buscarRegistroRefNombre(char *nombre, tipoEmpleado **refsEmpleados, int numEmpleados)
{
	int j = 0;

	for (int i = 0; i < numEmpleados; i++)
	{
		if (strcmp(nombre, refsEmpleados[i]->nombre) == 0)
		{
			return i;
		}
		else
		{
			j++;
		}
	}

	if (j == numEmpleados - 1)
	{
		return -1;
	}

	return 0;
}

void modificarRegistro(tipoEmpleado *empleado)
{
	cargarUnRegistro(empleado);
}
