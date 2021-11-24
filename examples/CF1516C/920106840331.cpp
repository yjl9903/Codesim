#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	bool f[10000]={0};
	int n=0,sum=0,a[102]= {0};
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%2==1){
		cout<<0;
		return 0;
	}
	sum/=2;
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=sum;j>=a[i];j--)
			f[j]|=f[j-a[i]];
	if(!f[sum]){
		puts("0");
		return 0;
	}
s:
	for(int i=1;i<=n;i++){
		if(a[i]&1){
			cout<<1<<"\n"<<i;
			return 0;
		}
	}
	for(int i=1;i<=n;i++) a[i]/=2;
	goto s;
}
