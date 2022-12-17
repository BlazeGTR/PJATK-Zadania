#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    vector<int> x;
    int size;
    printf("Podaj liczbe elementow wektora: ");
    scanf("%i",&size);

    int y;
    for(int i = 0;i<size;i++)
    {
        printf("Podaj wartosc elementu nr %i: ",i+1);
        scanf("%i",&y);
        x.push_back(y);
    }

    int max = x[0];
    int indeks = 0;
    for(int i = 1;i<size;i++)
    {
        if(x[i] > max)
        {
            max = x[i];
            indeks = i;
        }
    }
    printf("Najwiekszy element to %i a jego indeks to %i.",max,indeks);
    return 0;
}