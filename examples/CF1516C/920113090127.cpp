#include<iostream>
#include<cstdio>
using namespace std;

int main()
{   int a[105];
    bool f[200005];
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	    {scanf("%d",&a[i]),sum=sum+a[i];}
	if(sum&1)
	{
		cout<<"0"<<endl;		
	    system("pause");
		return 0;
	}
	sum/=2;
	f[0]=1;
	for(int i=1;i<=n;i++)
		{for(int j=sum;j>=a[i];j--)
		     {f[j]|=f[j-a[i]];}
	    }
	if(!f[sum])
	{
		cout<<"0";		
		return 0;
	}
	int minc=100000,minp=0;
	for(int i=1;i<=n;i++)
	{
		int x=a[i],e=0;
		while(!(x&1))
		{
			x>>=1;
			e++;
		}
		if(e<minc) 
		  {minc=e,minp=i;}
	}
	printf("1\n%d",minp);
	cout<<endl;
	system("pause");
	return 0;
}