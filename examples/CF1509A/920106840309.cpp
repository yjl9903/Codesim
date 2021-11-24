#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,a[2000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int w=0;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			if(x&1)
			{
				cout<<x;
				if(j!=n-1||w)cout<<' ';
			}
			else a[w++]=x;
		}
		for(int j=0;j<w;j++)
		if(j!=w-1)cout<<a[j]<<' ';
		else cout<<a[j];
		cout<<endl;
	} 
	return 0;
}
