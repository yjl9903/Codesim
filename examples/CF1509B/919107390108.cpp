#include <bits/stdc++.h>
using namespace std;
int casenum, strl, numT, numM, flag = 1; //全局变量
string str;

int main() {
	cin >> casenum;
	while (casenum--) {
		cin >> strl >> str;
		for (int i = 0; i < strl; i++) {
			if (str[i] == 'T')
				numT++;
			if (str[i] == 'M')
				numM++;
			if (numT < numM)  {
				flag = 0;
				break;
			}
		}
		numT = 0, numM = 0;
		for (int i = strl - 1 ; i >= 0; i--) {
			if (str[i] == 'T')
				numT++;
			if (str[i] == 'M')
				numM++;
			if (numT < numM)  {
				flag = 0;
				break;
			}
		}
		if (flag == 0 || numT != numM * 2)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		numT = 0, numM = 0, flag = 1;
	}
	return 0;
}