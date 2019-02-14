#include<iostream>

using namespace std;

struct knap
{
	int p;
	int w;
	int item;
	float x;
};

void swap(knap &a, knap &b)
{
	knap t;
	t = a;
	a = b;
	b = t;
}

void SortPW(knap k[],int n)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n-1-i; j++)
			if(( k[j].p/k[j].w ) < ( k[j+1].p/k[j+1].w ))
				swap(k[j],k[j+1]);
	
}

int knapSack(knap k[], int n, int M)
{   
	//cout<<"Sorting about to start";
	SortPW(k,n);
	//cout<<"Sorting done";

	int x[n] = {0}, profit = 0, i = 0;

	while(k[i].w <= M)
	{
		k[i].x = 1;
		M = M-k[i].w;
	
	//	cout<<endl<<k[i].item<<" M "<<M<<"	w "<<k[i].w<<"	p "<<k[i].p;
			i++;
	}

	k[i].x = float(M)/float(k[i].w);
	//cout<<float(3)/float(8);
	// cout<<"\nX = "<<k[i].x<<"	M "<<M<<"	W "<<k[i].w;

	for(int i=0; i<n; i++)
		profit += k[i].p * k[i].x;

	return profit;
}

int main()
{
	//cout<<"Yahha";
	knap k[5] = {{ 10, 3, 1, 0}, {20, 5, 2, 0}, {15, 4, 3, 0}, {8, 8, 4,0}, {25, 5, 5, 0}};
	//cout<<"Idhr shi";

	//cout<<"Enter values ";
	cout<<"Maximun profit is "<<knapSack(k,5,20)<<endl;
}
