#include<iostream>
using namespace std;
char a[100010];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cin.getline(a,n);
		int t = n / 3;
		int m = 0;
		int T = 0;
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 'T')
			{
				T++;
			}
			else
			{
				m++;
				T--;
			}
			if (T < 0 || T > n / 3)
			{
				flag = 1;
				break;
			}
		}
		if (flag || m != t)
		{
			cout<<"NO";
			continue;
		}
		else
		{
			cout<<"YES";
			continue;
		}

	}
}


