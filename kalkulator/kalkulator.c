#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int enterNumber(double *pliczba);
double suma(const double *x, const double *y);
double roznica(const double *x, const double *y);
double iloczyn(const double *x, const double *y);
int iloraz(const double *x, const double *y, double *pwynik);

int main()
{
    char znak;
    double a, b, wynik;
    bool stan;
    do
    {
        do
        {
            printf("Podaj dzialanie (+, -, *, /): \n");
            fflush(stdin);
            znak = getchar();
        } while ((znak != '+') && (znak != '-') && (znak != '*') && (znak != '/'));

        do
        {
            stan = enterNumber(&a);
        } while (stan == 0);

        do
        {
            stan = enterNumber(&b);
        } while (stan == 0);

        switch (znak)
        {
        case '+':
            wynik = suma(&a, &b);
            break;
        case '-':
            wynik = roznica(&a, &b);
            break;
        case '*':
            wynik = iloczyn(&a, &b);
            break;
        case '/':
            stan = iloraz(&a, &b, &wynik);
            break;
        }

        if (stan == 1)
        {
            printf("%lf\n", wynik);
        }
        else
        {
            printf("Nie dziel przez 0\n");
        }

        printf("Czy chcesz powtorzyc program? (t - tak, inny znak - nie): ");
        fflush(stdin);
    } while (tolower(getchar()) == 't');
    return 0;
}

int enterNumber(double *pliczba)
{
    printf("Podaj liczbe: ");
    fflush(stdin);
    return scanf("%lf", pliczba);
}

double suma(const double *x, const double *y)
{
    return (*x + *y);
}

double roznica(const double *x, const double *y)
{
    return (*x - *y);
}

double iloczyn(const double *x, const double *y)
{
    return (*x * *y);
}

int iloraz(const double *x, const double *y, double *pwynik)
{
    if (*y != 0)
    {
        *pwynik = (*x / *y);
        return 1;
    }
    else
    {
        return 0;
    }
}