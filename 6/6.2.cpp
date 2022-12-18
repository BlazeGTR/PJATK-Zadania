#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char *imie;
    int inf;
    int mat;
    int bio;
    int pol;
    student *next;
} ;


int main()
{
    student *osobaOld = (student*)malloc(6*sizeof(student));
    printf("Podaj imie ucznia nr 1 ");
    char *imie;
    scanf("%s",imie);
    strcpy(osobaOld->imie,imie);
    printf("Podaj ocene z informatyki :");
    scanf("%i",osobaOld->inf);
    printf("Podaj ocene z matematyki :");
    scanf("%i",osobaOld->mat);
    printf("Podaj ocene z biologii :");
    scanf("%i",osobaOld->bio);
    printf("Podaj ocene z jezyka polskiego :");
    scanf("%i",osobaOld->pol);
    student *head = osobaOld;
    for(int i = 0; i < 5; i++)
    {
        student *osoba = (student*)malloc(6*sizeof(student));
        osobaOld->next = osoba;
        osobaOld = osoba;
        
        printf("Podaj imie ucznia nr %i: ",i+1);
        char *imie;
        scanf("%s",imie);
        strcpy(osoba->imie,imie);
        printf("Podaj ocene z informatyki :");
        scanf("%i",osoba->inf);
        printf("Podaj ocene z matematyki :");
        scanf("%i",osoba->mat);
        printf("Podaj ocene z biologii :");
        scanf("%i",osoba->bio);
        printf("Podaj ocene z jezyka polskiego :");
        scanf("%i",osoba->pol);
    }

    printf("Podaj liczbe zapytan: ");
    int n; 
    scanf("%i",&n);
    for(int i = 0; i < n;i++)
    {
        printf("podaj nr ucznia: ");
        int nr;
        scanf("%i",&nr);
    }
}