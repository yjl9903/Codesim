#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string a;
		int s=0,t=0,m=0;
		bool pd=false;
		cin>>s;
		cin>>a;
		for(int i=0;i<s;i++)
		{
			if(a[i]=='T')
			t++;
			if(a[i]=='M')
			m++;
			if(t<m)
			{
				pd=true;
				break;
			}
		}
		m=0,t=0;
		for(int i=s-1;i>=0;i--)
		{
			if(a[i]=='T')
			t++;
			if(a[i]=='M')
			m++;
			if(t<m)
			{
				pd=true;
				break;
			}
		}
		if(t!=m*2||pd==true)
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	} 
    return 0;
}
