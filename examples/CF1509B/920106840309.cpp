#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	bool a[100005];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int t1=0,m1=0,t2=0,m2=0;
		char c;
		bool p=1;
		for(int j=0;j<n;j++)
		{
			cin>>c;
			if(c=='T')a[j]=1;
			else a[j]=0;
		}
		for(int j=0;j<n;j++)
		{
			if(a[j])t1++;
			else m1++;
			if(a[n-j-1])t2++;
			else m2++;
			if(t1<m1||t2<m2)break;
			if(j==n-1&&t1==m1*2)
			{
				cout<<"YES"<<endl;
				p=0;
			}
		}
		if(p)cout<<"NO"<<endl;
	} 
	return 0;
}
