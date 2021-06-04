#include <stdio.h>
#include <stdlib.h>

// *** ---------------------------
// *** Definicion del tipo nodo
// *** ---------------------------
typedef int tipoInfo;

typedef struct tipoNodo
{
	tipoInfo info;
	struct tipoNodo *sig;
} tipoNodo;

int main(void)
{

	// *** -----------------------------------
	// *** 1) Crear una lista enlazada vac�a
	// *** ----------------------------------

	tipoNodo *lst; // Puntero de entrada a la lista enlazada

	tipoNodo *nuevo; // Punteros auxiliares para los algoritmos
	tipoNodo *indice;
	tipoNodo *aborrar;
	tipoNodo *ultimo;
	tipoNodo *anterior;

	tipoInfo num, datobuscado;
	int cuantos;
	long suma;

	lst = NULL; // Iniciamos a "vac�a" la lista enlazada

	// *** -----------------------------------
	// *** 2) Crear un bucle que vaya leyendo n�meros hasta que se teclee 0 o negativo
	// ***   (bucle controlado por centinela). Por cada n�mero le�do debe de crear un nodo
	// ***   y enlazarlo como PRIMERO a la lista enlazada.
	// *** ----------------------------------
	printf("\n\nCREAR LISTA ENLAZANDO NODOS COMO PRIMERO\n");
	printf("Introduzca numero (<=0 para terminar): ");
	scanf("%d", &num);
	while (num > 0)
	{
		nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
		nuevo->info = num;
		nuevo->sig = NULL;

		nuevo->sig = lst;
		lst = nuevo;

		printf("Introduzca numero (<=0 para terminar): ");
		scanf("%d", &num);
	}

	// *** -----------------------------------
	// *** 3) Crear un bucle para que recorra la lista, la visualice,
	// ***    cuente sus nodos y obtenga la suma del valor de todos los nodos
	// ***    Imprimir el n�mero de nodos y su suma en pantalla
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	cuantos = 0;
	suma = 0;
	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		cuantos++;
		suma = suma + indice->info;
		indice = indice->sig;
	}

	printf("La lista enlazada tiene %d nodos.\n", cuantos);
	printf("El valor de su suma es %ld.\n", suma);

	// *** -----------------------------------
	// *** 4) Crear un bucle que vaya leyendo n�meros hasta que se teclee 0 o negativo
	// ***    (bucle controlado por centinela). Por cada n�mero le�do debe de crear un nodo y enlazarlo
	// ***    como ULTIMO a la lista enlazada.
	// *** ----------------------------------
	// *** ----------------------------------------------------
	// --- 4.1 Versi�n 1 del Algoritmo. Ante cada inserci�n, siempre recorremos la lista
	// --- desde el principio hasta localizar el ultimo nodo. Es poco eficiente
	// *** ----------------------------------------------------
	printf("\n\nCREAR LISTA ENLAZANDO NODOS COMO ULTIMO (algoritmo 1)\n");
	printf("Introduzca numero (<=0 para terminar): ");
	scanf("%d", &num);
	while (num > 0)
	{

		nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
		nuevo->info = num;
		nuevo->sig = NULL;

		// Localizamos el ultimo nodo
		indice = lst;
		if (indice == NULL)
			lst = nuevo;
		else
		{
			while (indice->sig != NULL)
				indice = indice->sig;
			indice->sig = nuevo;
		}

		printf("Introduzca numero (<=0 para terminar): ");
		scanf("%d", &num);
	}

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** ----------------------------------------------------
	// --- 4.2 Versi�n 2 del Algoritmo. Recorremos la lista la primera vez para lozalizar el ultimo
	// --- nodo, y a partir de ah�, mantenemos un puntero al ultimo nodo de forma que asi hacemos
	// --- m�s eficientes las inserciones.
	// *** ----------------------------------------------------

	ultimo = lst;
	if (lst != NULL)
		while (ultimo->sig != NULL)
			ultimo = ultimo->sig;

	printf("\n\nCREAR LISTA ENLAZANDO NODOS COMO ULTIMO (algoritmo 2)\n");
	printf("Introduzca numero (<=0 para terminar): ");
	scanf("%d", &num);
	while (num > 0)
	{

		nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
		nuevo->info = num;
		nuevo->sig = NULL;

		// El ultimo nodo est� apuntado por ultimo
		if (lst == NULL)
		{
			lst = nuevo;
			ultimo = nuevo;
		}
		else
		{
			ultimo->sig = nuevo;
			ultimo = nuevo; // Siempre dejamos apuntado el �ltimo nodo
		}

		printf("Introduzca numero (<=0 para terminar): ");
		scanf("%d", &num);
	}

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** -----------------------------------
	// *** 6) Eliminar el primer nodo de la lista
	// *** -----------------------------------

	printf("\n\nELIMINAR EL PRIMER NODO DE LA LISTA\n");

	if (lst != NULL)
	{ // Si la lista no esta vac�a
		aborrar = lst;
		lst = lst->sig;
		free(aborrar);
	}

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** -----------------------------------
	// *** 7) Eliminar el �ltimo nodo de la lista
	// *** -----------------------------------

	printf("\n\nELIMINAR EL ULTIMO NODO DE LA LISTA\n");

	if (lst != NULL)
	{ // Si la lista no esta vac�a

		// Localizamos el pen�ltimo y �ltimo nodo
		ultimo = lst;
		anterior = NULL;
		while (ultimo->sig != NULL)
		{
			anterior = ultimo;
			ultimo = ultimo->sig;
		}

		if (anterior == NULL)
		{ // Solo hay un nodo, que eliminamos
			free(lst);
			lst = NULL;
		}
		else
		{
			free(ultimo);
			anterior->sig = NULL;
		}
	}

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** -----------------------------------
	// *** 8) Insertar un nodo en orden en una lista enlazada:
	// ***    a) Eliminar la lista enlazada que tengamos construida hasta este momento.
	// ***    b) Crear un bucle que vaya leyendo n�meros hasta que se teclee 0 o negativo
	// ***    (bucle controlado por centinela). Por cada n�mero le�do debe de crear un nodo y enlazarlo
	// ***    en la posici�n que le correspnda dentro de la lista enlazada. De esta forma, la lista se ira
	// ***    creando siempre de forma ordenada
	// *** -----------------------------------

	printf("\n\nELIMINAMOS LA LISTA ENLAZADA\n");

	// Eliminamos la lista enlazada
	aborrar = lst;
	while (lst != NULL)
	{
		lst = lst->sig;
		free(aborrar);
		aborrar = lst;
	}

	printf("\n\nCREAR UNA LISTA ENLAZADA INSERTANDO LOS NODOS EN ORDEN\n");
	printf("Introduzca numero (<=0 para terminar): ");
	scanf("%d", &num);
	while (num > 0)
	{

		nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
		nuevo->info = num;
		nuevo->sig = NULL;

		indice = lst;
		anterior = NULL;
		if (indice == NULL) // Lista vac�a. El nodo es el primero
			lst = nuevo;
		else
		{ // Recorremos la lista hasta encontrar un nodo con el contenido
			// del campo informaci�n mayor que el del nodo a insertar, o bien hasta llegar
			// al final de la lista
			while ((indice->info < nuevo->info) &&
						 (indice->sig != NULL))
			{
				anterior = indice;
				indice = indice->sig;
			}

			if (anterior == NULL && (indice->info > nuevo->info))
			{
				// El nodo se inserta como primero
				nuevo->sig = lst;
				lst = nuevo;
			}
			else if ((indice->sig == NULL) && (indice->info < nuevo->info))
			{
				// El nodo se inserta al final de la lista
				nuevo->sig = NULL;
				indice->sig = nuevo;
			}
			else
			{
				// El nodo se inserta en medio de la lista
				nuevo->sig = indice;
				anterior->sig = nuevo;
			}
		}

		printf("Introduzca numero (<=0 para terminar): ");
		scanf("%d", &num);
	}

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** -----------------------------------
	// *** 9) Eliminar un nodo de la lista por su contenido
	// ***    a) Solicitar el valor del dato de un nodo de la lista
	// ***    b) Localizar el primer nodo de la lista que tenga ese contenido y eliminarlo
	// *** -----------------------------------
	int buscarenodo;
	printf("\nNUMERO PARA BUSCAR EN LOS NODOS:");
	scanf("%d", &buscarenodo);
	if (lst == NULL)
	{
		printf("\nLISTA VACIA\n");
	}
	else
	{
		aborrar = lst;
		anterior = NULL;
		while ((aborrar->info != buscarenodo) && (aborrar->sig != NULL))
		{
			anterior = aborrar;
			aborrar = aborrar->sig;
		}
		if (aborrar->info == buscarenodo)
		{
			if (anterior == NULL)
			{
				lst = aborrar->sig;
				free(aborrar);
			}
			else
			{
				anterior->sig = aborrar->sig;
				free(aborrar);
			}
		}
		else
			(printf("DATO NO ENCONTRADO\n"));
	}
	free(indice);

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** -----------------------------------
	// *** 10) Devolver el campo informacion de un nodo identificado por su posicion en la lista
	// ***     Debe obtenerse la informacion almacenada en el nodo situado en la posicion indicada
	// ***     por un indice entero (0 para primer nodo, 1 para segundo, 2 para tercero, etc, ...)
	// ***     Implica recorrido contando nodos hasta el valor indicado por indice.
	// ***     Atencion, hay que garantizar que esa posicion existe, es decir, que si la lista
	// ***     tiene 4 nodos (los numeramos de 0 a 3), las posiciones validas son 0, 1, 2, 3.
	// ***     Si la posicion no existe, no se puede devolver nada (en nuestro ejemplo, la posicion -1
	// ***     o cualquier otro numero negativo, no existe, y la posicion 4 y superiores tampoco).
	// *** -----------------------------------
	int i, ind;
	tipoNodo *aux;
	if (indice < 0 || lst == NULL)
	{
		printf("LISTA VACIA\n");
	}
	aux = (tipoNodo *)malloc(sizeof(tipoNodo));
	printf("INDICE DEL NODO AL QUE QUIERES ACCEDER: ");
	scanf("%d", &ind);
	if (lst == NULL)
	{
		printf("ERROR");
	}
	if (ind < 0)
	{
		printf("ERROR");
	}
	i = 0;
	aux = lst;
	while (i < ind && aux->sig != NULL)
	{
		aux = aux->sig;
		i++;
	}
	if (i == ind)
	{
		printf("%d", aux->info);
	}
	else
		(printf("NO EXISTE NODO POSICION %d", ind));

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** -----------------------------------
	// *** 11) Eliminar un nodo identificado por su posicion en la lista
	// ***     Debe eliminarse el nodo situado en la posicion indicada por un indice entero
	// ***     (0 para primer nodo, 1 para segundo, 2 para tercero, etc, ...)
	// ***     Implica recorrido contando nodos hasta el valor indicado por indice.
	// ***     Atencion, hay que garantizar que esa posicion existe, es decir, que si la lista
	// ***     tiene 4 nodos (los numeramos de 0 a 3), las posiciones validas son 0, 1, 2, 3.
	// ***     Si la posicion no existe, no se hace nada.
	// *** -----------------------------------

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** -----------------------------------
	// *** 12) Insertar un nodo identificado por su posicion en la lista
	// ***     (0 para primer nodo, 1 para segundo, 2 para tercero, etc, ...)
	// ***     Si la posicion no existe el nodo se inserta como ultimo.
	// ***     Por ejemplo, sila lista tiene 4 nodos (los numeramos de 0 a 3), y se
	// ***     ha indicado como posicion 6, el nodo se inserta ultimo
	// *** -----------------------------------

	// *** -----------------------------------
	// *** Bucle para recorrer la lista para visualizarla
	// *** Similar al creado en el punto 3)
	// *** ----------------------------------

	printf("\nLista enlazada:\n");

	indice = lst;
	while (indice != NULL)
	{
		printf("%d\n", indice->info);
		indice = indice->sig;
	}

	// *** -----------------------------------
	// *** 5) Bucle para eliminar cada uno de los nodos de la lista enlazada
	// *** Al finalizar este algoritmo lst queda con valor NULL
	// *** -----------------------------------
	printf("\n\nELIMINAMOS LA LISTA ENLAZADA\n");

	aborrar = lst;
	while (lst != NULL)
	{
		lst = lst->sig;
		free(aborrar);
		aborrar = lst;
	}

	printf("\n");
	system("pause");
	return 0;

} /* Fin del main */
