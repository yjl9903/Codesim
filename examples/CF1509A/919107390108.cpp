#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		int *p = new int [n];
		int temp, lp = 0, rp = n - 1;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (temp % 2 == 1) {
				p[lp] = temp;
				lp++;
			} else {
				p[rp] = temp;
				rp--;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << p[i] << " ";
		}
		delete []p;
	}
	return 0;
}