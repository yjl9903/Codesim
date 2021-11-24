#include<bits/stdc++.h>
#define int long long
using namespace std;

int read() {
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}

const int MAXN=1e5;

int n,sum;
int a[MAXN];
bool f[2][MAXN];

void div() {
	while(1) {
		for(int i=1;i<=n;i++) {
			if(a[i]&1) {
				cout<<1<<endl<<i<<endl;
				return ;
			}
			a[i]>>=1;
		}
	}
}

signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		a[i]=read();
		sum+=a[i];
	}
	if(sum&1) {
		cout<<0<<endl;
		return 0;
	}
	
	int m=sum/2;
	fill(f[0],f[0]+m+1,0);
	f[0][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			f[i%2][j]=f[(i-1)%2][j];
			if(j>=a[i]) {
				f[i%2][j]=f[i%2][j]|f[(i-1)%2][j-a[i]];
			}
		}
	}
	if(!f[n%2][m]) {
		cout<<0<<endl;
		return 0;
	}
	
	div();
	return 0;
}
