#include<iostream>
using namespace std;
int f[200010];
int a[110];
int sum,num,tsy;
bool sf(int x,int y){
	f[0]=1;
	for(int i=1;i<=x;i++)
		for(int j=y;j>=a[i];j--)
			f[j]|=f[j-a[i]];
	if(f[y]==1)
	return 1;
	else
	return 0;
}
int main(){
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]%2!=0&&num==0){
			tsy=i;
			num++;
		}
	}
	if(sum%2!=0)
		cout<<0<<endl;
	else{
	     if(!sf(m,sum/2))
	     cout<<0<<endl;
	     else{
	     	if(num==1)
	     	cout<<1<<endl<<tsy<<endl;
	     	else{
	     		int max=100000,min=0;
	for(int i=1;i<=m;i++){
		int g=a[i],cnt=0;
		while(g%2==0){
			g>>=1;
			cnt++;
		}
		if(cnt<max) max=cnt,min=i;
	}
	cout<<1<<endl<<min<<endl;
			 }
		 } 
	}
	
} 
