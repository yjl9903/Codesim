#include <iostream>
using namespace std;

int main()
{
	int t,a[2000]={0};
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		int h=0;
		while(1)
		{
			if(a[h]%2!=0)
			{
				cout<<a[h]<<" ";
			}
			h++;
			if(h==n)break;
		}
		h=0;
		while(1)
		{
			if(a[h]%2==0)
			{
				cout<<a[h]<<" ";
			}
			h++;
			if(h==n)break;
		}
		cout<<endl;
	}
 } 
