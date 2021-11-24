#include<iostream>
using namespace std;

int main()
{
	int t,n;
	char s[200000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<=n-1;i++)
			cin>>s[i];
		bool flag=1;
		int sumT=0,sumM=0;
		for(int i=0;i<=n-1;i++)
		{
			if(s[i]=='T')
				sumT++;
			if(s[i]=='M')
				sumM++;
			if(sumT<sumM)
			{
				cout<<"NO"<<endl;
				flag=0;
				break;
			}
		}
		if(flag==0)
			continue;
		flag=1;
		sumT=0;
		sumM=0;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='T')
				sumT++;
			if(s[i]=='M')
				sumM++;
			if(sumT<sumM)
			{
				cout<<"NO"<<endl;
				flag=0;
				break;
			}
		}
		if(flag==0)
			continue;
		if(sumT==2*sumM)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
}
