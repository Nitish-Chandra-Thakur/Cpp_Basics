#include<bits/stdc++.h>
using namespace std;

bool elePresent(int m, int n)
{
	int ele;
	int mat[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j] ;
		}
	}
	cin>>ele;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mat[i][j] == ele)
			{
				return true;
			}
		}
	}
	return false;
}

int main() 
{
	int m,n,ele;
	cin>>m >>n;
	cout<<elePresent(m,n);
	return 0;
}