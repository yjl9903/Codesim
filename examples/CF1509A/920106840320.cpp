#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int a[2000]={0};
		int ji[2000]={0};
		int ou[2000]={0};
		int n;
		cin>>n;
		int c=0;
		int d=0;
		for(int j=0;j<n;j++){
			cin>>a[j];
			if(a[j]%2==1){
				ji[c]=a[j];
				c++;
			}
			else{
				ou[d]=a[j];
				d++;
			}
		}
		for(int e=0;e<c;e++) 
			cout<<ji[e]<<' ';
		for(int f=0;f<d;f++)
			cout<<ou[f]<<' ';
		cout<<endl;
	} 
}

