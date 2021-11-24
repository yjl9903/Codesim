#include<iostream>
using namespace std;



int main(){
	int t=0,n=0,a[2000]={0};

	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]%2==0)cout<<a[i]<<" ";
		}
		for(int i=0;i<n;i++)if(a[i]!=0
		)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
