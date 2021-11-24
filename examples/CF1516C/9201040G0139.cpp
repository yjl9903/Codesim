#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int *p = new int[n];
	int *p_new = new int[n];
	int sum = 0;
	int flag = 0;
	int re;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		if (p[i] % 2 != 0)
		{
			flag = 1;
			re = i;
		}
	}
	/*对原数列化简*/
	while (flag==0)
	{
		for (int i = 0; i < n; i++)
		{
			p[i] /= 2;
			if (p[i] % 2 != 0)
			{
				re = i;
				flag = 1;
				continue;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		sum += p[i];
	}
	/*为奇数已经为好数列，不需要删除*/
	if (sum % 2 == 1)
		cout << 0 << endl;
	/*为偶数判断是否为好数列*/
	else
	{
		/*对之前的数列进行排序*/
		for (int i = 0; i < n; i++)
			p_new[i] = p[i];
		sort(p_new, p_new + n);
		int m = sum / 2;
		/*缺少判断是否满足和为某数1 7 6 8*/
		//判断两位是否成立
		if (n == 2)
		{
			if (p[0] == p[1])
			{
				cout << 1 << '\n' << 1 << endl;
				return 0;
			}
		}
		int sum_new=p_new[n - 1];
		//若最大值大于m,那么不成立
		if (p_new[n - 1] > m)
		{
			cout << 0 << endl;
			return 0;
		}
		int i = n-2;
		while (1)
		{
			/*判断历遍之后的结果*/
			//本身为好
			if (i == -1 && sum_new != m)
			{
				cout << 0 << endl;
				return 0;
			}
			//本身为坏
			else if (i == -1 && sum_new == m)
			{
				cout << 1 << endl;
				for (int i = 0; i < n; i++)
				{
					if (p[i] % 2 == 1)
					{
						cout << i + 1 << endl;
						return 0;
					}
				}
			}
			sum_new += p_new[i];

			if (sum_new < m)
			{
				i--;
			}
			else if (sum_new > m)
			{
				sum_new -= p_new[i];
				i--;
			}
			else   //sum == m 满足坏数列
			{
				cout << 1 << endl;
				for (int i = 0; i < n; i++)
				{
					if (p[i] % 2 == 1)
					{
						cout << i + 1 << endl;
						return 0;
					}
				}
			}
			//cout << i << " " << sum_new << endl;
		}
	}
	return 0;
}