#include<iostream>

using namespace std;

// void PP(int **s, int i, int j)
// {

// 	static int l = 1;
// //	if(i == 0 || j == 0 )
// //		return;

// 	//cout<<i<<" "<<j<<endl;

// 	if(l > 4)
// 		return;

// 	if( i == j )
// 	{
// 		cout<<" A"<<l++;
// 		return;
// 	}

// 	else if(i == j-1)
// 	{
// 		cout<<"A"<<l<<" A"<<l+1<<")";
// 		l += 2;
// 		return;
// 	}

// 	else
// 	{
// 		cout<<"(";
// 		PP(s, i, s[i][j]);
// 		PP(s, s[i][j] + 1, j--);
// 		cout<<")";
// 	}
// }

void PP(int **S,int i,int j)
{  
	
	if (i == j)
    {
        cout<<"A"<<i<<" ";
        return;
    }
    
    else
    {
    	cout<<"(";

    	PP(S,i, S[i][j]);

    	PP(S,S[i][j]+1, j);

    	cout<<")";
    }
}

void minmatrix(int **m, int *p, int n, int **s)
{


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			s[i][j] = 0;
		}
	}


//---------------Discarding half of the matrix as backward operations are not possilble
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(j < i)
				m[i][j] = -1;
			
			else if( i == j)
				m[i][j] = 0;
			
			else if(j == i+1)
			{
				m[i][j] = p[i-1]*p[i]*p[j]; 
				s[i][j] = i;
			}

		}




//-------------------Prints the indices of diagonal matrix-----------------
	// for (int i = 1; i < n; ++i)
	// {
	// 	int k = 1;
	// 	for (int j = i+1; j <= n; ++j)
	// 	{
	// 		cout<<k<<j<<"\t";
	// 		k++;
	// 	}
	// 	cout<<endl;
	// }

	// cout<<endl;


//---------------Compute m[][] matrix----------------------------
	for (int i = 1; i < n; ++i)
	{
		int l = 1;
		for (int j = i+2; j <= n; ++j)
		{
			int	min = 30000;
			for (int k = l; k < j; ++k)
			{
				if(min > (m[l][k] + m[k+1][j] + (p[l-1]*p[k]*p[j]) ))
				{
					min = m[l][k] + m[k+1][j] + (p[l-1]*p[k]*p[j]);
					s[l][j] = k;
				}
			}

			m[l][j] = min;
			l++;
		}
	}
	cout<<"\n";

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout<<s[i][j]<<"\t";
		
		cout<<endl;
	}
	
	cout<<"\n\n";

	for (int i = 1; i <= n; ++i)
	{
		cout<<i<<". ";
		for (int j = 1; j <= n; ++j)
			cout<<m[i][j]<<"\t";
		
		cout<<endl;
	}

	cout<<"\nMinimum number of operations can be achieved by: ";
	PP(s, 1, n);
}



int main()
{
	int n;
	//cin>>n;
	n = 5;
	int *p;

	p = new int [n+1];
	
	int d[] = { 5, 10, 4, 3, 5, 10};
	//{40, 20, 30, 10, 30};//;//{4, 10, 3, 12, 20, 7 };

	for (int i = 0; i <= n; ++i)
		p[i] = d[i];

	int **m, **s;

	m = new int* [n+1];
	s = new int* [n+1];

	for (int i = 0; i <= n; ++i)
	{
		m[i] = new int [n+1];
		s[i] = new int [n+1]; 
	}

	minmatrix(m, p, n, s);
	cout<<"\nMinimum number of operations to multiply these arrays is "<<m[1][n]<<endl;
} 