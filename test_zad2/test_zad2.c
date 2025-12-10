#include <math.h>
#include <stdio.h>

#if !defined(M_PI)
#define M_PI 3.14159265358979323846
#endif // M_PI

int main() {
  double kat, dokladnosc;

  printf("Program wyznacza cos(x) dla x podanego w stopniach\n");
  printf(
      "z zadana dokladnoscia z uzyciem rozwiniecia w szereg Maclaurina.\n\n");

  do {
    printf("Podaj x w stopniach: ");
    fflush(stdin);
  } while (!scanf("%lf", &kat));
  kat = (kat / 180) * M_PI;

  do {
    printf("Podaj dokladnosc (eps): ");
    fflush(stdin);
  } while (!scanf("%lf", &dokladnosc));

  double wyraz = 1 /*wtraz ciągu*/, suma = 1 /*suma ciągu*/;
  int n = 0 /*indeks wyrazu*/, liczbaWyrazow = 1;

  while (fabs(wyraz) > dokladnosc) {
    double licznik = -kat * kat;
    double mianownik = (2 * n + 2) * (2 * n + 1);

    wyraz = wyraz * (licznik / mianownik);

    suma = suma + wyraz;

    n = n + 1;
    liczbaWyrazow = liczbaWyrazow + 1;
  }

  printf("cos(x) =  %lf\n", suma);
  printf("Uwzgledniona liczba wyrazow szeregu =  %d\n", liczbaWyrazow);
  return 0;
}