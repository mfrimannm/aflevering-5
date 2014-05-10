// cudb.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 5

// Strukturen student_t må dog ikke ændres.
typedef struct {
	char name[NAME_SIZE];
	int data;
} student_t;

int main() {
	int svar = 1;
	int studentNrs = 0;
	char *userName ="\0";

	printf("Welcome to CUDB - The C University Data Base\n\n");

	printf("0: Halt\n1: List all students\n2: Add a new student\n\nEnter action:\n");
	fflush(stdout);
	scanf("%d", &svar);

	while (!(svar == 0)) {
		if (1 == svar) {
			//	listAll
			/*
			 * s0000 John 2009 Spring 200
			 * s0001 Mary 2040 Autumn 250
			 * Average GPA = 225.00
			 */




			// sprøger til en ny handling
			printf("Enter action:\n");
			fflush(stdout);
			scanf("%d", &svar);
		} else if (2 == svar) {
			//addNew

			// sprøg til navn
			printf("Enter name:\n");
			fflush(stdout);
			scanf("%s", &userName);
			printf("&s",userName);

			strTypeNr = strcat(strTypeNr, studentNrs);
			printf("%s",strTypeNr);
			student_t strTypeNr;
			strncpy(strTypeNr.name,userName, NAME_SIZE);

			studentNrs++;
			// sprøger til en ny handling
			printf("Enter action:\n");
			fflush(stdout);
			scanf("%d", &svar);
		} else {
			printf("fejl\nIndtast nyt tal mellem 0 og 2:\n");
			fflush(stdout);
			scanf("%d", &svar);
		};
	};

	printf("Farvel!");
	return 0;
}


