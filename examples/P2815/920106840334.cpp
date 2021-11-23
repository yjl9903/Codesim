#include<cstring>
#include<iostream>
using namespace std;
int maxx=0,maxi;
string str,s[8];
int main()
{
	cin>>str;
	for(int i=0;i<8;i++)
	{
		int j=0;
		while(str[i*5+j]=='0')
		{
			j++;
		}
		if(j==4)
		{
			s[i]="0";
		}
		else
		{
			for(j;j<4;j++)
			{
				s[i]+=str[i*5+j];
			}
		}
	}
	for(int i=0;i<8;i++)
	{
		if(s[i]=="0")
		{
			
			int j=0;
			while(i+j<7&&s[i+j+1]=="0")
			{
				j++;
			}
			if(j>maxx)
			{
				maxx=j;
				maxi=i;
			}
			i+=j;
		}
	}
		for(int i=0;i<8;i++)
	{
		if(i==maxi&&maxx)
		{
			cout<<"::";
			i+=maxx;
		}
		else
		{
			cout<<s[i];
			if(i!=7&&i!=maxi-1)
			{
				cout<<":";
			}
		}
	}
}
