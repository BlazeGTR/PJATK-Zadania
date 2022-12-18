#include <stdio.h>

int main()
{
    int n,wynik = 0;
    printf("Podaj n: ");
    scanf("%i",&n);
    for(int i = 0; i <= n; i++)
    {
        if(i % 5 == 0 && i % 3 != 0) 
        {;
            wynik++;
        }
    }
    printf("ilosc liczb naturalnych podzielnych przez 5 a nie 3 mniejszych od %i to %i",n,wynik);
    return 0;
}