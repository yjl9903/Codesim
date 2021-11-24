#include<bits/stdc++.h>
using namespace std;
int judge(int b){
	if(b%2==1) return 0;//·µ»Ø0ÎªÆæÊý 
	else return 1;
}
int main(){
	int n=0;
	cin>>n;
	int sum=0; 
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	if(judge(sum)==0){
		cout<<0<<endl;
	} 
	else{
		for(int i=0;i<n;i++){
		if(judge(a[i])==0){
			int c=0;
			c=i+1;
			cout<<1<<endl;
			cout<<c<<endl;
			break;
		}
	}
	}
	return 0;
}
