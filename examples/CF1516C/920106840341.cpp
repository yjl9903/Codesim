#include<bits/stdc++.h>
using namespace std;
int f[10000005];
int main(){
	int n;
	cin>>n;
	int a[105];
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int s=sum/2;
	if(sum%2==1){cout<<0<<endl;return 0;}
	for(int i=0;i<=n;i++){
		for(int j=s;j>=a[i];j--){
			f[j]=max(f[j],f[j-a[i]]+a[i]);
		}
	}
	if(f[s]!=s){cout<<0<<endl;return 0;}
	while(1){
		for(int i=1;i<=n;i++){
			if(a[i]%2==1)
			{  cout<<1<<endl<<i<<endl;return 0;}
		}
		for(int i=1;i<=n;i++)
		{  a[i]=a[i]/2;
			  } 	 
	}
	
	return 0;
} 
