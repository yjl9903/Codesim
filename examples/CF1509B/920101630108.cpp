#include<bits/stdc++.h>
using namespace std;

int main(){
	int t=0,n=0,cn1=0,cn2=0,flag=0,i=0;
	string a;
	scanf("%d",&t);
	
	while(t--){
	    cn1=0,cn2=0,flag=0;
		cin>>n>>a;
		for( i=0;i<n;i++){
			if(a[i]=='T') cn1++;
			if(a[i]=='M') cn2++;
			if(cn1<cn2){
			    flag=1;
			    break;
			}
		}
		for(cn1=0,cn2=0, i=n-1;i>=0;i--){
			if(a[i]=='T')cn1++;
			if(a[i]=='M')cn2++;
			if(cn1<cn2){
			    flag=1;
			    break;
			}
		}
		if(flag==1||cn1!=cn2*2)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
