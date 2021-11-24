#include <bits/stdc++.h>
using namespace std;
char a[100001];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,j=0,x=0,y=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++){
			if(a[i]=='T')x++;
			else y++;
			if(x<y){
				j=1;
				break;
			}
		}
		x=0;y=0;
		for(int i=n-1;i>=0;i--){
			if(a[i]=='T')x++;
			else y++;
			if(x<y){
				j=1;
				break;
			}
		}
		if(j==1||x!=y*2)
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}
	return 0;
} 
