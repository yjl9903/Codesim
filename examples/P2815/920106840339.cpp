#include <bits/stdc++.h> 
using namespace std;
string s;
int main()
{
	cin>>s;
	int a=0;
	int l=0;
	int num=0;
	int start=-1;
	int last=-1;
	for(int i =0;i<s.length();i+=5)
	{
		if(s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='0'&&s[i+3]=='0') 
		{
		    if(last!=i-5)
			{
				l=0;
				last=i;
				a=i;
			}
			else {
				last=i;
			}
			l ++;
		}
		if(l>num)
		{
			num=l;
			start=a;
		}
	}
	int jj=0;
	while(jj<s.length())
	{
		if(jj==start)
		{
			if(jj==0)
				cout << ":";
			jj +=num*5-1;
			if(jj==l)
				cout<<":";
		}
		else
		{
			if(jj%5==0)
			{
				if(jj>=35)
				{
					while(s[jj]=='0'&&jj+1!=s.length())
					{
						jj ++;
					}
				}
				else
				{
					while(s[jj]=='0'&&s[jj+1]!=':')
					{
						jj ++;
					}
				}
			}
			cout<<s[jj]; 
			jj ++;
		}
	}
	cout<<endl;
	return 0;
}
