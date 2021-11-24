#include <iostream>
using namespace std;
int main()
{
	int a[2005];
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int b;
		cin >> b;
		for (int i = 0; i < b; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < b; i++)
		{
			if (a[i] % 2 == 0)
				cout << a[i] << " ";
		}
		for (int i = 0; i < b; i++)
		{
			if (a[i] % 2 != 0)
				cout << a[i] << " ";
		}
	}
}
