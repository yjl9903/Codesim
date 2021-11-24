#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int t=0;
	cin>>t;
	int a[2000]={0};
	for(int i=0;i<t;i++){
		int n=0;
		cin>>n;
		for(int j=0;j<n;j++) cin>>a[j];
		for(int j=0;j<n;j++){
			if(a[j]%2==1) cout<<a[j]<<" ";
		}
		for(int j=0;j<n;j++){
			if(a[j]%2==0) cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
