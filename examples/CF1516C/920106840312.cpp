#include <bits/stdc++.h>
using namespace std;
bool f[200010];
int a[110];
int n,m;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	cin>>a[i],m+=a[i];
	f[0]=1;
	for(int i=1;i<=n;++i)
	for(int j=m;j>=a[i];--j)
	f[j]|=f[j-a[i]];
	if((m & 1) || !f[m>>1])
	{cout<<"0"<<endl;return 0;}
	int ans=60,pos;
	for(int i=1;i<=n;++i)
	{
		int tmp=0;
		for(int j=30;j>=0;--j)
		if(a[i]%(1<<j)==0)
		{
			tmp=j;
			break;
		}
		if(tmp<ans)
			ans=tmp,pos=i;
	}
    cout<<"1"<<endl;
    cout<<pos<<endl;
	return 0;
}
