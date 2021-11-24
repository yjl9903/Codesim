#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		/*输出奇数*/
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 1)
				cout << a[i] << ' ';
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 0)
				cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}