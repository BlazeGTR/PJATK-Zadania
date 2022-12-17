#include <stdio.h>
#include <cstdlib>

int main()
{
    int x,y;
    scanf("%i %i",&x,&y);
    int* arr = (int*)malloc(x*y*sizeof(int));
    int* arrTemp = (int*)malloc(x*y*sizeof(int));

    for(int i = 0; i < (x*y);i++)
    {
        printf("podaj liczbe wpisania w tab[%i][%i]: ",(i%x),(i/x));
        scanf("%i",(arr+i));
    }

    printf("Tablica wejsciowa:\n");
    for(int i = 0; i < y;i++)
    {
        for(int j = 0; j < x;j++)
        {
            printf("[%i]" ,*(arr+j+(x*i)));
        }
        printf("\n");
    }
    printf("\n");


    for(int i = 0; i < y;i++)
    {
        for(int j = 0; j < x;j++)
        {
            *(arrTemp+(x*i)+(x-1)-j)= *(arr+j+(x*i));
        }
    }

    for(int i = 0; i < (x*y);i++)
    {
        *(arr+i) = *(arrTemp+i);
    }

    printf("Tablica wejsciowa:\n");
    for(int i = 0; i < y;i++)
    {
        for(int j = 0; j < x;j++)
        {
            printf("[%i]" ,*(arr+j+(x*i)));
        }
        printf("\n");
    }
    return 0;
}