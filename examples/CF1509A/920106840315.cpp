#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;//表示测试用例数
	int n;//表示用例内整数个数
	int a[2003];//用于储存用例内整数
	cin>>t;
	for(t;t>0;t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]%2!=0)cout<<a[i]<<" ";
		}
		for(int i=1;i<=n;i++){
			if(a[i]%2==0)cout<<a[i]<<" ";
		}
		cout<<'\n';
	} 
	return 0;
} 
