#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][2021],b[n][2021];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2021;j++)
		{
			a[i][j]=-1;
			b[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		int j;
		cin>>j;
		for(int t=0;t<j;t++)
		{
			cin>>a[i][t];
		}
	}
	for(int i=0;i<n;i++)
	{
		int t=0;
		for(int j=0;a[i][j]!=-1;j++)
		{
			if(a[i][j]%2!=0)
			{
				b[i][t]=a[i][j];
				t++;
			}
		}
		for(int j=0;a[i][j]!=-1;j++)
		{
			if(a[i][j]%2==0)
			{
				b[i][t]=a[i][j];
				t++;
			}
		}
	}
	for(int i=0;i<n-1;i++)
	{
		int j; 
		for(j=0;b[i][j+1]!=-1;j++)
		cout<<b[i][j]<<" ";
		cout<<b[i][j];
		cout<<endl;
	}
	int j;
	for(j=0;b[n-1][j+1]!=-1;j++)
	cout<<b[n-1][j]<<" ";
	cout<<b[n-1][j];
	return 0;
}
