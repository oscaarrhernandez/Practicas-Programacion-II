/* Fuente: RACIONAL.C
	 Programa: ARITMETICA BASICA CON NUMEROS RACIONALES
	 Descripcion: Este programa permite operar con numeros racionales. Un numero racional 
	 se caracteriza por estar expresado con un denominador y un denominador.
	 Las operaciones que contempla son:
		 - suma
		 - resta
		 - producto
		 - division
	 Ademas utiliza una funcion para proporcionar siempre la expresion irreducible del numero
	 racional
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/* ---------------------------------------------------------- */
/* Definiciones globales                                      */
/* ---------------------------------------------------------- */
typedef struct Racional{
	 int num;   /* Numerador   */
	 int denom; /* Denominador */
} Racional;

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
	 void Modulo_Principal (void);
	 void Presentacion (void);
	 void LeerRacional (Racional *);
	 void MostrarRacional (Racional);
	 
// -----------------------------------------------------------------------
// Lo habitual es que las 4 funciones tuvieran prototipos similares, 
// en este caso se han hecho diferentes para poder practicar con las dos
// formas en que la funcion puede devolver el resultado
// -----------------------------------------------------------------------
// Devuelve el resultado en una estructura recibida por referencia
	 void SumaRacional (Racional, Racional, Racional *);
	 void RestaRacional (Racional, Racional, Racional *);
// Devuelve el resultado como valor de retorno
	 Racional MultiplicaRacional (Racional, Racional);
	 Racional DivideRacional (Racional, Racional);
			
	 void SimplificaRacional (Racional *);
	 int mcd (int, int);
		
/* ---------------------------------------------------------- */
	 int main (void) {
/* ---------------------------------------------------------- */
		 char respuesta;
	
		 system ("cls");
		 Presentacion();
		 do
			 { printf("\n");
				 Modulo_Principal();
			 printf("\n");
			 do
				 { printf("¿Otra ejecucion (S/N)?: ");
					 fflush(stdin); /* Limpia el buffer de teclado */
					 respuesta = toupper(getchar());
				 }
			 while (respuesta != 'S' && respuesta != 'N');

			 }
		 while (respuesta != 'N');
		 
		 printf("\n");
		 return 0;
		 
} /* Fin del main */


/* ---------------------------------------------------------- */
	 void Modulo_Principal (void) {
/* ---------------------------------------------------------- */   	
		 Racional rac1, rac2, rsum, rres, rprod, rdiv;
	
		 printf("Introduzca el primer numero racional:\n");
		 LeerRacional(&rac1);
		 printf("Introduzca el segundo numero racional:\n");
		 LeerRacional(&rac2);
					
		 printf("\n");
		 SumaRacional (rac1, rac2, &rsum);
		 printf("Suma.......: ");
		 MostrarRacional(rsum);
		 printf("\n");

		 RestaRacional (rac1, rac2, &rres);
		 printf("Resta......: ");
		 MostrarRacional(rres);
		 printf("\n");
		 
		 rprod = MultiplicaRacional (rac1, rac2);
		 printf("Producto...: ");
		 MostrarRacional(rprod);
		 printf("\n");
		 
		 rdiv = DivideRacional (rac1, rac2);
		 printf("Division...: ");
		 MostrarRacional(rdiv);
		 printf("\n");
}

/* ---------------------------------------------------------- */
	 void Presentacion (void) {
/* ---------------------------------------------------------- */
		 puts("ARITMETICA BASICA CON NUMEROS RACIONALES");
		 puts("========================================");
		 puts("");
		 puts("Realiza la suma, resta, producto y division de numeros racionales");
		 puts("Siempre presenta la expresion irreducible del numero racional");
		 puts("");
}

/* ---------------------------------------------------------- */
	 void LeerRacional (Racional *r) {
/* ---------------------------------------------------------- */
		struct Racional kl;
		printf("Numerador?: ");
		scanf("%d", &kl.num);
		printf("Denominador?: ");
		scanf("%d", &kl.denom);
		*r = kl;
}

/* ---------------------------------------------------------- */
	 void SumaRacional (Racional a, Racional b, Racional *r) {
/* ---------------------------------------------------------- */
		r->denom = a.denom * b.denom;
		r->num = (b.denom * a.num) + (a.denom * b.num);
		SimplificaRacional(r);
		*r;
}


/* ---------------------------------------------------------- */
	 void RestaRacional (Racional a, Racional b, Racional *r) {
/* ---------------------------------------------------------- */
		r->denom = a.denom * b.denom;
		r->num = (b.denom * a.num) - (a.denom * b.num);
		SimplificaRacional(r);
		*r;
}


/* ---------------------------------------------------------- */
	 Racional MultiplicaRacional (Racional a, Racional b) {
/* ---------------------------------------------------------- */
		struct Racional kl;
		kl.denom = a.denom * b.denom;
		kl.num = a.num * b.num;
		SimplificaRacional(&kl);
		return kl;
}


/* ---------------------------------------------------------- */
	 Racional DivideRacional (Racional a, Racional b) {
/* ---------------------------------------------------------- */

		struct Racional kl;
		kl.denom = a.denom * b.num;
		kl.num = a.num * b.denom;
		SimplificaRacional(&kl);
		return kl;
}

/* ---------------------------------------------------------- */
	 void MostrarRacional (Racional r) {
/* ---------------------------------------------------------- */
		printf("%3d", r.num);
		if (r.denom != 1)
		printf(" /%3d", r.denom);
}


/* ---------------------------------------------------------- */
	 void SimplificaRacional (Racional *r) {
/* ---------------------------------------------------------- */
		// Calcula el mcd del numerador y del denominador
		// Divide numerador y denominador por su mcd
		// Si la fracción debe llevar signo negativo (num*dem <0)
		//    entonces el signo se coloca al numerador

		 int divisor;
		 divisor = mcd (r->num, r->denom);
		 r->num = r->num / divisor;
		 r->denom = r->denom / divisor;

		 /* Siempre el signo negativo, lo lleva el numerador */

		 if ((r->num * r->denom) >=0 ){ 
				r->num = abs(r->num);
				r->denom = abs(r->denom);
		 }
		 else{ 
				r->num = -abs(r->num);
				r->denom = abs(r->denom);
		 }
}


/* ---------------------------------------------------------- */
	 int mcd (int a, int b) {
/* ---------------------------------------------------------- */
		int r;
 
	 r= a%b;
	 if (r==0)
	 {
				return b;
	 }
	 else
	 {
				return mcd(b,r);
	 }
}
