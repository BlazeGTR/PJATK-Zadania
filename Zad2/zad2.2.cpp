#include <stdio.h>

int main()
{
    int a,b;
    printf("A)\nPodaj wartosci a oraz b: ");
    scanf("%i %i",&a,&b);
    //B
    printf("B)\n");
    for(int i = 0; i < a; i++)
    {
        printf("*");
    }
    printf("\n");

    //C
    printf("C)\n");
    for(int i = 0; i < b; i++)
    {
        printf("*\n");
    }
    printf("\n");

    //D
    printf("D)\n");
    for(int i = 0; i < a; i++)
    {
         for(int j = 0; j < b; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");


    //E
    printf("E)\n");
    for(int i = 0; i < a; i++)
    {
         for(int j = 0; j < b; j++)
        {
            if((i == 0 || i == a-1) || (j == 0 || j == b-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");


    //F
    for(int i = 0; i < a; i++)
    {
        for(int j = i; j >= 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    //G
    printf("G)\n");
    for(int i = 0; i < a; i++)
    {
         for(int j = 0; j < a; j++)
        {
            if(j >= i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}