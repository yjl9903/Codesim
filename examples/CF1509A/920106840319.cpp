#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		bool b[n];
		memset(b,0,sizeof(b));
		for(int i=0;i<=n-1;i++)
		{
			cin>>a[i];
			if(a[i]%2)
				b[i]=1;			//1表示奇数 0表示偶数 
		}
		for(int i=0;i<=n-1;i++)			//输出所有奇数 
			if(b[i])
				cout<<a[i]<<' ';
		for(int i=0;i<=n-1;i++)			//输出所有偶数 
			if(!b[i])
				cout<<a[i]<<' ';
		cout<<endl; 
	}
	
	return 0;
}
