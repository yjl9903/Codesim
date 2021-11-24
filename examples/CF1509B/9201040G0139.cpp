#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int *Re = new int[t];
	int T = t;
	for(int j=0;j<t;j++)
	{
		int n, re, TNum = 0, MNum = 0;
		cin >> n;
		char *a = new char[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int flag = 0;
		/*正序判断*/
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 'T')
				TNum++;
			else if (a[i] == 'M')
			{
				MNum++;
			}
				
			if (MNum > TNum)
			{
				re = 0;
				flag = 1;
				break;
			}
		}
		/*倒叙判断*/
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] == 'T')
				TNum++;
			else if (a[i] == 'M')
				MNum++;
			if (MNum > TNum)
			{
				re = 0;
				flag = 1;
				break;
			}
		}
		/*是否已经赋值*/
		if (flag == 1)
		{ 
			Re[j] = re;
			continue;
		}
		/*是否满足*/
		if (TNum == (2 * MNum))
			re = 1;
		else
			re = 0;
		Re[j] = re;
	}
	for (int i = 0; i < t; i++)
	{
		if (Re[i] == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}