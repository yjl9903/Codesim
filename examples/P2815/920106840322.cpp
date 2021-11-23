#include <bits/stdc++.h>
using namespace std;

int main() 
{
	char a[39],b[32];
	for(int i=0;i<39;i++)
	{
		cin>>a[i];
	}
	int j=0;
	for(int i=0;i<39;i++)
	{
		if(a[i]!=':')
		{
			b[j]=a[i];
			j++;
		}
	}
	int sum[8]={0};
	j=0;
	for(int i=0;i<39;i++)
	{
		if(a[i]==':')
		{
			for(int f=4;f>0;f--)
			{
				if(a[i-f]=='0')sum[j]++;
				else break;
			}
			j++;
		}
		if(i==34)
		{
			for(int f=1;f<=4;f++)
			{
				if(a[i+f]=='0')sum[j]++;
				else break;
			}
		}
	}
	int tmp[8]={0};
	for(int i=0;i<8;i++)
	{
		if(sum[i]==4)
		{
			for(int f=i;f<8;f++)
			{
				if(sum[f]==4)tmp[i]++;
				else break;
			}
		}
	}
	int h,d=tmp[0];
	for(int i=0;i<8;i++)
	{
		if(tmp[i]>d)
		{
			h=i;
			d=tmp[i];
		}
	}
	for(int i=0;i<8;i++)
	{
		if(sum[i]!=4)
		{
			for(int f=0+sum[i];f<4;f++)
			{
				cout<<b[i*4+f];
			}
			if(i!=7&&i!=h-1)cout<<":";
		}
		if(sum[i]==4)
		{
			if(i>=h&&i<=(h+d-1))
			{
				cout<<"::";
				i=i+d-1;
			}
			else
			{
				cout<<"0";
				if(i!=7&&i!=h-1)cout<<":";
			}
		}
	}
    return 0;
} 
