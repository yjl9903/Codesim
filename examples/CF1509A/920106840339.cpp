#include <iostream>
using namespace std;
int t,n,a[2000];
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++)
		{
		cin>>a[j];	
		}
		for(int j=0;j<n;j++){
			if(a[j]%2==0) 
			cout<<a[i]<<" ";
		}
		for(int j=0;j<n;j++){
			if(a[j]%2==1) cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

