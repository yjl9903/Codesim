#include<iostream>
#include<string>
using namespace std;
string a;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int T=0,M=0;
		cin>>a;
			int TN=0,MN=0;
			int flag=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]=='T')
		    	TN++;
		    	if(a[i]=='M')
			    MN++;
			    if(TN<=0||TN<MN)
			    {
			    	flag=1;
			    	break;
				}
			}
			TN=0,MN=0;
			for(int i=n-1;i>=0;i--)
			{
				if(a[i]=='T')
		    	TN++;
		    	if(a[i]=='M')
			    MN++;
			    if(TN<=0||TN<MN)
			    {
			    	flag=1;
			    	break;
				}
			}
			if(flag||TN!=MN*2)
			cout<<"NO"<<endl;
			else
			cout<<"YES"<<endl;
	
	}
	return 0;
}
