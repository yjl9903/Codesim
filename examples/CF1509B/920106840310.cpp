#include <iostream>

using namespace std;

int main() 
{
	int t,n;
	char s[100000];
	int Tnum=0,Nnum=0;
	bool judge=true;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		cin>>n;
		for (int j=0;j<n;j++)
		{
			cin>>s[j];
		}
		
		/*for (int j=0;j<n;j++)
		{
			cout<<s[j];
		}*/
		
		for (int j=0;j<n;j++)
		{
			if (s[j]=='T') Tnum++;
			if (s[j]=='M') Nnum++;
			//cout<<Tnum<<" "<<Nnum<<endl;
			if (Tnum<Nnum) 
			{
				judge=false;
				//break;
			}
		}
		Tnum=0;Nnum=0;//judge=true;
		for (int j=n-1;j>=0;j--)
		{
			if (s[j]=='T') Tnum++;
			if (s[j]=='M') Nnum++;
			if (Tnum<Nnum) 
			{
				judge=false;
				//break;
			}
			//cout<<Tnum<<" "<<Nnum<<endl;
		}
		
		if (judge==false || Tnum!=Nnum*2) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		Tnum=0;Nnum=0;judge=true;
	}
	return 0;
}
