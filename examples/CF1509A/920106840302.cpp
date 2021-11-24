#include <iostream>
using namespace std;
int Change(int a[], int t);
int main()
{
	int n;
	cin >> n;
	int a[n][10000] = { 0 };
	int c[n] = { 0 };
	int i = 0, count = 0;
	while (i < n)
	{
		int m;
		cin >> m;
		int b[m] = { 0 };
		c[count] = m;
		count++;
		for (int j = 0; j < m; j++)
			cin >> b[j];
		Change(b, m);
		for (int j = 0; j < m; j++)
			a[i][j] = b[j];
		i++;
	}
	for (int j = 0; j < n; j++)
	{
		for (int m = 0; m < c[j]; m++)
		{
			if (m != (c[j] - 1))
				cout << a[j][m] << " ";
			else
				cout << a[j][m];
		}
		cout << endl;
	}
	return 0;
}
int Change(int a[], int t)
{
	int b[t] = { 0 };
	int c[t] = { 0 };
	int j = 0;
	int m = 0;
	for (int i = 0; i < t; i++)
	{
		if (a[i] % 2 != 0)
		{
			b[j] = a[i];
			j++;
			continue;
		}
		else
		{
			c[m] = a[i];
			m++;
			continue;
		}
	}
	for (int i = 0; i < j; i++)
		a[i] = b[i];
	for (int i = 0; i < m; i++)
		a[i + j] = c[i];
}
