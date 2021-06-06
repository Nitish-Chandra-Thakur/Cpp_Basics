#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int findsmallest(int arr[], int size, int i)
{
	sort(arr, arr+size);
	return arr[i];
	
}

int queryOne(int arr[], int size, int l, int r)
{
	int sum=0;
	for(int i=l-1; i<r; i++)
	{ 
		sum += arr[i];
	}

	return sum;
}

int queryTwo(int arr[], int size, int l, int r)
{
	int sum = 0;
	for(int i=l-1; i<r; i++)
	{
		sum += findsmallest(arr, size, i);
	}

	return sum;
}
int main()
{
	int size,m;
	cin>>size;
    int arr[size];
	cout<<endl;

	for(int i=0; i<size; i++)
	{
		cin>>arr[i] ;
	}	
	cout<<endl;
    cin>>m;
	cout<<endl;
	int type[m],l[m],r[m];
    for(int j=0; j<m; j++)
    {
		cin>>type[j] ;
		cin>>l[j] ;
		cin>>r[j];
		cout<<endl;
	}

	for(int k=0; k<m; k++)
	{
	    if(type[k] == 1)
        {
            cout<<queryOne(arr, size, l[k], r[k]);
            cout<<endl;
        }
	    	
	    else
	    {
            cout<<queryTwo(arr, size, l[k], r[k]);
            cout<<endl;
        }
	}

	return 0;
}