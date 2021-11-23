#include <bits/stdc++.h>
using namespace std;
int ans0[9];
int main(){
	int sum=0,ansi=0,i,j;
	char s[40];
	for (i=1;i<=39;i++) cin >> s[i]; 
	for (i=1;i<=8;i++){
	    for (j=4;j>=1;j--){
	    	if (s[5*i-j]=='0') ans0[i]++;
	    	else break;
		} 
	}
	for (i=1;i<=8;i++){
		if (ans0[i]<4) continue;
		for (j=i;j<=8;j++)if (ans0[j]<4) break;
		if (j-i>sum)sum=j-i,ansi=i;
		i=j-1;
	}
	for (i=1;i<=8;i++){
		if (i==ansi) 
		{
			i+=sum-1;
			if (ansi==1) cout << "::";
			else cout << ":";
		}
		else 
		{
			for (j=4-ans0[i];j>0;j--)cout << s[5*i-j];
			if (ans0[i]==4) cout << '0';
			if (i<8) cout << ":";
		}
	}
} 
