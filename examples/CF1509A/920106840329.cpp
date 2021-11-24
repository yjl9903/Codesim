#include<iostream>
using namespace std;
int a[2005];
int b[2005];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i];
		int tmp=0;
		int j=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]%2==1)
			{
				cout<<a[i]<<" ";
			}
			else
			{
				b[j]=a[i];
				j++;
			}
		}
		for(int i=0;i<j;i++)
		cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}
