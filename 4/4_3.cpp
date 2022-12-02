#include <stdio.h>

int main()
{
    int tab[10][10];

    for(int i = 0; i<10;i++)
    {
        for(int j = 0; j<10;j++)
        {
            tab[j][i] = 0;
        }
    }

    for(int i = 0; i<10;i++)
    {
        tab[0][i] = i;
    }

    for(int i = 0; i<10;i++)
    {
        tab[1][i] = i+i;
    }

    for(int i = 0; i<10;i++)
    {
        tab[2][i] = i*i;
    }

    for(int i = 0; i<10;i++)
    {
        tab[3][i] = i+4;
    }

    for(int i = 0; i<10;i++)
    {
        tab[4][i] = 5-i;
    }

    for(int i = 0; i<10;i++)
    {
        for(int j = 0; j<10;j++)
        {
            printf("%i ",tab[j][i]);
        }
        printf("\n");
    }
}