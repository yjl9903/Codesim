#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int a;
	cin>>a;
	int * *array=new int *[a];
	for(int i=0;i<a;i++)
	{
		int b;
		cin>>b;
		array[i]=new int[b+1];
		memset(array[i],0,b+1);
		array[i][0]=b;
		for(int j=1;j<=b;j++)
			cin>>array[i][j];
	}
	for(int i=0;i<a;i++)
	{
		for(int j=1;j<=array[i][0];j++)
		{
			if(array[i][j]%2!=0)
			cout<<array[i][j]<<" ";
		}
		for(int j=1;j<=array[i][0];j++)
		{
			if(array[i][j]%2==0)
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<a;i++)
		delete array[i];
	delete array;
	return 0;
}
