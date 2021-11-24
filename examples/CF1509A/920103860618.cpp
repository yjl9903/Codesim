#include <iostream>
using namespace std;

int t,n,a[2000];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i){
			if(a[i]%2==0)cout<<a[i]<<" ";
		}
		for(int i=0;i<n;++i){
			if(a[i]%2==1)cout<<a[i]<<" ";
		};
	}
	return 0;
}