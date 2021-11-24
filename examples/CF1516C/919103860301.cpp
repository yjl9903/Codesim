#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 105
int n,sum,num[N];
bool flag[200005];
int main()
{
	sum=0;
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>num[i];
		sum+=num[i];
	}
	if(sum%2!=0)
	{
		cout<<"0";
		return 0;
	}
	else
	{
		sum/=2;
		flag[0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=sum;j>=num[i];j--)
			{
				flag[j]|=flag[j-num[i]];
			}
		}
		if(!flag[sum])
		{
			cout<<"0";
			return 0;
		}
		int tempt1=100000,tempt2=0;
		for(i=1;i<=n;i++)
		{
			int tempt=num[i];
			int a=0;
			while(tempt%2==0)
			{
				tempt/=2;
				a++;
			}
			if(a<tempt1)
			{
				tempt1=a;
				tempt2=i;
			}
		}
		cout<<"1"<<endl<<tempt2;
	}
}
