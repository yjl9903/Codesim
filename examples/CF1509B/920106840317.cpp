#include <bits/stdc++.h>
using namespace std;
int main(){
	int T,n;
	char s[100002];
	cin >> T;
	while (T--){
		int numT=0,numM=0;
		bool f=1;
		cin >> n;
		for (int i=1;i<=n;i++) cin >> s[i];
		for (int i=1;i<=n;i++){
			if (numT<numM) 
			{
				f=0;
				break;
			}
			if (s[i]=='T') numT++;
			else numM++;
		}
		for (int i=n,numT=0,numM=0;i>0;i--){
			if (numT<numM) 
			{
				f=0;
				break;
			}
			if (s[i]=='T') numT++;
			else numM++;
		}
		if (f==0||numT!=2*numM) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
