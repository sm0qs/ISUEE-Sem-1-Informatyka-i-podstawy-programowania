#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main()
{
    double a, b, c;

    printf("Program wyznacza rozwiazania rownania: ax + bx + c = 0\n");

    do
    {
        do
        {
            printf("Podaj wspolczynnik a: ");
            fflush(stdin);
        } while (!scanf("%lf", &a));

        do
        {
            printf("Podaj wspolczynnik b: ");
            fflush(stdin);
        } while (!scanf("%lf", &b));

        do
        {
            printf("Podaj wspolczynnik c: ");
            fflush(stdin);
        } while (!scanf("%lf", &c));

        // ax^2 + bx + c = 0

        if (a == 0)
        {
            printf("Rówanie jest liniowe");
            // bx+c=0 | -c -> bx=-c |:b -> x=-c/b
            if (b == 0)
            {
                if (c == 0)
                {
                    printf("Nieszkonczenie wiele rozwiazan");
                }
                else
                {
                    printf("Rownanie sprzeczne");
                }
            }
            else
            {
                printf("x =  %lf", -c / b);
            }
        }
        else
        {
            double delta = b * b - 4 * a * c;

            if (delta < 0)
            {
                printf("Brak rozwiazan");
            }
            else if (delta == 0)
            {
                printf("x(0) = %lf", -b / (2 * a));
            }
            else
            {
                printf("x(1) = %lf\n", (-b - sqrt(delta)) / (2 * a));
                printf("x(2) = %lf\n", (-b + sqrt(delta)) / (2 * a));
            }
        }

        printf("Czy chcesz powtorzyc program? (t - tak, inny znak - nie): ");
        fflush(stdin);
    } while (tolower(getchar()) == 't');

    return 0;
}