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
	// *** 1) Crear una lista enlazada vacia
	// *** ----------------------------------

	tipoNodo *lst; // Puntero de entrada a la lista enlazada

	// Punteros auxiliares para los algoritmos
	tipoNodo *nuevo;		// Puntero de entrada a el nodo nuevo
	tipoNodo *indice;		// Puntero que va a ir recorriendo la lista
	tipoNodo *aborrar;	//Puntero para indicar que nodo vamos a borrar
	tipoNodo *ultimo;		//Ultimo nodo de la lista
	tipoNodo *anterior; //Puntero que marca a un nodo anterior, sirve para el punto 8.

	tipoInfo num; //El dato que metemos en la lista, en este caso un numero
	int cuantos;	//Contador para recorrer la lista
	long suma;		//Suma de los numeros de la lista

	lst = NULL; // Iniciamos a "vacia" la lista enlazada

	// *** -----------------------------------
	// *** 2) Crear un bucle que vaya leyendo numeros hasta que se teclee 0 o negativo
	// ***   (bucle controlado por centinela). Por cada numero leido debe de crear un nodo
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
	// ***    Imprimir el numero de nodos y su suma en pantalla
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
	// *** 4) Crear un bucle que vaya leyendo numeros hasta que se teclee 0 o negativo
	// ***    (bucle controlado por centinela). Por cada numero leido debe de crear un nodo y enlazarlo
	// ***    como ULTIMO a la lista enlazada.
	// *** ----------------------------------
	// *** ----------------------------------------------------
	// --- 4.1 Version 1 del Algoritmo. Ante cada insercion, siempre recorremos la lista
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
	// --- 4.2 Version 2 del Algoritmo. Recorremos la lista la primera vez para lozalizar el ultimo
	// --- nodo, y a partir de ahi, mantenemos un puntero al ultimo nodo de forma que asi hacemos
	// --- mas eficientes las inserciones.
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

		// El ultimo nodo esta apuntado por ultimo
		if (lst == NULL)
		{
			puts("La lista estaba vacia");
		}
		else if (lst == NULL)
		{
			lst = nuevo;
			ultimo = nuevo;
		}
		else
		{
			ultimo->sig = nuevo;
			ultimo = nuevo; // Siempre dejamos apuntado el ultimo nodo
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
	if (lst == NULL)
	{
		printf("\nLa lista estaba vacia\n");
	}
	else if (lst != NULL)
	{ //Lista no vacia
		aborrar = lst;
		lst = aborrar->sig; //Pasar nuestro elemento inicio al segundo elemento de la lista
		free(aborrar);
		printf("Eliminado el primer nodo de la lista.\n");
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
	// *** 7) Eliminar el ultimo nodo de la lista
	// *** -----------------------------------

	//7.1 Lista vacia
	if (lst == NULL)
		puts("\nLa lista estaba vacia");

	//7.2 Solo un elemento en la Lista
	/*
	else if (lst->sig == NULL)
	{
		free(lst);
		lst == NULL;
	} 
	*/
	//7.3 Más de un elemento en la lista
	else
	{
		aborrar = lst;
		ultimo = aborrar->sig;
		while (ultimo->sig != NULL)
		{
			aborrar = ultimo;
			ultimo = ultimo->sig;
		}
		aborrar->sig = NULL;
		free(ultimo);
		printf("\nEliminado el ultimo nodo de la lista\n");
	}
	/*
		hacemos que se muevan paralelamente desde el pricipio,(aux1=aborrar / aux2=ultimo).
		aux1 lo ponemos en el primer elemento y aux2 en el siguiente. Mientras aux2 no sea = a NULL significara que este no está en la ultima posición de la lista asi que seguimos avanzandola. Cuando aux2->sig sea igual a NULL ponemos aux1->sig a NULL y liberamos aux2(que tiene el último elemento).
	*/
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
	// ***    b) Crear un bucle que vaya leyendo numeros hasta que se teclee 0 o negativo
	// ***    (bucle controlado por centinela). Por cada numero leido debe de crear un nodo y enlazarlo
	// ***    en la posicion que le correspnda dentro de la lista enlazada. De esta forma, la lista se ira
	// ***    creando siempre de forma ordenada
	// *** -----------------------------------

	//a)
	aborrar = lst;			//Apuntamos con aborrar al comienzo de la lista
	while (lst != NULL) // Si esta no es null se ejecuta
	{
		lst = lst->sig; //apuntamos la cabeza de la lista al siguiente elemento después de esta
		free(aborrar);	//borramos aborrar que estaba apuntando al comienzo de la lista
		aborrar = lst;	//apuntamos aborrar al nuevo comienzo de la lista
	}
	printf("\nLista enlazada borrada.\n");

	//b)
	printf("\n\nCREAR LISTA ENLAZANDO NODOS EN SU POSICION CORRESPONDIENTE\n");
	printf("Introduzca numero (<=0 para terminar): ");
	scanf("%d", &num);
	while (num > 0)
	{
		nuevo = (tipoNodo *)malloc(sizeof(tipoNodo));
		nuevo->info = num;
		nuevo->sig = NULL;

		indice = lst;
		anterior = NULL;
		if (indice == NULL)
		{
			lst = nuevo;
		}
		else
		{
			while (indice->info < nuevo->info && indice->sig != NULL)
			{
				anterior = indice;
				indice = indice->sig;
			}
			if (indice->sig == NULL && indice->info < nuevo->info)
			{
				nuevo->sig = NULL;
				indice->sig = nuevo;
			}
			else
			{
				if (anterior == NULL)
				{
					nuevo->sig = lst;
					lst = nuevo;
				}
				else
				{
					nuevo->sig = indice;
					anterior->sig = nuevo;
				}
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
