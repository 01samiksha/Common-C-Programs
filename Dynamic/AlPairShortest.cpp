#include<iostream>
using namespace std;

const int INF = 30000, NIL = -1;
const int n =4;



//------------------Print Shortest Path for printing all pairs-------------------
void printAllPairs(int **p, int i, int j)
{
	if(i == j)
		cout <<"v" << i + 1 <<" ";

	else if(p[i][j] == NIL)
		cout << "No path from v"<<i + 1 <<" to v"<< j + 1;

	else
	{
		printAllPairs(p, i, p[i][j]);
		cout <<"v" << j + 1<<" ";
	}
}



//-----------------Calculating the minimum distance between source and dest-----------------
int alPairShortest(int d[][n], int x, int y, int n )
{
	int **p, t, c, i, j, k;

	p = new int *[n];


//----------Initializing path matrix with enteries for path[k] = 0----------------------
	for (i = 0; i < n; ++i)
	{
		p[i] = new int [n];

		for (int j = 0; j < n; ++j)
		{
			if( (i == j) || (d[i][j] == INF) )
				p[i][j] = NIL;
			else
				p[i][j] = i;
		}	
	}


//-------------Calculating distance matrix---------------------------------
	for (k = 0; k < n; ++k)
    	for (i = 0; i < n; ++i)
	    	for (j = 0; j < n; ++j)
			{
				c = d[i][k] + d[k][j];
				if(c < d[i][j])
				{
					d[i][j] = c;
					
					if(k > NIL)
						p[i][j] = p[k][j];
				}

			}


	cout<<"\n---------------PATH MATRIX---------------------\n";

		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				if (p[i][j] == NIL)
					cout<<"NIL\t";
				else
					cout<<p[i][j]<<"\t";
			}
			cout<<endl;
		}

	cout<<"\n---------------DISTANCE MATRIX---------------------\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(d[i][j] == INF)
				cout<<"INF\t";
			else
				cout<<d[i][j]<<"\t";
		}
		cout<<endl;
	}		


	cout<<endl;

	if (d[x][y] == INF)
	cout<<"Minimum distance is INF"<<endl;

	else
	cout<<"Minimum distance is "<<d[x][y]<<endl;

	cout<<endl<<"Path is: " ;

	printAllPairs(p, x, y);

}


int main()
{

//------------------EXAMPLE 1------------------------------

	int graph[][n] = { {0,   5,  7, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };


//------------------EXAMPLE 2------------------------------

	// int graph[n][n] = {	{0, 1, 4, INF, 12},
	// 					{INF, 0, 2, INF, INF},
	// 					{INF, INF, 0, 3, 2},
	// 					{INF, INF, INF, 0, 5},
	// 					{INF, INF, INF, INF, 0}
	// 				  };


    int x, y;
    cout<<"Enter the src and dest to trace the path: ";
    cin >> x >> y;
    alPairShortest(graph, x - 1, y - 1, n);
}




