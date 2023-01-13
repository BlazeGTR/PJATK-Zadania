#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

#define HWeight 0  
#define RandWeight 1

struct Node
{
    int value;
    int x;
    int y;
    int Hcost;
    int Gcost;
    int Fcost;
    Node* parent;
    bool path;
};
//Node *mapa;

bool compare(Node *str1, Node *str2)
{
    if(str1->Fcost > str2->Fcost)
        return true;
    else
        return false;
}

/// @brief Initialize the array with random numbers 1-9
/// @param x x size
/// @param y y size
/// @param map pointer to first ndoe 
void init(int x,int y,Node* map)
{
    for(int i = 0; i < y*x; i++)
    {
        (map + i)->value = ((rand() % 9) + 1)*RandWeight;
        (map + i)->x = i%x;
        (map + i)->y = abs((i/x));
        (map + i)->Fcost = 0;
        (map + i)->Gcost = 0;
        (map + i)->parent = NULL;
        (map + i)->path = false;
    }
}

/// @brief Display whole array
/// @param x x size
/// @param y y size
/// @param map pointer to first ndoe
void display(int x,int y,Node* map, bool Fonly = false)  
{
    if(!Fonly)
    {
        printf("Values:\n");
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                printf("%i  ",(map + j + (i*x))->value);
            }
            printf("\n");
        }

        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                printf("X:%i Y:%i  ",(map + j + (i*x))->x,(map + j + (i*x))->y);
            }
            printf("\n");
        }
        printf("Gcost:\n");
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                printf("%i  ",(map + j + (i*x))->Gcost);
            }
            printf("\n");
        }
        printf("Hcost:\n");
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                printf("%i  ",(map + j + (i*x))->Hcost);
            }
            printf("\n");
        }
        /*
        printf("OPEN:\n");
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                printf("%i  ",(map + j + (i*x))->);
            }
            printf("\n");
        }
        printf("CLOSED:\n");
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                printf("%i  ",(map + j + (i*x))->Hcost);
            }
            printf("\n");
        }*/
    }
    printf("Fcost:\n");
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            printf("%i  ",(map + j + (i*x))->Fcost);
        }
        printf("\n");
    }
}

/// @brief Calculate H cost for every node
/// @param x x size
/// @param y y size
/// @param map pointer to first ndoe
/// Hcost = Distance to goal
void Hcalc(int x,int y,Node* map)
{
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            (map + j + (i*x))->Hcost = (sqrt(i*i + (j-x+1)*(j-x+1)))*10*HWeight;
        }
    }
}

