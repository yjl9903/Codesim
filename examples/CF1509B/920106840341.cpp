#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	    char ch[100001]={0};
	    int s[100001]={0};
	    int t=0;
	    int m=0;
	    for(int i=1;i<=n;i++)
	    {   cin>>ch[i];
	        if(ch[i]=='T'){t++;}
	        if(ch[i]=='M'){m++;s[i]=1;}
		}
		if(ch[1]=='M'){cout<<"No"<<endl;continue;}
		if(m==0||t==0){cout<<"No"<<endl;continue;}
		int sum=0;
		for(int i=1;i<=n;i++)
		{   if(sum<m){
			    if(ch[i]=='T'){s[i]=1;sum++;}
		    }
			else break; 
		}
		int f=1;
		if(t/m==2&&t%m==0){ int tt=0,mm=0;
		for(int i=1;i<=n;i++){
			if(ch[i]=='T')tt++;
			if(ch[i]=='M'){mm++;
			   if(tt<mm){f=0;break;}		   
			  }
	   }
		    tt=0;mm=0;
		    for(int i=n;i>=1;i--){
		    	if(ch[i]=='T'&&s[i]==0)tt++;
		    	if(ch[i]=='M'){mm++;
		    	if(tt<mm){f=0;break;}
				}
		   }					 
		}
		else {cout<<"No"<<endl;continue;}
		if(f==1)cout<<"Yes"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

