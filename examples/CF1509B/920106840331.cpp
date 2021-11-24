#include <iostream>
using namespace std; 
int left(char ch[],int n){
	int nM=0;int nT=0;
	for(int i=0;i<n;i++){
		if(ch[i]=='M'){
			nM++;
			if(nT<nM) return 0;
		}
		if(ch[i]=='T') nT++;
	}
	return 1;
}

int right(char ch[],int n){
	int nM=0;int nT=0;
	for(int i=n-1;i>=0;i--){
		if(ch[i]=='M'){
			nM++;
			if(nT<nM) return 0;
		}
		if(ch[i]=='T') nT++;
	}
	return 1;
}

int main(int argc, char** argv) {
	int T=0;
	char ch[100000];
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		int ans=1;
		cin>>ch;
		ans=left(ch,n);
		if(ans==0){
		cout<<"NO"<<endl;
		continue;
		}
		ans=right(ch,n);
		int nM=0;
		int nT=0;
		for(int j=0;j<n;j++){
			if(ch[j]=='T') nT++;
			if(ch[j]=='M') nM++;
		}
		if(nT!=2*nM) ans=0;
		if(ans==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
