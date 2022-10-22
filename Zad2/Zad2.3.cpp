#include <stdio.h>

int main()
{
    int miesiac;
    printf("Podaj liczbe od 1 do 12: ");
    scanf("%i",&miesiac);
    if(miesiac > 12 || miesiac < 1)
    {
        printf("Liczba podana jest spodza zakresu!");
        return 0;
    }
    switch (miesiac)
    {
    case 1:
        printf("Styczen ");
        break;

    case 2:
        printf("Luty ");
        break;

    case 3:
        printf("Marzec ");
        break;

    case 4:
        printf("Kwiecien ");
        break;

    case 5:
        printf("Maj ");
        break;

    case 6:
        printf("Czerwiec");
        break;

    case 7:
        printf("Lipiec ");
        break;

    case 8:
        printf("Sierpien ");
        break;

    case 9:
        printf("Wrzesien ");
        break;

    case 10:
        printf("Pazdziernik ");
        break;

    case 11:
        printf("Listopad ");
        break;

    case 12:
        printf("Grudzien ");
        break;

    default:
        break;
    }

switch (miesiac)
{
    case 2:
        printf("ma 28 dni w roku nieprzestepnym ");
        break;

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("ma 31 dni ");
        break;

    default:
        printf("ma 30 dni ");
}

if(miesiac >= 4 && miesiac <= 9)
{
    printf("i jest sloneczny.");
}
else
{
    printf("i jest pochmurny.");
}
}