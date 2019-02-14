#include<iostream>
#include<graphics.h>
using namespace std;

void nextVal(int G[][7], int k, int x[], int m, int n)
{
    int i;
    do
    {
        x[k] = (x[k] + 1 ) ;

        if(x[k] == m+1)
            return;

        for (i = 0; i < n; ++i)
        {
            if( (G[k][i] != 0) && x[k] == x[i])
                break;
        }

        if(i == n)
            return;
    }while(1);

}

void graphColoring(int G[][7], int k, int x[], int n, int m)
{
    if(k == n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << x[i] << " " ;
        }
        return;
    }

    nextVal(G, k, x, m, n);

    if(x[k] == m+1)
    {
        cout << "It is not possible to color this graph using " << m <<" colors\n";
        return;
    }

    else
        graphColoring(G, k+1 , x, n, m);


}


int main()
{
    int n = 7, m;
    cin >> m;
    int G[][7] = { {0, 1, 0, 1, 0, 0, 1},
                {1, 0, 1, 0, 1, 0, 0},
                {0, 1, 0, 1, 0, 0, 0},
                {0, 0, 1, 0, 1, 1, 1},
                {1, 1, 0, 1, 0, 1, 1},
                {0, 0, 0, 1, 1, 0, 0},
                {1, 0, 0, 1, 1, 0, 0} }; 

    
    int x[n];
    //new int *[n];

    for (int i = 0; i < n; ++i)
        x[i] = 0;

    graphColoring(G, 0, x, n, m);

}