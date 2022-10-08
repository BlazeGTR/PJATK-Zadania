#include <stdio.h>

int main()
{
    int a,b,c;
    printf("Podaj 3 liczby calkowite: \n");
    scanf("%i %i %i",&a, &b, &c);
    if(a > b && a > c)
    {
        printf("Najwieksze jest %i",a);
            return 0;
    }
    if(b > c && b > a)
    {
        printf("Najwieksze jest %i",b);
            return 0;
    }
    if(c > a && c > b)
    {
        printf("Najwieksze jest %i",c);
            return 0;
    }
}

