#include <iostream>
using namespace std;
//结构体test，存放测试用例，n存放整数个数，num数组存放整数
struct test
{
	int n = 0;
	int num[2000] = { 0 };
};
//函数phOrder，对一个测试用例排序，使得上镜数对数量最大。只需要把奇数全排在前面输出，偶数全排在后面输出即可。
void phOrder(test sample)
{
	for (int i = 0; i < sample.n; i++)
		if (sample.num[i] % 2 != 0)
			cout << sample.num[i] << '\t';
	for (int i = 0; i < sample.n; i++)
		if (sample.num[i] % 2 == 0)
			cout << sample.num[i] << '\t';
	cout << endl;
}
int main()
{
	//接收测试用例数t，生成t个测试用例
	int t = 0;
	cin >> t;
	test* sample = new test[t];
	//录入t个测试用例
	for (int i = 0; i < t; i++)
	{
		cin >> sample[i].n;
		for (int j = 0; j < sample[i].n; j++)
		{
			cin >> sample[i].num[j];
		}
	}
	for (int i = 0; i < t; i++)
	{
		phOrder(sample[i]);
	}
	delete[]sample;
	return 0;
}