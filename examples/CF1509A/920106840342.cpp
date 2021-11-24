#include<iostream>
using namespace std;
int a[2000];
int main(){
	long long t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];}
		for(int i=1;i<=n;i++){
			if(a[i]%2==0)
			 cout<<a[i]<<" ";
		}
		for(int i=1;i<=n;i++){
			if(a[i]%2==1)
			 cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

