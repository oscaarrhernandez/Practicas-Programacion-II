#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	//PRESENTACION
	puts("PROGRAMA PARA REALIZAR SORTEOS");
	puts("==============================");

	//SOLICITUD DE DATOS
	int numparticipantes, numpremios;
	do
	{
		do
		{
			printf("Introduzca numero participantes en sorteo (entre 10 y 100): ");
			scanf("%d", &numparticipantes);
		} while (numparticipantes < 10 || numparticipantes > 100);
		do
		{
			printf("Introduzca numero premios a sortear (entre 10 y 100): ");
			scanf("%d", &numpremios);
		} while (numpremios < 10 || numpremios > 100);
		if (numpremios >= numparticipantes)
		{
			puts("EL NUMERO DE PREMIOS DEBE DE SER MENOR AL NUMERO DE PARTICIPANTES.");
		}
	} while (numpremios >= numparticipantes);

	//CREAR UN ARRAY DINAMICO
	int *vectpremiados;
	vectpremiados = (int *)malloc(numpremios * sizeof(int));
	//COMPROBACION DEL ARRAY DINAMICO
	if (vectpremiados == NULL)
	{
		puts("ERROR EN LA ASIGNACION DE MEMORIA DINAMICA");
		exit(-1);
	}
	//CARGAR VECTOR
	int repetido;												 // Flag para comprobar si hay elementos repetidos
	for (int i = 0; i < numpremios; i++) // OJO, el vector será hasta 'numpremios'
	{
		do
		{																													// do-while para comprobar repetidos
			repetido = 0;																						// repetido = 0
			vectpremiados[i] = rand() % (numparticipantes + 1) + 1; // OJO, 'vectpremiados' será aleatorio entre todos los participantes

			if (i != 0)
			{ // Comprobar repetidos
				for (int j = i - 1; j >= 0; j--)
				{ // Recorremos desde el último numero introducido
					if (vectpremiados[i] == vectpremiados[j])
					{								// Comparamos el inicial con el resto
						repetido = 1; // Si está repetido activamos el flag
					}
				}
			}
		} while (repetido == 1); // Repite el proceso en caso de tener numeros iguales
	}

	//ORDENAR VECTOR METODO BURBUJA
	int auxi;
	for (int j = 0; j < numpremios - 1; j++)
	{
		for (int f = 1; f < numpremios; f++)
		{
			if (vectpremiados[f] < vectpremiados[f - 1])
			{
				auxi = vectpremiados[f];
				vectpremiados[f] = vectpremiados[f - 1];
				vectpremiados[f - 1] = auxi;
			}
		}
	}
	//PRESENTACION DE NUMEROS PREMIADOS
	printf("LOS %d NUMEROS PREMIADOS EN EL SORTEO SON...\n", numpremios);
	for (int k = 0; k < numpremios; k++)
	{
		printf("  %d  ", vectpremiados[k]);
	}
	puts("\n");
	//LIBERAR MEMORIA RESERVADA
	free(vectpremiados);

	return 0;
}
