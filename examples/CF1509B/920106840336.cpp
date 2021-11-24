#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,len;
	cin>>n;
	while(n--){
		string a;
		int t=1,num1=0,num2=0;
		cin>>len;
		cin>>a;
		for(int i=0;i<len;i++){
			if(a[i]=='M') num2++;
			if(num1<num2) {
				t=2;
				cout<<"NO"<<endl;
				break;
			}
			if(a[i]=='T') num1++;
		}
		if(num2*2!=num1&&t==1){
			t=3;
            cout<<"NO"<<endl;
			continue;
		}
		num1=0;
		num2=0;
		for(int i=len-1;i>=0;i--){
			if(a[i]=='M') num2++;
			if(num1<num2&&t==1) {
				t=0;
				cout<<"NO"<<endl;
				break;
			}
			if(a[i]=='T') num1++;
		}
		if(t==1) cout<<"YES"<<endl;
	}
	return 0;
}
