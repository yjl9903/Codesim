#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n]={0};
	bool m=false;
	bool f[200005];
	int sum=0;
	int out=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];	
	}
	for(int i=0;i<n;i++){
		if(a[i]%2){
			out=i; 
			break;
		}
	} 
	if(sum%2)m=true;
	else{
		if(out!=-1){
			sum/=2;
			f[0]=1;
			for(int i=1;i<=n;i++)
				for(int j=sum;j>=a[i];j--)
					f[j]|=f[j-a[i]];
			if(!f[sum]){
				cout<<"0"<<endl;
				return 0;	
			} 
		}
		while(out==-1){
			sum/=2;
			if(sum%2){
				m=true;
				break;
			}
			for(int i=0;i<n;i++){
				a[i]/=2;
				if(a[i]%2){
				out=i; 
				break; 
				}	
			}
		}
	}
	if(m)cout<<"0"<<endl;
	else{
		cout<<"1"<<endl;
		cout<<out+1<<endl;
	}
	return 0;
}
