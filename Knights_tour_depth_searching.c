#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define STEPSLIMIT 100000 /* Pocet krokov do predcasneho ukoncenia */
#define WAYS 8 /* Osem moznych pohybov kona po sachovnici*/
//#define PRINTAXIS //odkomentovat ak sa ma vypisovat aj cislovanie na osi x a y 

void printSolution(int size);
void findSolution(int x, int y, int size);
void resetArr(int size);
void startChess(int size);

int steps = 0; /* Pocet krokov */
int printed = 0;
int **arr;

/* Osem smerov ako sa moze kon po 2D sachovnici pohybovat */
int stepX[] = { -2, -2, -1, -1,  1, 1,  2, 2 };
int stepY[] = { -1,  1, -2,  2, -2, 2, -1, 1 };

/* Vypisanie riesenia */
void printSolution(int size) {

	int i, j;

	for (i = size - 1; i > -1; i--) {
		#ifdef PRINTAXIS 
		printf("| %d | ", i + 1); 
		#endif
		for (j = 0; j < size; j++) {

			printf("[ %d ]", arr[j][i]);
		}
		printf("\n");
	}

	#ifdef PRINTAXIS 
		printf("\n y/x   ");
		for (i = 0; i < size; i++) {
			printf("| %d |", i + 1);
		}
		printf("\n");
	#endif

	printf("Pocet krokov: %d\n", steps);

	/* Oznacenie ze uz sa vypisalo riesenie */
	printed = 1;
}

/* Funkcia na hladanie riesenia */
void findSolution(int x, int y, int size) {
	int i;

	/* Ak je v poli zapisane cislo velkosti sachovnice a este nebolo vypisane riesenie tak sa vypise */
	if ((arr[x][y] == size * size) && (printed == 0)) {
		printSolution(size);
	}
	else {
		/* Depth first search
		   prehladavanie do hlbky, prehladava sa kazda mozna cesta az po kym sa da */
		for (i = 0; i < WAYS; i++) {
			/* Kontrola ci sa kon pohybuje spravne po sachovnici a ci nepresiel cez rovnake miesto viacej krat */
			if ((x + stepX[i] > -1) && (x + stepX[i] < size) && (y + stepY[i] > -1) && (y + stepY[i] < size) &&	(arr[x + stepX[i]][y + stepY[i]] == 0) && (printed == 0) && (steps < STEPSLIMIT)) {
				steps++;
				arr[x + stepX[i]][y + stepY[i]] = arr[x][y] + 1; // Oznacenie noveho miesta ako navstiveneho a zaroven poradia v ktorom bolo navstivene
				/* Rekurzivne prehladavanie kazdej cesty */
				findSolution(x + stepX[i], y + stepY[i], size);
				arr[x + stepX[i]][y + stepY[i]] = 0; // Ak sa nenasla vhodna cesta, oznacia sa postupne miesta ako nenavstivene
			}
		}
	}
}

/* Obnovenie sachovnice do povodneho stavu */
void resetArr(int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			arr[i][j] = 0;
		}
	}
}

void startChess(int size) {
	int i, x, y;

	srand(time(NULL));

	arr = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++) {
		arr[i] = (int*)malloc(size*sizeof(int));
	}

	if (size == 5) {
		steps = 0; // resetovanie hodnoty
		printed = 0; // resetovanie hodnoty
		printf("\nx: 1 , y: 1\n");
		resetArr(size); // resetovanie pola
		arr[0][0] = 1; // oznacenie ze sa zacalo na pozicii 0 0
		findSolution(0, 0, size);
	}
	else if (size == 6) {
		steps = 0; // resetovanie hodnoty
		printed = 0; // resetovanie hodnoty
		printf("\nx: 1 , y: 1\n");
		resetArr(size); // resetovanie pola
		arr[0][0] = 1; // oznacenie ze sa zacalo na pozicii 0 0
		findSolution(0, 0, size);
	}

	if (steps >= STEPSLIMIT) {
		printf("Hladanie prekrocilo povoleny limit tahov 100 000\n");
	}

	// 4 nahodne vygenerovane pozicie na zaciatku
	for (i = 0; i < 4; i++) {
		steps = 0; // resetovanie hodnoty
		printed = 0; // resetovanie hodnoty
		printf("\nx: %d , y: %d\n", (x = rand() % size) + 1, (y = rand() % size) + 1); // nahodne generovane zaciatocne pozicie
		resetArr(size); // resetovanie pola
		arr[x][y] = 1; // oznacenie ze sa zacalo na pozicii x y
		findSolution(x, y, size);
		if (steps >= STEPSLIMIT) {
			printf("Hladanie prekrocilo povoleny limit tahov 100 000\n");
		}
	}
}

int main() {

	printf("Sachovnica 5x5\n\n");
	startChess(5);
	printf("\n\nSachovnica 6x6\n\n");
	startChess(6);


	getchar();
	getchar();

	return 0;
}
