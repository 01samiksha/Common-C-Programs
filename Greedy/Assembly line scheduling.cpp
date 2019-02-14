#include<iostream>
#include<cmath>

using namespace std;
const int n = 4+1;

int min(int x, int y, int l[2][n], int i, int j)
{
	if(x < y)
	{
		l[j][i] = j;
		cout<<i<<" if j"<<j<<" ";
		return x;
	}
	else
	{
		l[j][i] = abs(j-1);
		cout<<i<<" else j"<<abs(j-1)<<" ";
		return y;
	}
}

int assemblyLineScheduling(int a[2][n], int t[2][n], int f[2][n+1], int e[2], int x[2], int l[2][n])
{

	int i, index;
	for (i = 0; i < 2; ++i)
	{
		f[i][0] = e[i] + a[i][0];
	}


	for (i = 1; i < n; ++i)
	{
		f[0][i] = min( (f[0][i-1] + a[0][i]), (f[1][i-1] + a[0][i] + t[1][i]), l, i, 0 );

		cout<<endl<<i<<" "<<f[0][i]<<" "<<l[0][i]<<endl;

		f[1][i] = min( (f[1][i-1] + a[1][i]), (f[0][i-1] + a[1][i] + t[0][i]), l, i, 1 );
		cout<<endl<<f[1][i]<<" "<<l[1][i]<<endl;
	}

   cout<<endl<<f[0][i-1]<<" "<<x[0]<<" "<<f[1][i-1]<<" "<<x[1];
	f[0][i] = f[0][i-1] + x[0];
	f[1][i] = f[1][i-1] + x[1];

	if(f[0][i] > f[1][i])
		index = 1;
	else
		index = 0;

	cout<<"Minimum cost is "<<f[index][i];
	//cout<<" "<<f[0][4]<<" "<<f[1][4];

	i = n-1;
	cout<<endl<<"Reverse path is: a"<<index<<i<<" ";

	while(i>0)
	{
		cout<<"a"<<l[index][i]<<i-1<<" ";

		index = l[index][i-1];
		
		i--;
	}
}

int main()
{
	// int a[2][n] = {{4, 5, 3, 2},
 //                {2, 10, 1, 4}};
 //    int t[2][n] = {{0, 7, 4, 5},
 //                {0, 9, 2, 8}};
 //    int e[] = {10, 12}, x[] = {18, 7};

	int a[2][n] = {{ 5, 3, 10, 11, 6},
                {7, 6, 5, 6, 12}};
    int t[2][n] = {{0, 1, 9, 2, 3},
                {0, 2, 8, 3, 9}};
    int e[] = {3, 2}, x[] = {1, 3};
	
	int f[2][n+1], l[2][n];

	assemblyLineScheduling(a, t, f, e, x, l);
}