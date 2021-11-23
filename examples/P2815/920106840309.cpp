#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	bool p=0;
	int i=0,begin=-1,end,a[9]={0,5,10,15,20,25,30,35,40},m=0;
	cin>>s;                          
	while(s[a[i]]!='0'&&i<8)i++;    
	int j=i;                                  
	while(j<8)
	{	
		for(int k=a[j];k<a[j]+4;k++)
		if(s[k]!='0')
		{
			i=j+1;
			break;
		}       
		if(j+1-i>m)
		{
			m=j+1-i;
			begin=i;
			end=j+1;           
			p=1; 
		}                     
		j++;                       
	}                    
	if(begin==0)cout<<":";               
	for(int i=0;i<8;i++)
	if(i==begin)
	{
		cout<<":";
		i=end-1;
	}
	else 
	{
		int j=a[i];
		while(s[j]=='0')j++;
		if(p&&j-a[i]==4)cout<<0;
		for(;j<a[i+1];j++)cout<<s[j];
	}
	cout<<endl;
	return 0;
}
