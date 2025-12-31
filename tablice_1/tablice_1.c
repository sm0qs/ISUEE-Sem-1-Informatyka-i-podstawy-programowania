#include <stdio.h>
#include <stdlib.h>

const unsigned int MAX_SIZE = 3;

// deklaracje funkcji
void wczytaj_tablice(double tab[], int rozmiar);
void wypisz_tablice(double tab[], int rozmiar);
unsigned int policz_wieksze_od_zera(double tab[], int rozmiar);
double policz_sume(double tab[], int rozmiar);
void znajdz_maximum(double tab[], int rozmiar, int *pindex, double *pmax);

int main() {
	int wybor;
	printf("Wybierz wariant:\n");
	printf("1 - tablica statyczna (%d elementy)\n", MAX_SIZE);
	printf("2 - tablica dynamiczna\n");

	do {
		printf("Podaj numer (1/2): ");
		fflush(stdin);
	} while (!scanf("%d", &wybor) || (wybor != 1 && wybor != 2));

	if (wybor == 1) {
		double tablica[MAX_SIZE];
		int index_max;
		double wartosc_max;

		printf("\nTablica statyczna.\n");
		// pkt 1
		wczytaj_tablice(tablica, MAX_SIZE);
		// pkt 2
		wypisz_tablice(tablica, MAX_SIZE);
		// pkt 3
		printf("Tablica zawiera %u elementy wieksze od zera.\n",
		       policz_wieksze_od_zera(tablica, MAX_SIZE));
		// pkt 4
		printf("Suma elementow = %lf\n", policz_sume(tablica, MAX_SIZE));
		// pkt 5
		znajdz_maximum(tablica, MAX_SIZE, &index_max, &wartosc_max);
		printf("Index elementu maksymalnego = %d, wartosc = %lf\n", index_max, wartosc_max);
	} else if (wybor == 2) {
		double *tablica;
		unsigned int rozmiar;
		int index_max;
		double wartosc_max;

		printf("\nTablica dynamiczna.\n");

		do {
			printf("Podaj rozmiar tablicy: ");
			fflush(stdin);
		} while (!scanf("%u", &rozmiar) || rozmiar == 0);

		tablica = malloc(rozmiar * sizeof(double));

		if (tablica == NULL) {
			printf("Blad alokacji pamieci.\n");
			return 0;
		}

		// pkt 1
		wczytaj_tablice(tablica, rozmiar);
		// pkt 2
		wypisz_tablice(tablica, rozmiar);
		// pkt 3
		printf("Tablica zawiera %u elementy wieksze od zera.\n",
		       policz_wieksze_od_zera(tablica, rozmiar));
		// pkt 4
		printf("Suma elementow = %lf\n", policz_sume(tablica, rozmiar));
		// pkt 5
		znajdz_maximum(tablica, rozmiar, &index_max, &wartosc_max);
		printf("Index elementu maksymalnego = %d, wartosc = %lf\n", index_max, wartosc_max);

		free(tablica);
	}

	return 0;
}

void wczytaj_tablice(double tab[], int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		do {
			printf("\nPodaj %d element: ", i);
			fflush(stdin);
		} while (!scanf("%lf", &tab[i]));
	}
}

void wypisz_tablice(double tab[], int rozmiar) {
	printf("\nTab = [%lf", tab[0]);
	for (int i = 1; i < rozmiar; i++) {
		printf(", %lf", tab[i]);
	}
	printf("];\n");
}

unsigned int policz_wieksze_od_zera(double tab[], int rozmiar) {
	unsigned int licznik = 0;
	for (int i = 0; i < rozmiar; i++) {
		if (tab[i] > 0) {
			licznik++;
		}
	}

	return licznik;
}

double policz_sume(double tab[], int rozmiar) {
	double suma = 0;
	for (int i = 0; i < rozmiar; i++) {
		suma = suma + tab[i];
	}
	return suma;
}

void znajdz_maximum(double tab[], int rozmiar, int *pindex, double *pmax) {
	int index_max = 0;
	double max = tab[0];

	for (int i = 1; i < rozmiar; i++) {
		if (tab[i] > max) {
			index_max = i;
			max = tab[i];
		}
	}

	*pindex = index_max;
	*pmax = max;
}
