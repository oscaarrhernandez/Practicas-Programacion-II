//
//  listaEnlazadaSimple.c
//  listaEnlazadaSimple

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazadaSimple.h"

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int CrearVacia(ListaEnlazadaRef raiz)
{

	*raiz = NULL;
	return 0;
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int estaVacia(ListaEnlazada raiz)
{

	return (raiz == NULL);
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
tipoNodoRef creaNodo(tipoInfoRef info)
{

	tipoNodoRef nuevo;

	if (NULL == (nuevo = (tipoNodoRef)malloc(sizeof(tipoNodo))))
	{
#ifdef DEBUG
		fprintf(stderr, "Error: no reserva memoria\n");
#endif
	}
	else
	{
		nuevo->info = *info;
		nuevo->sig = NULL;
	}
	return nuevo;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int InsertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{

	tipoNodoRef nuevo, indice;

	nuevo = creaNodo(info);

	if (nuevo == NULL)
	{
		fprintf(stderr, "ERROR--> En la reserva de memoria del nodo a añadir\n");
	}
	if (estaVacia(*raiz))
	{
		*raiz = nuevo;
	}
	else
	{
		indice = *raiz;

		while (indice != NULL && indice != pos)
		{
			indice = indice->sig;
		}

		if (indice != NULL)
		{
			nuevo->sig = pos->sig;
			pos->sig = nuevo;
		}
		else
		{
			free(nuevo);
			return -2;
		}

		return 0;
	}

	return 0;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int InsertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{

	tipoNodoRef anterior, nuevo;

	nuevo = creaNodo(info);

	if (nuevo == NULL)
	{
		fprintf(stderr, "ERROR--> En la reserva de memoria del Nodo a incluir\n");
	}

	if (EstaVacia(*raiz))
	{
		nuevo->sig = *raiz;
		*raiz = nuevo;
	}
	else if (pos == NULL)
	{
		nuevo->sig = *raiz;
		*raiz = nuevo;
	}
	else if (pos == *raiz)
	{
		nuevo->sig = *raiz;
		*raiz = nuevo;
	}
	else
	{
		anterior = *raiz;

		while ((anterior->sig != pos) || (anterior != NULL))
		{
			anterior = anterior->sig;
			if (anterior != NULL)
			{
				nuevo->sig = pos;
				anterior->sig = nuevo;
			}
			else
			{
				free(nuevo);
				return -2;
			}
			return 0;
		}
	}
	return 0;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int InsertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info)
{

	return insertarAntesDeNodo(raiz, (*raiz), info);
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int InsertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info)
{

	return insertarDespuesDeNodo(raiz, NULL, info);
}

/*
 * Esta función recibe una lista (por referencia), un índice entero y una
 * variable de tipoInfo por referencia. Debe insertar un nuevo nodo
 * en la posición indicada por el índice entero (implica recorrido contando
 * nodos hasta el valor indicado por indice). Ojo, hay que garantizar que 
 * esa posición existe, es decir, que si la lista tiene 5 nodos, (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4, 5 (la posición 5
 * es equivalente a añadir al final).
 * Si la posición no existe, no se puede hacer la inserción (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 6 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque implique 
 * ineficiencias (recorridos adicionales de la lista enlazada). Opcional 
 * escribir una versión eficiente que no implique repetir recorridos.
 */
int InsertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info)
{

	int i = 0;
	tipoNodoRef x;

	x = *raiz;

	if (indice < 0)
	{
		return -1;
	}
	if (indice == 0)
	{
		return insertarAntesDeNodo(raiz, x, info);
	}
	if (estaVacia(*raiz))
	{
		return -1;
	}

	while (x->sig != NULL && ++i < indice)
	{
		x = x->sig;
	}

	if (i == indice || i + 1 == indice)
	{
		return insertarDespuesDeNodo(raiz, x, info);
	}

	return -1;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos)
{

	tipoNodoRef x;

	if (estaVacia(*raiz))
	{
		return -1;
	}
	if (pos == NULL)
	{
		return -1;
	}
	if (pos == *raiz)
	{
		*raiz = (*raiz)->sig;
		free(pos);
		return 0;
	}

	x = *raiz;

	while (x != NULL && x->sig != pos)
		x = x->sig;

	if (x != NULL)
	{
		x->sig = pos->sig;
		free(pos);
	}

	return -1;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int EliminarNodoComienzo(ListaEnlazadaRef raiz)
{
	return eliminarNodo(raiz, *raiz);
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */

int EliminarNodoFinal(ListaEnlazadaRef raiz)
{

	tipoNodoRef aborrar;

	if (estaVacia(*raiz))
	{
		return -1;
	}

	aborrar = *raiz;

	while (aborrar->sig != NULL)
	{
		aborrar = aborrar->sig;
	}

	return eliminarNodo(raiz, aborrar);
}

/*
 * Esta función recibe una lista (por referencia) y un índice entero
 * Debe eliminar el nodo situado en en la posición indicada por el
 * índice entero (implica recorrido contando nodos hasta el valor
 * indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4.
 * Si la posición no existe, no se puede hacer la eliminación (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 5 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque 
 * implique ineficiencias (recorridos adicionales de la lista enlazada). 
 * Opcional escribir una versión eficiente que no implique repetir recorridos.
 */

int EliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice)
{

	int k;
	tipoNodoRef aBorrar;
	tipoNodoRef anterior;

	if (indice <= 0)
	{
		return -1;
	}

	aBorrar = *raiz;
	k = 1;
	anterior = NULL;

	while ((aBorrar != NULL) && (k < indice))
	{
		k++;
		anterior = aBorrar;
		aBorrar = aBorrar->sig;
	}

	if (k == indice)
	{
		if (anterior == NULL)
			*raiz = aBorrar->sig;
		else
		{
			anterior->sig = aBorrar->sig;
		}
		free(aBorrar);
	}

	return 0;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int LiberarListaEnlazada(ListaEnlazadaRef raiz)
{

	tipoNodoRef indice, aBorrar;

	if (EstaVacia(*raiz))
	{
		return -1;
	}

	indice = *raiz;
	while (indice != NULL)
	{
		aBorrar = indice;
		indice = indice->sig;
		free(aBorrar);
	}

	*raiz = NULL;
	return 0;
}

/********************************************************************
 *                                                                  *
 * Las cuatro funciones que vienen a continuación dependen de cómo  *
 * está definido el tipo de dato tipoInfo. No es lo mismo mostrar   *
 * por pantalla el contenido de los datos almacenados en una lista  *
 * enlazada si éste es de tipo entero, o si se trata de un registro.*
 * Adicionalmente, y para que el alumno no pierda el tiempo         *
 * en implementar funciones que aportan poco desde un punto de vista*
 * docente, se proporcionan ya implementadas las funciones          *
 * mostrarListaEnlazada() y crearListaValoresAleatorios(). Las otras*
 * dos son sencillas y se dejan al alumno su implementación.        *
 *                                                                  *
 *******************************************************************/

/*
 * Esta función recibe una lista (por referencia) y un índice entero
 * Debe devolver la información almacenada en el nodo situado en la 
 * posición indicada por el índice entero (implica recorrido contando nodos 
 * hasta el valor indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4.
 * Si la posición no existe, no se puede devolver nada (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 5 tampoco).
 * IMPORTANTE: tipoInfo es, en este caso particular, un entero. Aunque
 * la dependencia es pequeña, si existe. ¿Cómo se devuelve el código de error
 * en caso de no existir la posición indicada por el parámetro indice?. Si 
 * tipoInfo es un int es sencillo, si es un registro también, pero ya es
 * diferente implementación.
 */
tipoInfo DevolverInfoPosicionIndice(ListaEnlazada raiz, int indice)
{

	int i = 0;
	tipoNodoRef x;
	x = raiz;

	if (indice < 0)
	{
		return -1;
	}
	if (estaVacia(raiz))
	{
		return -1;
	}
	while (x != NULL && ++i <= indice)
	{
		x = x->sig;
	}
	if (x != NULL)
	{
		return x->info;
	}

	return -1;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */

int InsertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info)
{

	tipoNodoRef indice;

	if (estaVacia(*raiz) || (*raiz)->info > info)
	{
		return InsertarNodoComienzo(raiz, info);
	}
	else
	{
		indice = *raiz;
		while (indice->sig != NULL && indice->sig->info < *info)
		{
			indice = indice->sig;
		}
		return InsertarDespuesDeNodo(raiz, indice, info);
	}
}

int mostrarListaEnlazada(ListaEnlazada raiz)
{

	tipoNodoRef aImprimir;
	int res = 0, i = 0;

	printf("\n\n");
	printf("%-14s%-10s\n", "  Posición", "Valor");
	printf("%-14s%-10s\n", "  ==========", "======");

	aImprimir = raiz;
	while (aImprimir != NULL)
	{
		printf("\t%3d)\t%7d\n", i++, aImprimir->info);
		aImprimir = aImprimir->sig;
	}

	return res;
}

int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos)
{

	int i;
	tipoInfo temp;

	if (estaVacia(*raiz))
	{
		srand(time(NULL));
		for (i = 0; i < numNodos; i++)
		{
			temp = rand() % 10000;
			insertarDespuesDeNodo(raiz, NULL, &temp);
			//insertarAntesDeNodo(raiz, NULL, &temp);
			//insertarNodoFinal(raiz, &temp);
			//insertarNodoComienzo(raiz, &temp);
		}
		return 0;
	}

	return -1;
}
