#include<iostream>
#include<algorithm> 
#include<string.h>
using namespace std;

int main()
{
	int n,sum=0,flag=0;
	cin>>n;
	int a[n];
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
		sum+=a[i]; 
	}
	if(sum%2)			 //数组之和为奇数：不需要减 
	{
		cout<<0<<endl;
		return 0;
	}
	else				 //数组之和为偶数：先对原数组判断
	{
		bool b[sum];
		memset(b,0,sizeof(b));
		b[0]=1;
		for(int i=0;i<=n-1;i++)
			for(int j=sum/2;j>=a[i];j--)
				b[j]|=b[j-a[i]];
		if(!b[sum/2])
		{
			cout<<0<<endl;
			return 0;
		}
	}
	while(1)		//数组之和为偶数：不断除以2直到出现奇数 
	{ 
		for(int i=0;i<=n-1;i++)
		{
			if(a[i]%2)
			{
				flag=1;			//出现奇数flag置1
				cout<<1<<endl<<i+1<<endl; 
				break;
			}	
		}
		if(flag==1)
			break;
		for(int i=0;i<=n-1;i++)
		{
			a[i]/=2;
		}
	}
	
	return 0;
}
