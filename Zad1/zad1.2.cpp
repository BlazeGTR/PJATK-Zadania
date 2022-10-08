#include <stdio.h>

int main()
{
    int liczba;
    printf("Podaj liczbe calkowita: ");
    scanf("%i",&liczba);
    if(liczba == 0)
    {
        printf("Liczba %i jest rowna 0",liczba);
        return 0;
    }
    if(liczba > 0)
    {
        printf("Liczba %i jest dodatnia",liczba);
        return 0;
    }
    printf("Liczba %i jest ujemna",liczba);
    return 0;
}