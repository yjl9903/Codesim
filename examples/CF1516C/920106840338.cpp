#include <bits/stdc++.h>
using namespace std;
int a[1000000]={0},f[1000000]={0};
int main(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];sum+=a[i];
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=a[i];j--)f[j]=max(f[j],f[j-a[i]]);
	}
	if(sum&1||!f[sum>>1]){
		cout<<"0"<<endl;
		return 0;
	}
	while(1){
		for(int i=1;i<=n;i++){
			if(a[i]&1){
				cout<<"1"<<endl<<i<<endl;
				return 0;
			}
			a[i]/=2;
		}
	}
	return 0;
} 
