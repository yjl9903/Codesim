#include <iostream>
using namespace std;
#define N 100005
int n;
int count,Tnum,Mnum,flag;
char s[N];
int main()
{
	Tnum=0,Mnum=0,flag=0;;
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>count;
        if(count%3!=0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cin>>s;
		for(j=0;j<count;j++)
		{
			if(s[j]=='M')
			Mnum++;
			if(s[j]=='T')
			Tnum++;
			if(Tnum<Mnum)
			{
				flag=1;
				break;
			}
		}
		Tnum=0,Mnum=0;
		for(j=count-1;j>=0;j--)
		{
			if(s[j]=='M')
			Mnum++;
			if(s[j]=='T')
			Tnum++;
			if(Tnum<Mnum)
			{
				flag=1;
			    break;
			}
		}
		if(flag==1||Tnum!=(2*Mnum))
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl; 
		Tnum=0,Mnum=0,flag=0;
	}
	
 } 
