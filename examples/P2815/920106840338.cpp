#include <bits/stdc++.h>
using namespace std;
int main(){
	string h;
	cin>>h;
	int aa=-1,bb=-1,a=1,b=1,flag=0,t=0,ans=0;
	string m="";
	for(int i=0;i<h.size();){
		if(h[i]=='0'&&h[i+1]=='0'&&h[i+2]=='0'&&h[i+3]=='0'){
			if(flag==0){
				a=i;t=0;
			}
			i+=5;flag=1;t++;
		}
		else{
			if(flag==1){
				b=i;
				if(t>ans){
					aa=a;bb=b-1;ans=t;
				}
			} 
			i+=5;flag=0;
		}
	}
	if(flag==1){
		b=h.size()-1;
		if(t>ans){
			aa=a;bb=b;ans=t;
		}
	}
	if(aa==0)m+=':';
	for(int i=0;i<h.size();i++){
		if(i==aa){
			i=bb;
		}
		else{
		while(h[i]=='0')i++;
		if(h[i]==':'||i==h.size()){
			i--;
		}
		while(h[i]!=':'&&i<h.size()){
			m+=h[i];i++;
		}}
		if((i!=h.size())||(bb==h.size()-1))m+=':';
	} 
	cout<<m<<endl;
	return 0;
} 
