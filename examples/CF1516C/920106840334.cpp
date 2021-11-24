#include<iostream>
#include<cstdio>
using namespace std;
int a[105];
bool f[200005];
int main(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	if(sum&1){
		puts("0");
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
	int minc=1e5,minp=0;
	for(int i=1;i<=n;i++){
		int x=a[i],cnt=0;
		while(!(x&1)){
			x>>=1;
			cnt++;
		}
		if(cnt<minc) minc=cnt,minp=i;
	}
	printf("1\n%d",minp);
	return 0;
}
