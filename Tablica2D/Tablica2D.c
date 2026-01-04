#include <stdio.h>
#include <stdlib.h>

const unsigned int MAX_SIZE = 2;

double **allocTab2D(const unsigned int rows, const unsigned int cols) {
	double **tabW = malloc(rows * sizeof(double *));
	for (unsigned int i = 0; i < rows; i++) {
		tabW[i] = malloc(cols * sizeof(double));
	}
	return tabW;
}

void freeTab2D(double **tab, const unsigned int rows) {
	for (unsigned int i = 0; i < rows; i++) {
		free(tab[i]);
	}
	free(tab);
}

void wczytaj2D(double **tab, const unsigned int rows, const unsigned int cols) {
	printf("Wprowadzanie tablicy %ux%u:\n", rows, cols);
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			do {
				printf("tab[%u][%u]=", i, j);
				fflush(stdin);
			} while (!scanf("%lf", &tab[i][j]));
		}
	}
}

void wypisz2D(double **tab, const unsigned int rows, const unsigned int cols) {
	printf("Wprowadzona tablica to:\n");
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			printf("%lf ", tab[i][j]);
		}
		printf("\n");
	}
}

unsigned int policzWiekszeOdZera2D(double **tab, const unsigned int rows, const unsigned int cols) {
	unsigned int licznik = 0;
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			if (tab[i][j] > 0) {
				licznik++;
			}
		}
	}
	return licznik;
}

double max2D(double **tab, const unsigned int rows, const unsigned int cols, unsigned int *maxW,
             unsigned int *maxK) {
	double max = tab[0][0];
	*maxW = 0;
	*maxK = 0;
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			if (tab[i][j] > max) {
				max = tab[i][j];
				*maxW = i;
				*maxK = j;
			}
		}
	}
	return max;
}

double *sumaWierszy(double **tab, const unsigned int rows, const unsigned int cols) {
	double *tab1D = malloc(rows * sizeof(double));
	if (tab1D == NULL) {
		printf("Brak pamieci na rezerwacje tablicy!\n");
		return NULL;
	}
	for (unsigned int i = 0; i < rows; i++) {
		double sumW = 0;
		for (unsigned int j = 0; j < cols; j++) {
			sumW = sumW + tab[i][j];
		}
		tab1D[i] = sumW;
	}
	return tab1D;
}

void wypisz1D(const double *tab, const unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		printf("Wiersz [%u]: %lf\n", i, tab[i]);
	}
	printf("\n");
}

int main() {
	unsigned int wybor, rows, cols;
	double maxVal;
	unsigned int maxW, maxK;
	double *sumW;
	double **tablica;

	printf("Wybierz wariant tablicy dwuwymiarowej:\n");
	printf("1 - tablica statyczna (2x2)\n");
	printf("2 - tablica dynamiczna (rozmiar n x n)\n");

	do {
		printf("Podaj numer (1/2): ");
		fflush(stdin);
	} while (!scanf("%u", &wybor) || (wybor != 1 && wybor != 2));

	if (wybor == 1) {
		rows = MAX_SIZE;
		cols = MAX_SIZE;
	} else {
		do {
			printf("Podaj liczbe wierszy (m >= 1): ");
			fflush(stdin);
		} while (!scanf("%u", &rows) || rows < 1);

		do {
			printf("Podaj liczbe kolumn n (n >= 1): ");
			fflush(stdin);
		} while (!scanf("%u", &cols) || cols < 1);
	}

	tablica = allocTab2D(rows, cols);

	wczytaj2D(tablica, rows, cols);
	wypisz2D(tablica, rows, cols);

	printf("Tablica zawiera %u elementow wiekszych od zera\n",
	       policzWiekszeOdZera2D(tablica, rows, cols));

	maxVal = max2D(tablica, rows, cols, &maxW, &maxK);
	printf("Wartosc maksymalna = %lf na pozycji [%u][%u]\n", maxVal, maxW, maxK);

	sumW = sumaWierszy(tablica, rows, cols);
	printf("Sumy elementow w poszczegolnych wierszach:\n");
	wypisz1D(sumW, rows);
	free(sumW);
	freeTab2D(tablica, rows);

	return 0;
}
