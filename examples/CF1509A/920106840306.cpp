#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int t,n;
	int a[2000];
	int b[2000];
	int c[2000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int d=0;
		int e=0;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		for(int m=0;m<n;m++)
		{
			if(a[m]%2!=0)
			{
				b[d]=a[m];
				d=d+1;
			}
			if(a[m]%2==0)
			{
				c[e]=a[m];
				e=e+1;
			}
		}
		for(int k=0;k<d;k++)
		{
			cout<<b[k]<<' ';
		}
		if(d==n)				//如果全为奇数，输出换行，进行下一次循环 
		{
			cout<<endl; 
			continue; 
		}
		for(int g=0;g<e;g++)
		{
			if(g!=(e-1))
			{
				cout<<c[g]<<' ';
			}
			else
			{
				cout<<c[g]<<endl;
			}
		}
		
	}
	return 0;
}
