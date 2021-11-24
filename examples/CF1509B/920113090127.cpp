#include<iostream>
using namespace std;
int main(){
	
	int t,n,numberT=0,numberM=0,a=1;
	cin>>t;
	char s[2005]={};
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)
		      {cin>>s[i];}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='T')
			    {numberT++;}
			if(s[i]=='M')
			    {numberM++;}
			if(numberT<numberM)
			    {a=0;break;}
		}
		numberT=0,numberM=0;

		for(int i=(n-1);i>=0;i--){
			if(s[i]=='T')
			    {numberT++;}
			if(s[i]=='M')
			    {numberM++;}
			if(numberT<numberM)
			    {a=0;break;}
		}
		if(a==0||numberT!=numberM*2)
		    {cout<<"NO"<<endl;}
		else 
		    {cout<<"YES"<<endl;}
	    numberT=0,numberM=0,a=1;
	}
	system("pause");
	return 0;
}