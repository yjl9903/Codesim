#include <bits/stdc++.h>
using namespace std;
int a[2002]={0},b[2002]={0};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x=0,y=0,s;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s;
			if(s&1)a[x++]=s;
			else b[y++]=s;
		}
		for(int i=0;i<x;i++)cout<<a[i]<<" ";
		for(int i=0;i<y;i++)cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
} 
