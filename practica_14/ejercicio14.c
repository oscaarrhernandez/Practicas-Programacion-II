#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200

int main()
{
	FILE *fp;
	char fichero_entrada[] = "fichero_entrada.txt";
	char cadena[N + 1];

	system("cls");

	if ((fp = fopen(fichero_entrada, "r")) == NULL)
	{
		printf("ERROR. No se puede abrir el fichero %s\n", fichero_entrada);
		printf("\n");
		system("pause");
		return 1;
	}

	printf("CONTENIDO DEL FICHERO %s\n", fichero_entrada);
	printf("=====================================\n");

	while (fgets(cadena, N, fp) != NULL)
	{

		printf("%s", cadena);

		if (strlen(cadena) >= 3)
			printf("%c %c\n", cadena[0], cadena[strlen(cadena) - 2]);
		else if (strlen(cadena) == 2)
			printf("%c (_)\n", cadena[0]);
		else
			printf("(linea vacia)\n");
	}

	printf("\n======================================\n");

	printf("\n\n");
	system("pause");
	return 0;
}
