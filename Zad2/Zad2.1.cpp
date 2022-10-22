#include <stdio.h>

int main()
{
    int n,suma;
    printf("Podaj n: ");
    scanf("%i", &n);
    for(int i = 0; i <= n; i++)
    {
        for(int j = i; j > 0; j--)
        {
            suma += j;
        }
    }
    printf("%i",suma);
}