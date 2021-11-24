#include<iostream>
using namespace std;
int a[2010],b[2010],c[2010];
int i,j,q;
int main(){
	int m,n;
	cin>>m;
	for(i=0;i<m;i++){
		int k=0,g=0;
		cin>>n;
		for(j=0;j<n;j++){
			cin>>a[j];
			if(a[j]%2==0){
				b[k]=a[j];
				k++;	
			}
			else{
				c[g]=a[j];
				g++;
			}
		}
		for(j=0;j<g;j++)
		cout<<c[j]<<' ';
		for(q=0;q<k;q++)
		cout<<b[q]<<' ';	
		cout<<endl;
		for(q=0;q<k;q++)
		b[q]=0;
		for(j=0;j<g;j++)
		c[j]=0;
	}
}
