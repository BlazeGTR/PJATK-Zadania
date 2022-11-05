#include <stdio.h>
#include <conio.h>

int main()
{
    printf("Podaj znak: ");
    char znak;
    znak = getch();
    while (znak != 't')
    {
        printf("Podales: %c\n",znak);
        printf("Podaj znak: ");
        znak = getch();
    }
    printf("Podales: %c",znak);
}