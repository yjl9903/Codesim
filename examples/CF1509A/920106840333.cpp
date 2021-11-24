#include<bits/stdc++.h>
using namespace std;
int N,n,a[100];
int main(){
	cin>>N;
	while(N--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]%2==1)cout<<a[i]<<" ";
		}
		for(int i=1;i<=n;i++){
			if(a[i]%2==0)cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
