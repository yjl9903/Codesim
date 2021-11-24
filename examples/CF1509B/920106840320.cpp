#include<iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		char s[n]={0};
		cin.get();
		cin.getline(s,n+1);
		int t=0;
		int m=0;
		bool c=true;
		for(int j=0;j<n;j++){
			if(s[j]=='T')t++;
			if(s[j]=='M')m++;
			if(m>t){
				c=false;
				break;
			}
		}
		t=0;
		m=0;
		for(int j=n;j>=0;j--){
			if(s[j]=='T')t++;
			if(s[j]=='M')m++;
			if(m>t){
				c=false;
				break;
			}
		}
//		cout<<t<<' '<<m<<endl;
		if(t!=2*m)
			c=false;
		if(c==false)
			cout<<"NO"<<endl;
		if(c)
			cout<<"YES"<<endl;
	}
	return 0;
}
