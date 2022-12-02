#include <stdio.h>

int main()
{
    int x;
    printf("Podaj rozmiar tablicy: ");
    scanf("%i",&x);
    int tablica[x];
    for(int i = 0; i<x; i++)
    {
        printf("Podaj element nr%i: ",1+i);
        scanf("%i", &tablica[i]);
    }
    int najwEl = (tablica[0]);
    for(int i = 0; i<x; i++)
    {
        if(tablica[i] > najwEl) najwEl = tablica[i];
    }
    printf("Najwiekszy element to: %i",najwEl);
}