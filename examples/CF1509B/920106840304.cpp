#include<bits/stdc++.h>
using namespace std;
char ch[20000];
int main ()
{
	int t;
	cin>>t;
	string ch; 
	while(t--)
	{
		int n;
		cin>>n;
		cin>>ch;
		int r=0,s=0,i=0;
		for(i=0 ; i<n ;i++)
		{	
		    if(ch[i]=='T') r++;
			if(ch[i]=='M') s++;
		}		
		if((r/2)!=s) cout<<"NO"<<endl;
		else{
				int kk=0,ss=0,cc=0;
			    for(int j=0 ;j <n ;j++)
		        	{
				     if(ch[j] == 'T')  kk++;
				     if(ch[j] == 'M')  ss++;
				     if(kk < ss)  {
				     	    cc=1;
				     	    break;
					     } 
			    	} 
			        
		        kk=0;
		        ss=0;
		    	for(int j=n-1 ; j>=0 ;j--)
		    	{
				 if(ch[j] == 'T')  kk++;
				 if(ch[j] == 'M')  ss++;
				 if(kk < ss){
				 	cc=1;
				 	break;
				    }
		    	}
			    if(cc == 1) cout<<"NO"<<endl;
			    else cout<<"YES"<<endl;
	  	}
	
	} 
	
	return 0;
 } 
