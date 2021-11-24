#include <iostream>
using namespace std;
int main (){
	int t,n,ji=0,ou=0;
	int sl[2000];
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=0;i<n;i++){
			cin >> sl[i];
			if (sl[i]%2==1) cout << sl[i] <<' ';
		}
        for (int i=0;i<n;i++){
        	if (sl[i]%2==0) cout << sl[i] <<' ';
		}
		cout << endl;
	}
} 
