#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	char t[8][4]={0};
	int a=0;
	int b=0;
	bool f[8]={true,true,true,true,true,true,true,true};
	int max=0;
	int start=-1;
	for(int i=0;i<39;i++){
		if(s[i]!=':'){
			t[a][b]=s[i];
			b++;
		}
		if(b==4){
			b=0;
			a++;
		}
	}
/*	for(int i=0;i<8;i++){
		for(int j=0;j<4;j++)
			cout<<t[i][j]; 
		cout<<endl;
	}*/
	for(int i=0;i<8;i++){
		int count=0;
			if(t[i][0]=='0'){
				count++;
				if(t[i][1]=='0'){
					count++;
					if(t[i][2]=='0'){
						count++;
						if(t[i][3]=='0')count++;
					}
				}
			}
		if(count==4)f[i]=false;
//		cout<<i<<":"<<count<<",bool="<<f[i]<<endl;
	}
	for(int i=0;i<8;i++){
		int tmp=0;
		while(f[i]==false&&i<8){
			tmp++;
//			cout<<tmp<<",i="<<i<<endl;
			i++;
		}
		if(tmp>max){
			max=tmp;
			start=i-tmp;
		}
	}
//	cout<<"max="<<max<<endl;
	for(int i=0;i<8;i++){
		int j=0;
		if(i<start||i>=start+max){
			if(t[i][0]=='0'){
				j++;
				if(t[i][1]=='0'){
					j++;
					if(t[i][2]=='0')j++;
				}
			} 
			for(int k=j;k<4;k++)cout<<t[i][k]; 
			if(i<7)cout<<":";
		}
		if(start==0)
			if(i==0)cout<<":";
		if(i==start+max-1)cout<<":";
		if(i==7) cout<<endl;
	}
	return 0;
} 
