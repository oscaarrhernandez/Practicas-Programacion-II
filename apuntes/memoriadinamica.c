#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define COL 10
typedef struct matFloat1
{
	float *m;
	int numFil, numCol;
} matFloat1;
typedef struct matFloat2
{
	float (*m)[COL];
	int numFil, numCol;
} matFloat2;
typedef struct matFloat3
{
	float **m;
	int numFil, numCol;
} matFloat3;
int main(void)
{
	int filas = 6, columnas = 5;
	int f, c;
	float num; /*
	 //? Primera estrategia
	 puts("Memoria dinamica mat primera estrategia\nMatriz como vector\n");
	 matFloat1 *mat1;
	 //$_reserva
	 mat1 = malloc(sizeof(matFloat1));
	 mat1->m = malloc(filas * columnas * sizeof(float));
	 mat1->numCol = columnas;
	 mat1->numFil = filas;
	 //$_manejo_de_la_matriz
	 num = 0;
	 for (f = 0; f < mat1->numFil; f++)
	 {
		 for (c = 0; c < mat1->numCol; c++)
		 {
			 mat1->m[f * mat1->numCol + c] = num;
			 printf("mat1[%d][%d]=%f\n", f, c, num);
			 num++;
		 }
	 }
	 //$_liberar_memoria
	 free(mat1->m);
	 free(mat1);
	 puts("\n\n");*/
	//? Segunda estrategia
	puts("Memoria dinamica mat segunda estrategia\n Matriz con puntero a vector\n ");
	matFloat2 *mat2;
	//$_reserva
	mat2 = malloc(sizeof(matFloat2));
	mat2->m = malloc(filas * sizeof(float[COL]));
	mat2->numFil = filas;
	mat2->numCol = columnas;
	//$_manejo_de_la_matriz
	num = 0;
	for (f = 0; f < mat2->numFil; f++)
	{
		for (c = 0; c < mat2->numCol; c++)
		{
			mat2->m[f][c] = num;
			printf("mat2[%d][%d]=%f\n", f, c, num);
			num++;
		}
	}
	//$_liberar_memoria
	free(mat2->m);
	free(mat2);
	puts("\n\n"); /*
	//? Tercera estrategia
	puts("Memoria dinamica mat tercera estrategia\n Matriz puntero a puntero\n ");
	matFloat3 *mat3;
	//$_reserva
	mat3 = malloc(sizeof(matFloat3));
	mat3->m = malloc(filas * sizeof(float *));
	for (int i = 0; i < filas; i++)
	{
		mat3->m[i] = malloc(columnas * sizeof(float));
	}
	mat3->numFil = filas;
	mat3->numCol = columnas;
	//$_manejo_de_la_matriz
	num = 0;
	for (f = 0; f < mat3->numFil; f++)
	{
		for (c = 0; c < mat3->numCol; c++)
		{
			mat3->m[f][c] = num;
			printf("mat3[%d][%d]=%f\n", f, c, num);
			num++;
		}
	}
	num = *((*(*mat3).m + 2) + 4);
	printf("\n%f\n", num);
	num = 0;
	num = *((*mat3).m[2] + 4);
	printf("\n%f\n", num);
	num = 0;
	num = *(mat3->m[2] + 4);
	printf("\n%f\n", num);
	num = 0;
	num = (*mat3).m[2][4];
	printf("\n%f\n", num);

	//$_liberar_matriz
	for (int i = 0; i < mat3->numFil; i++)
	{
		free(mat3->m[i]);
	}
	free(mat3->m);
	free(mat3);*/
	return 0;
}
