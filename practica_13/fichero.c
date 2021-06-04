#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Presentacion(char *entrada);

int main(void)
{
	FILE *fp;
	char fichero_entrada[] = "frases.txt";
	char c;
	int i;
	int cuantos;
	float frecuencia;
	int estadistica[256] = {0};

	Presentacion(fichero_entrada);

	if ((fp = fopen(fichero_entrada, "r")) == NULL)
	{
		printf("ERROR. NO SE PUEDE ABRIR EL FICHERO %s\n", fichero_entrada);
	}
	cuantos = 0;
	c = fgetc(fp);
	while (!feof(fp))
	{
		if (c != '\n')
		{
			estadistica[c]++;
			cuantos++;
		}
		c = fgetc(fp);
	}

	printf("Caracter ASCII Fr. Absoluta Fr. Relativa\n");
	printf("-------- ----- --- -------- --- --------\n");
	for (i = 0; i < 256; i++)
	{
		if (estadistica[i] != 0)
		{
			frecuencia = 100 * (float)estadistica[i] / cuantos;
			printf("%4c %8d %9d %15.2f\n", i, i, estadistica[i], frecuencia);
		}
		fclose(fp);
		printf("\n\n\n");
		printf("Caracteres en el fichero...: %d\n", cuantos);

		system("pause");
		return 0;
	}
}

void Presentacion(char *entrada)
{
	puts("ESTADISTICA TEXTO LIBRE PLANO");
	puts("========================================");
	puts("Genera una estadistica sobre el fichero plano");
}
