#include <bits/stdc++.h>
using namespace std;
int n,sum,ans;
int a[2100]={0};
int dp[200000];
int main()
{
	cin>>n;
	int f=1;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=a[i];j--)
		{
			dp[j]=dp[j-a[i]];
		}
	}
	if(!dp[sum/2])
	{
		cout<<"0"<<endl;
		return 0;
	}
while(f==1){
        if(sum%2==1) {
	       cout<<"0";
	       return 0;
         }
         sum=0;
	for(int i=1;i<=n;i++)
		{
			if(a[i]%2==1) {
				ans=i;
				f=0;
				break;
			}
			a[i]=a[i]/2;
			sum+=a[i];
		}
    }
     cout<<"1"<<endl;
     cout<<ans;
}
