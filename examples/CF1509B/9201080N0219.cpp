#include <iostream>
using namespace std;
struct TMT
{
	int n = 0;
	string TMTs;
};
int Check(TMT s)
{
	int TNum = 0, MNum = 0;
	//判断M前是否有充足的T
	for (int i = 0; i < s.n; i++)
	{
		if (s.TMTs[i] == 'T')
			TNum++;
		else
			MNum++;
		if (TNum < MNum)
			return 0;
	}
	TNum = 0, MNum = 0;
	//判断M后是否有充足的T
	for (int i = s.n - 1; i >= 0; i--)
	{
		if (s.TMTs[i] == 'T')
			TNum++;
		else
			MNum++;
		if (TNum < MNum)
			return 0;
	}
	//判断T的个数是否为M两倍
	if (TNum == MNum * 2)
		return 1;
	else
		return 0;
}
int main()
{
	//录入字符串，并确保输入正确
	int T = 0;
	cin >> T;
	TMT* s = new TMT[T];
	for (int i = 0; i < T; i++)
	{
		cin >> s[i].n;
		cin >> s[i].TMTs;
	}
	for (int i = 0; i < T; i++)
	{
		if (Check(s[i]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	delete[]s;
	return 0;
}