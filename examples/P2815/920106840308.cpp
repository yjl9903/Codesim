#include <bits/stdc++.h>
using namespace std;
int main()
{
	int max=0,t;
	string a,b[8];
	cin>>a;
	for(int i=0;i<8;i++)
	{
		int j=0;
		while(a[i*5+j]=='0')
		j++;
		if(j==4)
		b[i]="0";
		else
		for(j;j<4;j++)
		b[i]+=a[i*5+j];
	}
	for(int i=0;i<8;i++)
	{
		if(b[i]=="0")
		{
			int j=0;
			while(i+j<7&&b[i+j+1]=="0")
			j++;
			if(j>max)
			{
				max=j;
				t=i;
			}
			i+=j;
		}
	}
	for(int i=0;i<8;i++)
	{
		if(i==t&&max!=0)
		{
			cout<<"::";
			i+=max;
		}
		else
		{
			cout<<b[i];
			if(i!=7&&i!=t-1)
			cout<<":";
		}
	}
}
