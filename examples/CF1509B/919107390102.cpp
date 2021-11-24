#include<bits/stdc++.h>
using namespace std;
int t,n,countT,countM,flag=1;
string a;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a;a=" "+a;
		for(int i=1;i<=n;++i){
			if(a[i]=='T')countT++;
			if(a[i]=='M')countM++;
			if(countT<countM){flag=0;break;}
		}countT=0,countM=0;
		for(int i=n;i>=1;--i){
			if(a[i]=='T')countT++;
			if(a[i]=='M')countM++;
			if(countT<countM){flag=0;break;}
		}
		if(flag==0||countT!=countM*2)puts("NO");
		else puts("YES");
	    countT=0,countM=0,flag=1;
	}
	return 0;
}
