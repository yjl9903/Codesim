#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[1005],ans=0;
	bool b[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	if(ans&1)cout<<0<<endl;
	else
	{
		ans/=2;
		b[0]=1;
		for(int i=1;i<=n;i++)
		for(int j=ans;j>=a[i];j--)
		b[j]|=b[j-a[i]];
		if(b[ans]==0)cout<<0<<endl;
		else
		{
			cout<<1<<endl;
			bool p=1;
			while(p)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i]&1)
					{
						p=0;
						cout<<i<<endl;
						break;
					}
					a[i]>>=1;
				}
			}
		}
	}
	return 0;
}
