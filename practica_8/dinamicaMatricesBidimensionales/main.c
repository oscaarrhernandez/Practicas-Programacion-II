//
//  main.c
//  dinamicaMatrices
//
//  Created by Iván Álvarez Navia on 22/03/13.
//  Copyright (c) 2013 Iván Álvarez Navia. All rights reserved.
//
//No he sabido hacer este ejercicio.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrizBidimensional.h"

int main(int argc, const char *argv[])
{
	char menu[] = "Matrices: A) Leer datos B) Sumar matrices C) Multiplicar matrices D) Columna maxima de la suma E) Columna maxima de la multiplicacion F) Liberar matrices G) Ver resultados Q) Salir\n";
	char opcion;
	int numFil, numCol, errNum;
	float *vectorsuma, *vectormultiplicacion = NULL;

	matFloatRef A, B, C, D;

	A = B = C = D = NULL;

	do
	{
		printf("%s ", menu);
		scanf("%c%*c", &opcion);
		opcion = toupper(opcion);
		switch (opcion)
		{
		case 'A':
			if (A != NULL || B != NULL)
			{
				printf("Ya existen matrices ... opciones C o D o E\n\n");
				break;
			}
			printf("\n\nDimensiones de las matrices:\n\n");
			printf("Número de filas: ");
			scanf("%d%*c", &numFil);
			printf("Número de columnas: ");
			scanf("%d%*c", &numCol);
			//
			printf("Primera matriz: \n");
			if (NULL != (A = crearMatFloat(numFil, numCol, &errNum)))
				leerMatFloat(A, "Matriz A");
			else
				printf("Fallo creación matriz: %d\n", errNum);
			//
			printf("Segunda matriz: \n");
			if (NULL != (B = crearMatFloat(numFil, numCol, &errNum)))
				leerMatFloat(B, "Matriz B");
			else
				printf("Fallo creación matriz: %d\n", errNum);
			break;
		//
		case 'B':
			printf("\n\nSuma...");
			if (NULL != C)
			{
				liberarMatFloat(C);
				free(C);
			}
			if (NULL == (C = sumarMatFloat(A, B, &errNum)))
				printf("... no realizada %d\n", errNum);
			else
				printf("efectuada.\n\n");
			break;
		//
		case 'C':
			printf("\n\nMultiplicacion...");
			if (NULL != D)
			{
				liberarMatFloat(D);
				free(D);
			}
			if (NULL == (D = multiplicarMatFloat(A, B, &errNum)))
				printf("... no realizada %d\n", errNum);
			else
				printf("efectuada.\n\n");
			break;
		//
		/*case 'D':
			printf("\n\nColumna maxima de la matriz suma...");
			if (NULL == obtenerColumnaMaxMatFloat(C, &errNum))
				printf("... no realizada %d\n", errNum);
			else
				printf("efectuada.\n\n");
			vectorsuma = obtenerColumnaMaxMatFloat(C, &errNum);
			break;
		//
		case 'E':
			printf("\n\nColumna maxima de la matriz multiplicacion...");
			if (NULL == obtenerColumnaMaxMatFloat(D, &errNum))
				printf("... no realizada %d\n", errNum);
			else
				printf("efectuada.\n\n");
			vectormultiplicacion = obtenerColumnaMaxMatFloat(D, &errNum);
			break;*/
		case 'F':
			printf("\n\nLiberación de matrices...");
			liberarMatFloat(A);
			free(A);
			A = NULL;
			liberarMatFloat(B);
			free(B);
			B = NULL;
			liberarMatFloat(C);
			free(C);
			C = NULL;
			liberarMatFloat(D);
			free(D);
			D = NULL;
			vectorsuma = NULL;
			vectormultiplicacion = NULL;
			printf("efectuada.\n\n");
			break;
		//
		case 'G':
			printf("\n\nVisualización de resultados\n\n");
			printf("\n\nPrimera matriz\n\n");
			mostrarMatFloat(A, " %6.2lf ");
			printf("\n\nSegunda matriz\n\n");
			mostrarMatFloat(B, " %6.2lf ");
			//
			printf("\n\nMatriz suma\n\n");
			mostrarMatFloat(C, " %6.2lf ");
			//
			printf("\n\nMatriz multiplacion\n\n");
			mostrarMatFloat(D, " %6.2lf ");
			//
			if (vectorsuma != NULL)
			{
				printf("\n\nColumna maxima de la matriz suma\n\n");
				imprimircolumna(vectorsuma, numFil);
			}
			if (vectormultiplicacion != NULL)
			{
				printf("\n\nColumna maxima de la matriz multiplicacion\n\n");
				imprimircolumna(vectormultiplicacion, numFil);
			}
			break;
		//
		case 'Q':
			printf("\n\nSaliendo.\n\n");
			break;
		//
		default:
			printf("\n\nOpción incorrecta!\a\n\n");
			break;
		}
	} while ('Q' != opcion);
	printf("\n\nTerminación normal del programa.\n\n");
	return 0;
}
