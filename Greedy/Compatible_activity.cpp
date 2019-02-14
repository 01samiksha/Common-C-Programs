#include <iostream>

using namespace std;

struct activity
{
	int start;
	int end;
	char no;
};

void swap(activity &a, activity &b)
{
	activity t;
	t = a;
	a = b;
	b = t;
}

int sortEnd(activity A[], int n)
{
		for(int i=0; i<n; i++)
		for(int j=0; j<n-1-i; j++)
			if(( A[j].end) > ( A[j+1].end))
				swap(A[j],A[j+1]);
}

void Compatible(activity A[], int n)
{	
	int count=1, j=0;
	sortEnd(A,n);

	for(int i=1; i<n; i++)
	{
		cout<<"\nEnd "<<A[j].start<<"-"<<A[j].end<<"	Start "<<A[i].start;
		if(A[j].end <= A[i].start)
		{	
			//cout<<"if";
			cout<<"\tActivity "<<A[j].no<<" is compatible with "<<A[i].no;
			j = i;
			count++;
		}
	}

	cout<<"\nMaximum compatible activities are "<<count<<endl;
}

int main()
{
	//activity A[] = {{1,2,'a'}, {5,7,'b'}, {0,6,'c'}, {5,9,'d'}, {3,4,'e'}, {8,9,'f'}};
	activity A[] = {{10,20,'a'}, {12,15,'b'}, {20,30,'c'}};

	Compatible(A,3);

}