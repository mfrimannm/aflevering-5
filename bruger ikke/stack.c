// stack.c

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*

Tilf�j funktionerne newStack, pop, push, top og empty.

*/


// denne funktion skal lave et nyt array med l�ngden af ens
// stack_t struktur.
stack_t * newStack(void){

	stack_t * result = malloc(sizeof (stack_t));

	return result;
};

/* man tager det �vereste element af
 */
int pop(stack_t * stack_p){
	int takkenOff = 0;


	return takkenOff;
};


/* denne l�gger et tal oven p� ens array som kan forst�s som
 * en pind der l�gges tal p�.
 * dette betyder ogs� at hvis man ligger to tal p� skal man
 * tage 1 af for at komme til det f�rste man lage p� det
 * kommer alts� til at ligge nederest.
 */
void push(stack_t * stack_p, int value){

	return
};


int top(stack_t * stack_p){

	return
};

/* denne tjekker om ens array er tomt eller ej, hvis det er
 * vil den returnere true (alts� hvis det er tomt).
 */
int empty(stack_t * stack_p){

	return
};
