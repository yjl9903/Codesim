#include<iostream>
using namespace std;
int Read(){
	char ch=getchar();int res=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=(res<<1)+(res<<3)+ch-'0';
		ch=getchar(); 
	}
	return res;
}
int t,n,p[2005];
int main(){
	t=Read();
	while(t--){
		n=Read();
		for(int i=1;i<=n;++i)
		p[i]=Read();
		for(int i=1;i<=n;++i)
		{
			if(p[i]%2==1)
		    cout<<p[i];
		}
	
		for(int i=1;i<=n;++i)
		{
			if(p[i]%2==0)
		    cout<<p[i];
		}
	
		cout<<endl;
	}
	return 0;
} 
