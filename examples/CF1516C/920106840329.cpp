#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string.h>
using namespace std;
int a[105];
bool f[200010];
int main()
{
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	f[0]=1;
	for(int i=1;i<=n;++i)
	for(int j=sum;j>=a[i];--j)
	f[j]|=f[j-a[i]];
	if(!f[sum>>1])
	cout<<0<<endl;
	else
	while(1)
	{
		if(sum&1)
		{
			cout<<0<<endl;
			break;
		}
		else
		{
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]&1)
				{
					flag=i;
					break;
				}
				else
				a[i]>>=1;
			}
			sum/=2;
			if(flag)
			{
				cout<<1<<endl;
				cout<<flag<<endl;
				break;
			}
		}
	}
	return 0;
}
