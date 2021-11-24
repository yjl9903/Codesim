//很容易看出，当和为奇数时，必定无法进行分类,即是一个好数列，不需要消元
//若为偶数，则去掉一个奇数，若每个元素都是偶数，则去掉第一个/2后为奇数的.
#include<bits/stdc++.h>
using namespace std;
int ea[105];
bool f[200005];
int main(){
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ea[i],sum+=ea[i];
	if(sum&1){
		cout<<"0";
		return 0;
	}
	sum/=2;
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=sum;j>=ea[i];j--)
			f[j]|=f[j-ea[i]];
	if(!f[sum]){
		puts("0");
		return 0;
	}
	int minc=1e5,minp=0;
	for(int i=1;i<=n;i++){
		int x=ea[i],cnt=0;
		while(!(x&1)){
			x>>=1;
			cnt++;
		}
		if(cnt<minc) minc=cnt,minp=i;
	}
	printf("1\n%d",minp);
	return 0;
}
