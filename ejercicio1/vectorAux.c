#include <stdio.h>
#include <stdlib.h>
#include "vectorAux.h"

int cargarValoresAleatorios(int *vector, int tam, int rangoInf, int rangoSup)
{
	if (vector == NULL)
	{
		return 1;
	}
	for (int i = 0; i < tam; i++)
	{
		vector[i] = rand() % (rangoSup - rangoInf + 1) + rangoInf;
	}
	return 0;
}

int cargarValoresTeclado(int *vector, int tam)
{
	if (vector == NULL)
	{
		return 1;
	}
	for (int i = 0; i < tam; i++)
	{
		printf("Introduce valor[%d]: ", i + 1);
		scanf("%d", &vector[i]);
	}
	return 0;
}

int mostrarValores(int *vector, int tam)
{
	if (vector == NULL)
	{
		return 1;
	}
	for (int i = 0; i < tam; i++)
	{
		printf("valor %d: %d\n", i + 1, vector[i]);
	}
	return 0;
}
