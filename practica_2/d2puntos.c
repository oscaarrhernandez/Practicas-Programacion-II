/* Fuente: PUNTO2D.C
   Programa: MANEJO DE LOS PUNTOS DEL PLANO en negativos MEDIANTE ESTRUCTURAS
   Descripción: Mediante funciones que manejan estructuras que representan los puntos del plano en negativos,
   se realizan las siguientes operaciones.
			  - Leer un punto de teclado
			  - Presentar un punto en pantalla
			  - Dados dos puntos, calcular la distancia entre ellos
			  - Dados dos puntos, determinar el punto medio de la linea que los une.
			  - Dados dos puntos, indicar que figura definen
			  - Dados dos puntos, calcular el area de la figura que definen
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/* ---------------------------------------------------------- */
/* Definiciones globales*/
/* ---------------------------------------------------------- */
typedef struct
{
	float x;
	float y;
} Punto;

typedef enum
{
	CUADRADO,
	RECTANGULO,
	PUNTO,
	LINEA_VERTICAL,
	LINEA_HORIZONTAL
} Figura;

/* ---------------------------------------------------------- */
/* Prototipos*/
/* ---------------------------------------------------------- */
void ModuloPrincipal(void);
void Presentacion(void);
void LeerPunto(Punto *);
void EscribirPunto(Punto);
float DistanciaPuntos(Punto, Punto);
Punto PuntoMedio(Punto, Punto);
Figura FiguraDefinenPuntos(Punto, Punto);
float AreaFiguraPuntos(Punto, Punto);

/* ---------------------------------------------------------- */
int main(void)
{
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
	Punto p1, p2, ptot;
	float dist, area;
	Figura figu;

	puts("Introduzca el primer punto: ");
	LeerPunto(&p1);

	puts("\n\nIntroduzca el segundo punto: ");
	LeerPunto(&p2);

	printf("\n\nEL PUNTO 1: ");
	EscribirPunto(p1);
	printf("\nEL PUNTO 2: ");
	EscribirPunto(p2);

	dist = DistanciaPuntos(p1, p2);
	printf("\n\nDistancia entre los puntos: %0.lf", dist);

	ptot = PuntoMedio(p1, p2);
	printf("\n\nPunto medio: x: %.2lf   y: %.2lf", ptot.x, ptot.y);

	figu = FiguraDefinenPuntos(p1, p2);
	printf("\n\nFigura que generan: %d", figu);
	if (figu == 2)
		printf(" (PUNTO)");
	if (figu == 3)
		printf(" (LINEA VERTICAL)");
	if (figu == 4)
		printf(" (LINEA HORIZONTAL)");

	if (figu == 0 || figu == 1)
	{
		if (figu == 0)
			printf(" (CUADRADO)");
		if (figu == 1)
			printf(" (RECTANGULO)");
		area = AreaFiguraPuntos(p1, p2);
		printf("\n\nEl area de la figura: %.2lf\n", area);
	}
}

/* ---------------------------------------------------------- */
void LeerPunto(Punto *p)
{
	printf("Coordenada X? ");
	scanf("%f", &p->x);
	printf("Coordenada Y? ");
	scanf("%f", &p->y);
}

/* ---------------------------------------------------------- */
void EscribirPunto(Punto p)
{
	printf("(%4.2f, %4.2f)", p.x, p.y);
}

/* ---------------------------------------------------------- */
float DistanciaPuntos(Punto p1, Punto p2)
{
	float distancia;
	distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return distancia;
}

/* ---------------------------------------------------------- */
Punto PuntoMedio(Punto p1, Punto p2)
{
	Punto p3;
	p3.x = (p1.x + p2.x) / 2;
	p3.y = (p1.y + p2.y) / 2;
	return p3;
}

/* ---------------------------------------------------------- */
Figura FiguraDefinenPuntos(Punto p1, Punto p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
	{
		return PUNTO;
	}
	else if (p1.x == p2.x && p1.y != p2.y)
	{
		return LINEA_VERTICAL;
	}
	else if (p1.x != p2.x && p1.y == p2.y)
	{
		return LINEA_HORIZONTAL;
	}
	else
	{
		Punto p4;
		p4.x = p2.x;
		p4.y = p1.y;
		float L1, L2;
		L1 = (DistanciaPuntos(p1, p4));
		L2 = (DistanciaPuntos(p4, p2));
		if (L1 == L2)
		{
			return CUADRADO;
		}
		else
		{
			return RECTANGULO;
		}
	}
}

/* ---------------------------------------------------------- */
float AreaFiguraPuntos(Punto p1, Punto p2)
{
	Punto p4;
	p4.x = p2.x;
	p4.y = p1.y;
	float L1, L2, area;
	L1 = DistanciaPuntos(p1, p4);
	L2 = DistanciaPuntos(p4, p2);
	area = L1 * L2;
	return area;
}

/* ---------------------------------------------------------- */
void Presentacion(void)
{
	puts("DISTANCIA ENTRE PUNTOS DEL PLANO en negativos");
	puts("================================");
	puts("Dados dos puntos del plano en negativos, calcula la distancia y el punto medio entre ellos.");
	puts("Ademas indica si delimitan un rectangulo o un cuadrado y el area del mismo.");
	puts("");
}
