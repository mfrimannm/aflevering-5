// cudb.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 5

// Strukturen student_t m� dog ikke �ndres.
typedef struct {
	char name[NAME_SIZE];
	int data;
} student_t;

int dtbConvert(int yearD, int semesterD, int gpaD);

void udskrivListen(student_t students[], int studentNrs);

int main() {
	// starter med at lave et array som kommer til at indeholde mine student_t informaioner
	// dette for en given l�ngde hvilke selvf�lgelig er en begr�sning.
	student_t students[10000];
	// her laver jeg nogen af de variabler jeg skal bruge senere
	// samt s�tter den nuv�rende antal studerende i databasen til 0 og name bliver defineret som en "string" p� 5 char + '\0'
	int svar = 1;
	int studentNrs = 0;
	char userName[(NAME_SIZE + 1)];
	double gpaTemp = 0;
	int startYearTemp = 0;
	int startSemesterTemp = 0;
	// spring or autumn
	userName[0] = '\0';

	printf("Welcome to CUDB - The C University Data Base\n\n");

	printf(
			"0: Halt\n1: List all students\n2: Add a new student\n\nEnter action:\n");
	fflush(stdout);
	scanf("%d", &svar);

	while (!(svar == 0)) {
		if (1 == svar) {
			// giver funktionen arrayet med studerende og antallet af dem.
			udskrivListen(students, studentNrs);

			printf("Enter action:\n");
			fflush(stdout);
			scanf("%d", &svar);
		} else if (2 == svar) {
			//addNew
			studentNrs++; // denne studerende bliver s� den n�ste
			// jeg g�r dette s� ingen studerende bliver den nulte da dette ikke giver mening, dog betyder det ogs� at mit array bliver
			// 1 indetret og ikke 0 indexret.

			// spr�g til navn
			printf("Enter name (max 5 char):\n");
			fflush(stdout);
			scanf("%5s", userName); // jeg forventer at folk kun skriver 5 tegn ind maks.
			userName[5] = '\0'; // og afslutter lige min streg ordenligt.

			strncpy(students[studentNrs].name, userName, NAME_SIZE);

			// spr�g til data s�som start �r og s� videre.
			printf("Enter start year (2009-2040):\n");
			fflush(stdout);
			scanf("%i", &startYearTemp);

			printf("Enter start semester (0=Autumn/1=Spring):\n");
			fflush(stdout);
			scanf("%i", &startSemesterTemp);

			printf("Enter GPA (0-255):\n");
			fflush(stdout);
			scanf("%lf", &gpaTemp);

			// gemmmer i students[studentNrs] til sidst laver en string som samles
			students[studentNrs].data = dtbConvert(startYearTemp,
					startSemesterTemp, gpaTemp);
			printf("Tak\n");
			// spr�ger til en ny handling
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

int dtbConvert(int yearD, int semesterD, int gpaD) {
	yearD -= 2009; // jeg rykker mit �rs tal s� 2009 er 0 og den kan s� l�be 31 �r op.
	semesterD *= 32; // jeg ganger med 32 s� jeg f�r rykket den til bit 5
	int gpaB = 0; // denne indeholder GPA i bin�re tal, den skal nu konverteres for neden
	gpaB = ((gpaD / 128) % 2) * 8192; // her tjekkes f�rst om der er en 128'er og derefter rykkes til til bit 13 bit
	gpaB += ((gpaD / 64) % 2) * 4096; // her tjekkes for 64 og igen rykkes det
	gpaB += ((gpaD / 32) % 2) * 2048;
	gpaB += ((gpaD / 16) % 2) * 1024;
	gpaB += ((gpaD / 8) % 2) * 512;
	gpaB += ((gpaD / 4) % 2) * 256;
	gpaB += ((gpaD / 2) % 2) * 128;
	gpaB += (gpaD % 2) * 64;

	return yearD + semesterD + gpaB; // til sidst l�gges tallene sammen og retuneres.

}

void udskrivListen(student_t students[], int studentNrs) {
	int i;
	for (i = 1; i <= studentNrs; i++) {
		//Printer navn
		printf("s%i %s ", i,students[i].name);
		int yearD, semesterD, gpaD;
		//converter nu daten fra et int tal som indeholder b�de �rstal, semester og gpa til tre variable som kan udskrives.
		yearD = students[i].data % 2; // den tager dataen ud tjekker om det er 1 eller 0 og ganger det op
		yearD += ((students[i].data / 2) % 2) * 2;
		yearD += ((students[i].data / 4) % 2) * 4;
		yearD += ((students[i].data / 8) % 2) * 8;
		yearD += ((students[i].data / 16) % 2) * 16;
		yearD += 2009;
		semesterD = ((students[i].data / 32) % 2) * 32;
		gpaD = (students[i].data / 64) % 2;
		gpaD += ((students[i].data / 128) % 2) * 2;
		gpaD += ((students[i].data / 256) % 2) * 4;
		gpaD += ((students[i].data / 512) % 2) * 8;
		gpaD += ((students[i].data / 1024) % 2) * 16;
		gpaD += ((students[i].data / 2048) % 2) * 32;
		gpaD += ((students[i].data / 4096) % 2) * 64;
		gpaD += ((students[i].data / 8192) % 2) * 128;

		//Printer start �r
		printf("%d ", yearD);
		//Printer start semester
		if (gpaD) {
			printf("Spring ");
		} else {
			printf("Autumn ");
		}
		//Printer GPA
		printf("GPA: %d\n", gpaD); // og laver linje skfit.

	}

}

