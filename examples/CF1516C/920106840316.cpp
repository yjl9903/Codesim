#include <bits/stdc++.h>
using namespace std;
int main ()
{
	bool f[200021];
	int n,s=0,p=0;
	cin>>n;
	int a[n+1],c[n+1];
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		s+=temp;
		if(temp%2==1)
		p=1;
		a[i]=temp;
	}
	if(s%2==1)
	{
	   cout<<0;
	   return 0;
    }
	s/=2;
	f[0]=1;
    for(int i=1;i<=n;i++)
		for(int j=s;j>=a[i];j--)
			f[j]|=f[j-a[i]];
	if(!f[s])
	{
		cout<<0;
		return 0;
	}
	cout<<1<<endl; 
	if(p==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2==1)
			{
				cout<<i;
				break;
			}
		}
	}
	else
	{
       	while(1)
       	{
       		for(int i=1;i<=n;i++)
       		{
       			a[i]/=2;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]%2==1)
				{
					cout<<i;
					return 0;
				}
			}
		}
    }
	return 0;
}
