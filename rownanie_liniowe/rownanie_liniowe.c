#include <stdio.h>

double a, b;

int main() {
	do {
		printf("Podaj 1 liczbe: ");
		fflush(stdin);
	} while (!scanf("%lf", &a));

	do {
		printf("Podaj 2 liczbe: ");
		fflush(stdin);
	} while (!scanf("%lf", &b));

	// ax+b=0 | -b -> ax=-b |:a -> x=-b/a

	if (a == 0) {
		if (b == 0) {
			printf("Nieszkonczenie wiele rozwiazan");
		} else {
			printf("Rownanie sprzeczne");
		}
	} else {
		printf("x =  %lf", -b / a);
	}

	return 0;
}
