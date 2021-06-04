/* Fuente: POLINOMIO.C*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void ModuloPrincipal(void);
void Presentacion(void);
int *CrearPolinomio(int);
float EvaluarPolinomio(int *, int, float);
void LiberarMemoria(int *);
void PresentarPolinomio(int *, int);

/* ---------------------------------------------------------- */
int main(void)
{
	/* ---------------------------------------------------------- */
	char respuesta;

	system("cls");
	Presentacion();
	do
	{
		printf("\n");
		ModuloPrincipal();
		printf("\n");
		do
		{
			printf("�Otra ejecuci�n (S/N)?: ");
			fflush(stdin); /* Limpia el buffer de teclado */
			respuesta = toupper(getchar());
		} while (respuesta != 'S' && respuesta != 'N');

	} while (respuesta != 'N');

	return 0;

} /* Fin del main */

/* ---------------------------------------------------------- */
void ModuloPrincipal(void)
{
	/* ---------------------------------------------------------- */
	int *poli = NULL;
	int grado;
	float valorpoli;
	float valor_x;
	do
	{
		printf("Grado del polinomio?: ");
		scanf("%d", &grado);
	} while (grado < 0);

	poli = CrearPolinomio(grado);

	printf("Polinomio generado:\n");
	PresentarPolinomio(poli, grado);

	printf("\nValor de x para evaluar el polinomio?: ");
	scanf("%f", &valor_x);

	valorpoli = EvaluarPolinomio(poli, grado, valor_x);

	printf("\nEl valor del polinomio en %g es %g\n", valor_x, valorpoli);

	LiberarMemoria(poli);
}

/* ---------------------------------------------------------- */
void Presentacion(void)
{
	/* ---------------------------------------------------------- */
	puts("EVALUACION DE POLINOMIOS");
	puts("========================");
	puts("");
}

/* ---------------------------------------------------------- */
int *CrearPolinomio(int grd)
{
	/* ---------------------------------------------------------- */
	int *vectorpoli;
	vectorpoli = (int *)malloc((grd + 1) * sizeof(int));
	if (vectorpoli == NULL)
	{
		puts("ERROR EN LA ASIGNACION DE MEMORIA DINAMICA");
		exit(-1);
	}
	for (int i = grd; i >= 0; i--)
	{
		printf("COEFICIENTE %d DEL POLINOMIO: ", i);
		scanf("%d", &vectorpoli[i]);
	}
	return vectorpoli;
}

/* ---------------------------------------------------------- */
void LiberarMemoria(int *px)
{
	/* ---------------------------------------------------------- */
	free(px);
}

/* ---------------------------------------------------------- */
void PresentarPolinomio(int *px, int grd)
{
	/* ---------------------------------------------------------- */
	for (int i = grd; i >= 0; i--)
	{
		if (grd == 0)
		{
			printf("%d", px[i]);
		}
		else if (grd == 1)
		{
			printf("%dx+", px[i]);
		}
		else
		{
			printf("%d(x^%d)+", px[i], grd);
		}
		grd--;
	}
}

/* ---------------------------------------------------------- */
float EvaluarPolinomio(int *px, int grd, float x)
{
	/* ---------------------------------------------------------- */
	float valorpoli = 0, val;
	for (int i = grd; i >= 0; i--)
	{
		val = pow(x, grd); //x^y
		valorpoli += (val * px[i]);
		grd--;
	}
	return valorpoli;
}
