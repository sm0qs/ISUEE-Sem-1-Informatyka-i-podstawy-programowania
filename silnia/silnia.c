#include <stdio.h>

int main()
{
    int a;
    unsigned long long s = 1;

    do
    {
        printf("Podaj liczbe naturalna nieujemna: ");
        fflush(stdin);
    } while ((!scanf("%d", &a)) || a < 0 || a > 20);

    int i;
    for (i = 1; i <= a; i++)
    {
        s = i * s;
    }

    printf("Silnia = %llu", s);

    return 0;
}
