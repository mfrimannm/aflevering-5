// stack.c

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*

Tilføj funktionerne newStack, pop, push, top og empty.

*/


// denne funktion skal lave et nyt array med længden af ens
// stack_t struktur.
stack_t * newStack(void){

	stack_t * result = malloc(sizeof (stack_t));

	return result;
};

/* man tager det øvereste element af
 */
int pop(stack_t * stack_p){
	int takkenOff = 0;


	return takkenOff;
};


/* denne lægger et tal oven på ens array som kan forstås som
 * en pind der lægges tal på.
 * dette betyder også at hvis man ligger to tal på skal man
 * tage 1 af for at komme til det første man lage på det
 * kommer altså til at ligge nederest.
 */
void push(stack_t * stack_p, int value){

	return
};


int top(stack_t * stack_p){

	return
};

/* denne tjekker om ens array er tomt eller ej, hvis det er
 * vil den returnere true (altså hvis det er tomt).
 */
int empty(stack_t * stack_p){

	return
};
