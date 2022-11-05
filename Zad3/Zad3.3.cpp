#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float A, B, C;
    printf("Postac rownania kwadratowego:\nAx^2 + Bx + C\n");
    printf("Podaj A, B i C:");
    scanf("%f %f %f",&A, &B, &C);
    printf("Podanie rownanie kwadratowe to:\n%fx^2 + %fx + %f\n",A,B,C);
    float delta;
    delta = (B*B) - (4*A*C);
    if(delta < 0)
    {
        printf("Nie ma pierwiastkow");
        return 0;
    }
    printf("Pierwiastki rownania to:\n%f\n%f",(-B-sqrt(delta))/(2*A),(-B+sqrt(delta))/(2*A));
}