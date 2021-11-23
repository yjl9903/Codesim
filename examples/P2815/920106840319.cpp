#include<iostream>
using namespace std;

int main()
{
	char ch[50];
	bool b[8]={0};
	cin>>ch;
	int sum = 0,begin,end,lianxu=0,beginmax,endmax,lianxumax=0;
	for(int i=0;i<=38;i++)
	{
		if(ch[i]!='0'&&ch[i]!=':')
			break;
		else if(i == 38)
		{
			cout<<"::";
			return 0;
		}
	}
	
	for(int i=0;i<=35;i+=5)
	{
		if(ch[i]=='0'&&ch[i+1]=='0'&&ch[i+2]=='0'&&ch[i+3]=='0')
		{
			sum++;
			b[i/5]=1;
		}
	}
	
	for(int i=0;i<=6;i++)
	{
		begin=-1;
		if(b[i]==1)
		{
			begin=i;
			for(int j=i+1;j<=7;j++)
			{
				if(b[j]==0)
				{
					end=j-1;
					break;
				}
				else if(j==7)
					end=7;
			}
		}
		else if(i==6&&b[7]==1)
		{
			begin=7;
			end=7;	
		}
		if(begin!=-1)
		{
			lianxu=end-begin+1;
		}
		if(lianxu>lianxumax)
		{
			lianxumax=lianxu;
			beginmax=begin;
			endmax=end;
		}
	}
	
	if(sum==0)
		for(int i=0;i<=38;i++)
			cout<<ch[i];
	else
		for(int i=0;i<=38;i+=5)
		{
			if(i==beginmax*5)
			{
				beginmax==0?cout<<"::":cout<<':';
				i=(endmax+1)*5-5;
			}
			else
			{
				if(b[i/5]==1)
					(i/5==7)?cout<<'0':cout<<"0:";
				else
				{
					int j;
					for(j=i;j<=i+3;j++)
					{
						if(ch[j]!='0')
							break;
					}
					while(j<=i+4)
					{
						cout<<ch[j];
						j++;
					}
				}
			}	
		}
	
	
	return 0;
}