/// @brief Calculate Fcost
/// @param x x size
/// @param y y sizea
/// @param map pointer to first ndoe
/// @param open a list of open nodes
/// @param closed a list of closed nodes
bool Fcalc(int x,int y,Node** map,vector<Node*> *open,vector<Node*> *closed)
{
    Node *currentNode = *(open->end()-1);
    (*open).pop_back();
    (*closed).push_back(currentNode);
    printf("Checking node X:%i Y:%i \n",currentNode->x,currentNode->y);
    if(currentNode->x == x-1 && currentNode->y == 0)
    {
        return true;
    }
    vector<Node*> neighbours;

    if (currentNode->x%x != 0) //not touching left wall
    {
        neighbours.push_back((currentNode-1));
        if (currentNode->y != y-1) //not touching bottom left corner
        {
            neighbours.push_back((currentNode+x-1));
        }
        if (currentNode->y != 0) //not touching yop left corner
        {
            neighbours.push_back((currentNode-x-1));
        }
    }
    if (currentNode->x%x != x-1) //not touching right wall
    {
        neighbours.push_back((currentNode+1));
        if (currentNode->y != y-1) //not touching bottom right corner
        {
            neighbours.push_back((currentNode+x+1));
        }
        if (currentNode->y != 0) //not touching yop right corner
        {
            neighbours.push_back((currentNode-x+1));
        }
    }
    if (currentNode->y != y-1) //not touching bottom wall
    {
        neighbours.push_back((currentNode+x));
    }
    if (currentNode->y != 0) //not touching top wall
    {
        neighbours.push_back((currentNode-x));
    }

    vector<Node*>::iterator it;
    vector<Node*>::iterator findIt;
    for(it = neighbours.begin(); it != neighbours.end(); ++it)
    {
        Break:
        for(findIt = closed->begin(); findIt != closed->end(); ++findIt)
        {
            if((*findIt)->x == (*it)->x && (*findIt)->y == (*it)->y)
            {    
                ++it;   //found in closed, dont check
                if(it != neighbours.end())
                    goto Break;         //im so sorry for using goto but its the only way to break out of a nested loop
                else
                    goto MegaBreak;
            }
        }
        double xDiff,yDiff;
        xDiff = (*it)->x - currentNode->x;
        yDiff = (*it)->y - currentNode->y;
        //printf("Gcoststs: %i\n",sqrt(xDiff*xDiff + yDiff*yDiff));
        int dist = sqrt(xDiff*xDiff + yDiff*yDiff)*10;
        int newGcost = currentNode->Gcost + dist;
        //int newFcost = (*it)->value+newGcost+(*it)->Hcost;    //zmiania na djikstre
        int newFcost = (*it)->value + currentNode->Fcost;
        
        bool isInOpen = false;
        for(findIt = open->begin(); findIt != open->end(); ++findIt)
        {
            if((*findIt)->x == (*it)->x && (*findIt)->y == (*it)->y)
            {
                isInOpen = true;
                break;       //found in closed, dont check
            }
        }

        if(newFcost < (*it)->Fcost || !isInOpen)
        {
            (*it)->Gcost = newGcost;
            //(*it)->Fcost = (*it)->value+newGcost+(*it)->Hcost;    //zmiania na djikstre
            (*it)->Fcost = (*it)->value + currentNode->Fcost;
            (*it)->parent = currentNode;
            if(!isInOpen)
            {
                open->push_back(*it);
            }
        }
        //printf("FCOST: %i X:%i Y:%i\n",(*it)->Fcost,(*it)->x,(*it)->y);
    }
    MegaBreak:
    return false;
}


int main()
{
    clock_t start, end;
    //Initialisation
    int x, y;
    //srand(time(NULL));
    srand(1);
    vector<Node*> open;
    vector<Node*> closed;

    //Getting values
    printf("Podaj wymiary tablicy do zainicjowania\nX: ");
    scanf("%i",&x);
    printf("Y: ");
    scanf("%i",&y);

    

    //more init
    start = clock();
    Node* mapa = (Node*)malloc(x*y*(sizeof(Node)));
    if(mapa == NULL)
    {
        printf("err");
    }
    init(x,y,mapa);

        printf("Values:\n");
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                printf("%i  ",(mapa + j + (i*x))->value);
            }
            printf("\n");
        }

    Hcalc(x,y,mapa);
    int startIndex = ((x)*(y-1));
    open.push_back(mapa+startIndex); //adding start node to the open list
    bool goal = false;

    //doing pathfinding magic
    while(!goal)
    {
        //printf("Evaluating X:%i Y:%i\n",(*(open.end()-1))->x,(*(open.end()-1))->y);
        goal = Fcalc(x,y,&mapa,&open,&closed);
        if(open.size() != 1)
        {
            sort(open.begin(),open.end(),compare);
        }
        //display(x,y,mapa,true);
        //getch();
    }
    // printf("starter node value: %i ",((mapa+(x*y)-x)->value));
    // printf("%i",((mapa+1)->value));
    Node* endPath;
    endPath = (mapa+x-1);
    int suma = 0;
    while (endPath->parent != NULL)
    {
        printf("Path:%i\n",endPath->value);
        suma += endPath->value;
        endPath->path = true;
        endPath = endPath->parent;
    }
    suma += endPath->value;
    endPath->path = true;
    endPath = endPath->parent;

    end = clock();

    display(x,y,mapa);
    for(int i = 0; i < y; i++)      //print the end path, Rouge style
    {    
        for(int j = 0; j < x; j++)
        {
            if ((mapa + j + (i*x))->path)
            {
                printf("@ ");
            }
            else
            {
                printf(". ");
            }
        }
    printf("\n");
    }

    printf("Suma:%i\n",suma);
    printf("\nPress any key to continue.\n");
    printf("start: %i\n",start);
    printf("start: %i\n",end);
    double elapsedTime = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken:%.10lfs",elapsedTime);
    getch();
    return 0;
}
