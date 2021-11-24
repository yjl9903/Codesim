#include<bits/stdc++.h>
using namespace std;
int t,n,numT,numM,flag=1;
string a;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a;a=" "+a;
		for(int i=1;i<=n;++i){
			if(a[i]=='T')numT++;
			if(a[i]=='M')numM++;
			if(numT<numM){flag=0;break;}
		}numT=0,numM=0;
		for(int i=n;i>=1;--i){
			if(a[i]=='T')numT++;
			if(a[i]=='M')numM++;
			if(numT<numM){flag=0;break;}
		}
		if(flag==0||numT!=numM*2)puts("NO");
		else puts("YES");
	    numT=0,numM=0,flag=1;
	}
	return 0;
}