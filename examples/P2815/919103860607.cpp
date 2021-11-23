#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int l = s.length();
	int a = 0,js=0,M=0,wz=-1,last=-1;
	for(register int i = 0;i < l;i += 5){
	   if(s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0' && s[i + 3] == '0'){
		if(last == i - 5)
			last = i;
		else{
			js = 0;
			last = i;
			a = i;
		}
		js ++;
       }
	   if(js > M){
		 M = js;
		 wz = a;
		}
	}	
	int jj = 0;
	while(jj < l){
	   if(jj == wz){
		if(jj == 0)
		   cout << ":";
		   jj += M * 5 - 1;
		if(jj == l)
		   cout << ":";
	   }
	  else{
		if(jj % 5 == 0){
			if(jj >= 35){
				while(s[jj] == '0' && jj + 1 != l){
					jj ++;
				}
		    }
			else{	
				while(s[jj] == '0' && s[jj + 1] != ':'){
					jj ++;
				}		
			}		
		}		
		cout << s[jj]; 		
		jj ++;			
	}			
	}		
	cout << endl;
	return 0;		
} 
