#include <iostream>
using namespace std;

int main()
{
	int tmp;
	cin>>tmp;
	for(int i=0;i<tmp;i++)
	{
		int n,sum1=0,sum2=0,h=1;
		string s;
		cin>>n>>s;
		for(int j=0;j<n;j++)
		{
			if(s[j]=='T')sum1++;
			if(s[j]=='M')sum2++;
			if(sum1<sum2)h=0;
		}
		sum1=0,sum2=0;
		for(int j=n-1;j>=0;j--)
		{
			if(s[j]=='T')sum1++;
			if(s[j]=='M')sum2++;
			if(sum1<sum2)h=0;
		}
		if(sum1!=2*sum2)h=0;
		if(h==0)cout<<"NO"<<endl;
		if(h==1)cout<<"YES"<<endl;
	}
 } 
