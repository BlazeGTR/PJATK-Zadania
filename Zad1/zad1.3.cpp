#include <stdio.h>

int main()
{
    int liczba;
    printf("Podaj liczbe do sprawdzenia: ");
    scanf("%i",&liczba);
    if(liczba == 0)
    {
        printf("Liczba rowna jest 0");
        return 0;
    }
    if(liczba % 2 == 0)
    {
        printf("Liczba jest parzysta");
        return 0;
    }
    printf("Liczba jest nieparzysta");
    return 0;
}