#include<bits/stdc++.h>
using namespace std;

bool f[200020];
int a[107];
int main(){
	int i,j,n,sum=0,ans=100,k,tem;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),sum+=a[i];
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(j=sum;j>=a[i];j--)f[j]|=f[j-a[i]];
	}
	if((sum%2==1) || f[sum/2]==0)
	{printf("0");return 0;}
	for(i=1;i<=n;++i)
	{
		tem=0;
		for(j=30;j>=0;j--)
		if(a[i]%(1<<j)==0){
			tem=j;
			break;
		}
		if(tem<ans){
			ans=tem;
			k=i;
		}
	}
	printf("1\n%d\n",k);
	return 0;
}
