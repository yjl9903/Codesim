#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char a[100001];
int main(int argc, char** argv) {
	int t1;
	cin>>t1;
	while(t1--){
		int n,t=0,m=0,k=1;
		cin>>n>>a;
		for(int i=0;i<n;i++){
			if(a[i]=='T')t++;
			if(a[i]=='M')m++;
			if(m>t){
				k=0;
				break;
			}
		}
		if(k==1){
			t=0,m=0;
		 for(int i=n-1;i>=0;i--){
		 	if(a[i]=='T')t++;
				if(a[i]=='M')m++;
				if(m>t){
					k=0;
					break;
				}
			}
		}
		
		if(k==1&&t==m*2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
