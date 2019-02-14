#include<iostream>
using namespace std;

const int n = 11, k = 5;

struct stages
{
	int no;
	int a[10];
};

void multistage(int c[n][n], stages s[k])
{
	int cost[k][n], min, j, l, m, d[k][n];

	
//--------------------VALUES OF COST  = 0 initially
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cost[i][j] = 0;
		}

	}


//-----------------VALUES of d matrix = -1 initially
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			d[i][j] = -1;
		}

	}


	cost[4][8] = 2;
	cost[4][9] = 2; 



	j = 8;
	for (int i = k-2; i >= 0; i--)
		for(int z = 0; z < s[i].no; z++)
		{

			j = s[i].a[z];
			min = 1000;
			for (int m = 0; m < s[i+1].no; ++m)
			{
				l = s[i+1].a[m];
				
				if(c[j][l] > 0)
				{

					if( (c[j][l] + cost[i+1][l]) < min)
						{
							min = c[j][l] + cost[i+1][l];
							d[i][j] = l;
 							cost[i][j] = min;
						}
				}
			}
		}

	cout<<endl;

// 	cout<<"\n\nCOST MATRIX\n";
// //------------------------PRINTING COST MATRIX---------------
// 	for (int i = 0; i < k; ++i)
// 	{
// 		cout<<i<<". ";
// 		for (j = 0; j < n; ++j)
// 		{
// 			cout<<cost[i][j]<<"\t";
// 		}

// 		cout<<endl;
// 	}


// 	cout<<"\n\nDISTANCE MATRIX\n";

// //-------------------PRINTING DISTANCE MATRIX-----------------
// 	for (int i = 0; i < k; ++i)
// 	{
// 		for (j = 0; j < n; ++j)
// 		{
// 			if(d[i][j] != -1)
// 			cout<<i<<","<<j<<"\t"<<d[i][j]<<"\t\n";
// 		}

// 	}


	j = 0;

	cout<<"\nMinimum distance from source to destination is "<<cost[0][0];
	cout<<"\n\nThe minimimum path from source to destination is: ";
	

	//---------------PRINT THE PATH---------------------------
	for (int i = 0; i < k; ++i)
	{
		cout<<"v"<<j<<" ";
		j = d[i][j];
	}

}



int main()
{					//  0,1, 2,3,4, 5,6,7, 8,9,10
	int c[n][n] = { {   0,4, 5,3,2, 0,0,0, 0,0,0 },
					  { 0,0, 0,0,0, 4,0,0, 0,0,0 },
					  { 0,0, 0,0,0, 5,6,4, 0,0,0 },
					  { 0,0, 0,0,0, 0,3,6, 0,0,0 },
					  { 0,0, 0,0,0, 0,0,1, 0,0,0 },
					  { 0,0, 0,0,0, 0,0,0, 7,0,0 },
					  { 0,0, 0,0,0, 0,0,0, 8,9,0 },
					  { 0,0, 0,0,0, 0,0,0, 0,10,0},
					  { 0,0, 0,0,0, 0,0,0, 0,0,2 },
					  { 0,0, 0,0,0, 0,0,0, 0,0,2 },
					  { 0,0, 0,0,0, 0,0,0, 0,0,0 } };

	//int k = 5;
	stages s[k] = { {1, {0}          },
					{4, {1, 2, 3, 4} },
					{3, {5, 6, 7}    },
					{2, {8, 9}      },
					{1,  {10} }
				  };



   cout<<"THE GRAPH WITH STAGE AND VERTICES IS \n";
   
   // for (int i = 0; i < k; ++i)
   // {
   // 	int j = 0;
   // 	 while(s[i].a[j] != -1)
   // 	 	j++;

   // 	 s[i].no = j;
   // }


   for (int i = 0; i < k; ++i)
   {
   	cout<<endl<<i<<". "<<s[i].no<<" - ";

   	for (int j = 0; j < s[i].no; ++j)
   	{
   		cout<<s[i].a[j]<<" ";
   	}
   }

	multistage(c, s); 
	cout <<"\n";
}