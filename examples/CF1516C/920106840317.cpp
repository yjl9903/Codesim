#include <bits/stdc++.h>
using namespace std;
int a[101];
bool b[200001];
int main (){
	int n,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	if(sum&1) 
	{
		cout << 0;
		return 0;
	}
	sum/=2;
	b[0]=1;
	for(int i=1;i<=n;i++)for(int j=sum;j>=a[i];j--)b[j]|=b[j-a[i]];
	if(!b[sum]) 
	{
		cout << 0;
		return 0;
	}
	for(int i=1;;i++){
		if (a[i%n]&1) 
		{
			cout << 1 << endl << i%n;
			break;
		}
		else a[i%n]/=2;
	}	
}
