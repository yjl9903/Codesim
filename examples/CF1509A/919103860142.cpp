#include<bits/stdc++.h>
using namespace std;
int t,n,a[2005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			if(a[i]%2==0)cout<<a[i]<<" ";
		}
		for(int i=1;i<=n;++i){
			if(a[i]%2==1)cout<<a[i]<<" ";
		}cout<<endl;
	}
	return 0;
}
