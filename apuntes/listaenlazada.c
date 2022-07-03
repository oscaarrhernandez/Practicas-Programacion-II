#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct matrix
{
	int **m;
	int numFil, numCol;
} matrix;
typedef int tipoInfo;
typedef tipoInfo *tipoInfoRef;

typedef struct tipoNodo
{
	tipoInfo info;
	tipoNodo *sig;
} tipoNodo;

typedef tipoNodo *tipoNodoRef;
typedef tipoNodo *ListaEnlazada;
typedef ListaEnlazada *ListaEnlazadaRef;

int crearVacia(ListaEnlazadaRef raiz)
{
	*raiz = NULL;
	return 0;
}
int estaVacia(ListaEnlazada raiz)
{
	return (raiz == NULL);
}
tipoNodoRef crearNodo(tipoInfoRef info)
{
	tipoNodoRef nuevo;
	nuevo = malloc(sizeof(tipoNodo));
	if (nuevo == NULL)
	{
		printf("\nNo hubo reserva");
		return NULL;
	}
	else
	{
		nuevo->info = *info;
		nuevo->sig = NULL;
	}
	return nuevo;
}
int insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef aux, nuevo, ant;
	nuevo = crearNodo(info);
	if (nuevo == NULL)
	{
		printf("\n...no se pudo reservar");
		return -1;
	}
	else
	{
		if (estaVacia(*raiz))
		{
			*raiz = nuevo;
		}
		else
		{
			aux = *raiz;
			while (aux != NULL && aux != pos)
			{
				ant = aux;
				aux = aux->sig;
			}
			if (aux != NULL && pos != NULL)
			{
				nuevo->sig = pos->sig;
				pos->sig = nuevo;
			}
			else
			{
				if (pos == NULL)
				{
					ant->sig = nuevo;
				}
				else
				{
					free(nuevo);
					return -2;
				}
			}
			return 0;
		}
	}
}
int insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo, ant;
	nuevo = crearNodo(info);
	if (nuevo == NULL)
	{
		printf("\n...no se pudo reservar");
		return -1;
	}
	else
	{
		if (estaVacia(*raiz) || pos == NULL || pos == *raiz)
		{
			nuevo->sig = *raiz;
			*raiz = nuevo;
		}
		else
		{
			ant = *raiz;
			while (ant != pos && ant->sig != pos)
			{
				ant = ant->sig;
			}
			if (ant != NULL)
			{
				nuevo->sig = pos;
				ant->sig = nuevo;
			}
			else
			{
				free(nuevo);
				return -2;
			}
		}
		return 0;
	}
}
int insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef nuevo, aux;
	nuevo = crearNodo(info);
	aux = *raiz;
	if (nuevo == NULL)
	{
		printf("\n...no se pudo reservar");
		return -1;
	}
	else
	{
		if (estaVacia(*raiz))
		{
			*raiz = nuevo;
		}
		else
		{
			insertarAntesDeNodo(raiz, aux, info);
		}
		return 0;
	}
}
int insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef aux, nuevo;
	aux = NULL;
	nuevo = crearNodo(info);
	if (nuevo == NULL)
	{
		printf("\n...no se pudo reservar");
		return -1;
	}
	else
	{
		if (estaVacia(*raiz))
		{
			*raiz = nuevo;
		}
		else
		{
			aux = *raiz;
			while (aux->sig != NULL)
			{
				aux = aux->sig;
			}
			aux->sig = nuevo;
		}
		return 0;
	}
}
int insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info)
{
	tipoNodoRef nuevo = NULL, ant = NULL, aux = NULL;
	int cont = 0;
	nuevo = crearNodo(info);
	if (nuevo == NULL)
	{
		printf("\n...no se pudo reservar");
		return -1;
	}
	if (indice == 0)
	{
		nuevo->sig = *raiz;
		*raiz = nuevo;
		return 0;
	}
	else
	{
		if (estaVacia(*raiz))
		{
			*raiz = nuevo;
		}
		else
		{
			aux = *raiz;
			while (cont != indice)
			{
				ant = aux;
				aux = aux->sig;
				cont++;
			}
			nuevo->sig = aux;
			ant->sig = nuevo;
		}
		return 0;
	}
}

int cambiarValorDeNodoEnIndice(ListaEnlazadaRef raiz, int valor, int indice)
{
	tipoNodoRef aux;
	int i = 1;
	if (estaVacia(*raiz) || indice < 0)
	{
		return -1;
	}
	else
	{
		if (indice == 1)
		{
			(*raiz)->info = valor;
		}
		else
		{
			aux = *raiz;
			while (i != indice && aux != NULL)
			{
				aux = aux->sig;
				i++;
			}
			if (aux != NULL)
			{
				aux->info = valor;
			}
		}
		return 0;
	}
}
int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos)
{
	tipoNodoRef aux = NULL, ant = NULL;
	if (estaVacia(*raiz))
	{
		printf("\n...lista vacia");
		return -2;
	}
	else
	{
		if (pos == NULL)
		{
			printf("\n...posicion no valida");
			return -1;
		}
		else
		{
			aux = *raiz;
			while (aux != NULL && aux != pos)
			{
				ant = aux;
				aux = aux->sig;
			}
			if (aux != NULL)
			{
				ant->sig = aux->sig;
				free(pos);
			}
			return 0;
		}
	}
}
int eliminarNodoComienzo(ListaEnlazadaRef raiz)
{
	tipoNodoRef aux;
	if (estaVacia(*raiz))
	{
		printf("\n... lista vacia");
		return -1;
	}
	else
	{
		aux = (*raiz)->sig;
		free(*raiz);
	}
	return 0;
}
int eliminarNodoFinal(ListaEnlazadaRef raiz)
{
	tipoNodoRef aux = NULL, ant = NULL;
	if (estaVacia(*raiz))
	{
		printf("\n...lista vacia");
		return -1;
	}
	else
	{
		aux = *raiz;
		while (aux->sig != NULL)
		{
			ant = aux;
			aux = aux->sig;
		}
		free(aux);
		ant->sig = NULL;
		// si quitas ant=aux y ant->sig=NULL el nodo no se borra, solo se borra el contenido
	}
	return 0;
}

