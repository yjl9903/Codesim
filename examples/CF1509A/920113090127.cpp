#include<iostream>
using namespace std;

int main()
{   int t,n,numberT,numberM,a=1;
	cin>>t;
	while(t--)
	{   char s[2005]={};
		cin>>n;
		for(int i=0;i<n;i++)
		    {cin>>s[i];}
		for(int i=0;i<n;++i)
		{
			if(s[i]=='T')
			    {numberT++;}
			if(s[i]=='M')
			    {numberM++;}
			if(numberT<numberM)
			    {a=0;break;}
		}
		numberT=0,numberM=0;
		for(int i=(n-1);i>=0;--i){
			if(s[i]=='T')
			    {numberT++;}
			if(s[i]=='M')
		        {numberM++;}
			if(numberT<numberM)
			    {a=0;break;}
		}
		if(f==0||numberT!=numberM*2)
		        {cout<<"No";}
		else 
		        {cout<<"Yes";}
	    numberT=0,numberM=0,a=1;
	}
	
	return 0;
}