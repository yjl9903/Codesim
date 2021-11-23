#include <bits/stdc++.h>
using namespace std;
int main ()
{
	string a;
	cin>>a;
	string s[90];
	for(int i=0;i<4;i++)
	{
		s[1]+=a[i];
	}
	for(int i=5;i<9;i++)
	{
		s[2]+=a[i];
	}
	for(int i=10;i<14;i++)
	{
		s[3]+=a[i];
	}
	for(int i=15;i<19;i++)
	{
		s[4]+=a[i];
	}	
	for(int i=20;i<24;i++)
	{
		s[5]+=a[i];
	}	
	for(int i=25;i<29;i++)
	{
		s[6]+=a[i];
	}	
	for(int i=30;i<34;i++)
	{
		s[7]+=a[i];
	}		
	for(int i=35;i<39;i++)
	{
		s[8]+=a[i];
	}	
	int order=0,sum=0,max=0;
	for(int i=1;i<9;i++)
	{
		if(s[i]=="0000")
		{
			sum++;
			if(max<sum) 
			{
				max=sum;
				order=i;
			}		
		}
		else sum=0;
	}
	order=order-max+1;
	for(int i=1;i<9;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(s[i][0]=='0'&&s[i]!="0000")
			{
				int k;
				for(k=1;k<4;k++)
				if(s[i][k]!='0') break;
				s[i].erase(0,k);
				break;
			}
		}
	}
	for(int i=1;i<9;i++)
	{
     	if(s[i]=="0000")
	    s[i]="0";
    }
	if(max>0)
	{
		for(int i=1;i<order-1;i++)
		{
			cout<<s[i];
			cout<<":";
		}
	    cout<<s[order-1];
		cout<<"::";
		for(int i=order+max;i<8;i++)
		{
			cout<<s[i];
			cout<<":";
		}
	    if(order+max>8) return 0;
	    else cout<<s[8];
	}
	else
	{
		for(int i=1;i<8;i++)
		{
		
			cout<<s[i];
			cout<<":";
        }
       cout<<s[8];
	}
	return 0;
}
