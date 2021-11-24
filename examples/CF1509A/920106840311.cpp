#include<iostream>
using namespace std;



int main(){
	int t,n,a[2001];
	cin>>t;
	if(t<1||t>500)cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<2||n>2000)cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		
		for(int i=0;i<n;i++)if(a[i]%2)cout<<a[i]<<" ";
		for(int i=0;i<n;i++)if(!(a[i]%2))cout<<a[i]<<" ";
		
		cout<<endl;
	}
	return 0;
} 
