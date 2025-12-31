#include <stdio.h>

int main() {
	double a, b, c;

	do {
		printf("Podaj 1 liczbe: ");
		fflush(stdin);
	} while (!scanf("%lf", &a));

	do {
		printf("Podaj 2 liczbe: ");
		fflush(stdin);
	} while (!scanf("%lf", &b));

	do {
		printf("Podaj 3 liczbe: ");
		fflush(stdin);
	} while (!scanf("%lf", &c));

	printf("Srednia arytmetyczna: %lf", (a + b + c) / 3.0);

	return 0;
}
