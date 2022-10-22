#include <stdio.h>

int main()
{
    int pizza,kawal,gosc;
    printf("Podaj ilosc pizz, oraz na ile kawalkow sa podzielone: ");
    scanf("%i %i",&pizza,&kawal);
    printf("Podaj liczbe gosci: ");
    scanf("%i",&gosc);
    printf("Dla organizatora przypadnie %i kawalkow, a dla kazdego goscia %i",(pizza*kawal)%gosc,(pizza*kawal)/gosc);
}