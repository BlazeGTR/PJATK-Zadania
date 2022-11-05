#include <stdio.h>
#include <conio.h>

int main()
{
    float x, y;
    scanf("%f %f", &x, &y);
    printf("Suma: %.2f\nRoznica: %.2f\nIloczyn: %.2f\nIloraz: %.2f\n",(x+y),x-y,x*y,x/y);
    getch();
}