#include <iostream>
using namespace std;
int main()
{
	int n = 0, a[2000] = { 0 }, sum = 0;
	bool f[200005];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 2 == 0)
	{
		sum /= 2;
		f[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = sum; j >= a[i]; j--)
				f[j] |= f[j - a[i]];
		if (!f[sum])
		{
			cout << 0 << endl;
			return 0;
		}
		int index = 0, minCount = 1e5;
		for (int i = 1; i <= n; i++)
		{
			int temp = a[i], count = 0;
			while (temp % 2 == 0)
			{
				temp >>= 1;
				count++;
			}
			if (count < minCount)
			{
				minCount = count;
				index = i;
			}
		}
		cout << 1 << endl << index << endl;
	}
	else
		cout << 0 << endl;
	return 0;
}