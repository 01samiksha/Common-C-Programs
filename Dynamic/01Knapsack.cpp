#include<iostream>
using namespace std;

void knapsack(int m, int n, int p[], int w[])
{
	int **V = new int *[n];
	int x[n], i, j;

	for (i = 0; i < n; ++i)
		V[i] = new int [m];

	for (i = 0; i < m; ++i)
		V[0][i] = 0;
		
	for (i = 0; i < n; ++i)
	{
		V[i][0] = 0; 
		x[i] = 0;
	}

	for (i = 1; i < n; ++i)
	{
		for (j = 1; j < m; ++j)
		{

			if( (V[i-1][j] < ( V[i-1][j - w[i]] + p[i]) )  && (j - w[i] >= 0))
				V[i][j] = V[i-1][j - w[i]] + p[i];
			else
				V[i][j] = V[i-1][j];
		}	
	}

	for (i = 0; i < n; ++i)
	{
		for(j = 0; j < m; j++)
			cout << V[i][j] << " "; 
		cout << endl;
	}

	i = n-1;
	j = m-1;

	while(i > 0)
	{
		if(V[i][j] == V[i-1][j])
			x[i-1] = 1;
		
		else
		{
			x[i] = 1;

			//cout << "weight "<<V[i][j] - p[i] << endl; 
			for (int k = 0; k < m; ++k)
			{
				if(V[i-1][k] == V[i][j] - p[i])
				{
					j = k;
					break;
				}
			}
		}
		i--;

	}

	cout<<"\nFollowing weights are included: \n";
	cout<<"Weight\tProfit";

	for (i = 1; i < n; ++i)
	{
		if(x[i] == 1)
		cout <<"\n" << w[i] <<"\t"<< p[i];
	}
	
	cout << "\nMax profit is : "<< V[n-1][m-1] << endl;


}

int main()
{	
	// int n = 4, m =8;
	// int p[] = {0, 1, 2, 3, 6};
	// int w[] = {0, 2, 3, 4, 5};

	int n = 3, m = 50;
	int p[] = {0,60, 100, 120};
    int w[] = {0,10, 20, 30};

	knapsack(m+1, n+1, p, w);
	return 0;
}