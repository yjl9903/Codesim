#include<iostream>
using namespace std;
string s3[10];
int count,mark,k,m;
int main(){
	string s,s1="0000",s2;
	cin>>s;
	for(int i=0;i<s.size();i++){
		s2="";
		m=0;
		while(m!=4){
			if(s[i]=='0'&&mark==0)
			count++;
			else{
				s2+=s[i];
				mark++;
			}
			i++,m++;
		}
		if(count==4)
		s2=s1;
		s3[k]=s2;
		k++;
		count=0,mark=0;
	}
	int num,a,b,g,max=0;
	for(k=0;k<8;k++){
		num=0;
		if(s3[k]==s1){
			g=k;
		while(s3[k]==s1){
			num++;
			k++;
		}
		k--;
		if(num>max){
			a=g,b=k;
			max=num;
		}
	}
}
    for(k=0;k<8;k++){
    	if(s3[k]==s1){
    		if(k==a){
    			if(a==0)
    			cout<<"::";
    			else
    			cout<<":";
    			k=b;
    			continue;
			}
			else
			cout<<"0";
		}
    	else
    	cout<<s3[k];
    	if(k!=7)
    	cout<<":";
	}
}
