#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int Maxn=110;
const int Maxm=200010;
bool f[Maxm];
int a[Maxn];
int n,m;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i),m+=a[i];
	f[0]=1;
	for(int i=1;i<=n;++i)
	for(int j=m;j>=a[i];--j)
	f[j]|=f[j-a[i]];
	if((m & 1) || !f[m>>1])
	{puts("0");return 0;}
	int ans=60,pos;
	for(int i=1;i<=n;++i)
	{
		int tmp=0;
		for(int j=30;j>=0;--j)
		if(a[i]%(1<<j)==0){tmp=j;break;}
		if(tmp<ans)ans=tmp,pos=i;
	}
	printf("1\n%d\n",pos);
	return 0;
}
