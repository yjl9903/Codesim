#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[300];
int f[200005];
int main(){
	int len,num,sum=0,minn=100000,mini=0;
	cin>>len;
	for(int i=0;i<len;i++){
		cin>>a[i];
		sum+=a[i];
	}
	f[0]=1;
	for(int i=0;i<len;i++)
		for(int j=200005;j>=a[i];j--)
			f[j]|=f[j-a[i]];
	if((sum%2)||!f[sum/2]) {
		cout<<0<<endl;
		return 0;
	}
	if(sum%2==0){
		for(int i=0;i<len;i++){
		    int x=a[i];
			num=0;
		    while(!(x&1)){
			x>>=1;
			num++;
		    }
		    if(num<minn) minn=num,mini=i;
	    }
	    cout<<1<<endl;
	    cout<<mini+1<<endl;
	}
	return 0;
} 