int eliminaDatosIndice(ListaEnlazadaRef raiz, int indice)
{
	tipoNodoRef aux = NULL;
	int i = 1;
	if (estaVacia(*raiz) || indice < 0)
	{
		printf("\n...lista vacia");
		return -1;
	}
	else
	{
		if (indice == 1)
		{
			(*raiz)->info = 0;
		}
		else
		{
			aux = *raiz;
			while (i != indice)
			{
				aux = aux->sig;
				i++;
			}
			aux->info = 0;
		}
	}
	return 0;
}
int eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice)
{
	tipoNodoRef aux = NULL, ant = NULL;
	int cont = 1;
	if (estaVacia(*raiz))
	{
		printf("\n...lista vacia");
		return -1;
	}
	else
	{
		if (indice < 0)
		{
			return -2;
		}
		else
		{
			aux = *raiz;
			while (cont != indice)
			{
				ant = aux;
				aux = aux->sig;
				cont++;
			}
			ant->sig = aux->sig;
			aux->sig = NULL;
			free(aux);
		}
		return 0;
	}
}
int liberarListaEnlazada(ListaEnlazadaRef raiz)
{
	tipoNodoRef aBorrar = NULL, indice = NULL;
	if (estaVacia(*raiz))
	{
		printf("\n...lista vacia");
		return -1;
	}
	else
	{
		indice = *raiz;
		while (indice->sig != NULL)
		{
			aBorrar = indice;
			indice = indice->sig;
			aBorrar->sig = NULL;
			free(aBorrar);
		}
		(*raiz) = NULL;
		printf("\n...la lista fue borrada con exito");
		return 0;
	}
}
tipoInfo devolverInfoPosicionIndice(ListaEnlazada raiz, int indice)
{
	tipoNodoRef aux = NULL;
	int cont = 0;
	if (estaVacia(raiz))
	{
		printf("\n...lista vacia");
		return -1;
	}
	else
	{
		if (indice < 0)
		{
			return -2;
		}
		else
		{
			aux = raiz;
			while (aux != NULL && cont != indice)
			{
				aux = aux->sig;
				cont++;
			}
			return (aux->info);
		}
	}
}
int insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef aux, nuevo;
	nuevo = crearNodo(info);
	if (nuevo == NULL)
	{
		return -1;
	}
	else
	{
		if (estaVacia(*raiz) || (*raiz)->info < nuevo->info)
		{
			nuevo->sig = *raiz;
			*raiz = nuevo;
		}
		else
		{
			aux = *raiz;
			while (aux->sig != NULL && (aux->sig)->info > nuevo->info)
			{
				aux = aux->sig;
			}
			nuevo->sig = aux->sig;
			aux->sig = nuevo;
		}
		return 0;
	}
}
int crearOrdenadaDesdeMat(matrix *mat)
{
	ListaEnlazada raiz, anterior, aux, indice, nuevo;
	raiz = NULL;
	for (int f = 0; f < mat->numFil; f++)
	{
		for (int c = 0; c < mat->numCol; c++)
		{
			nuevo = malloc(sizeof(tipoNodo));
			nuevo->info = mat->m[f][c];
			nuevo->sig = NULL;
			if (f == c && f == 0)
			{
				raiz = NULL;
			}
			else
			{
				indice = raiz;
				while (indice != NULL && indice->info < mat->m[f][c])
				{
					anterior = indice;
					indice = indice->sig;
				}
				if (indice != NULL)
				{
					anterior->sig = nuevo;
					nuevo->sig = indice;
				}
			}
		}
	}
}
int mostrarListaEnlazada(ListaEnlazada raiz)
{
	tipoNodoRef aImprimir;
	int res = 0, i = 1;
	printf("%-14s%-10s\n", "  Posicion", "Valor");
	printf("%-14s%-10s\n", "  ========", "=====");
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
		srandom(time(NULL));
		for (i = 0; i < numNodos; i++)
		{
			temp = random() % 10000;
			insertarDespuesDeNodo(raiz, NULL, &temp);
			// insertarAntesDeNodo(raiz, NULL, &temp);
			// insertarNodoFinal(raiz, &temp);
			// insertarNodoComienzo(raiz, &temp);
		}
		return 0;
	}
	return -1;
}
