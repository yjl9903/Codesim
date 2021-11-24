#include <iostream>
#include <algorithm>
using namespace std;
int n, ans;
int a[1001];
int f[1001][1001];

int main() {
	cin >> n;   //数组a的长度
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	//对序列做最大公约数的除法
	int gc = a[1];
	for (int i = 1; i <= n; i++) {
		gc = __gcd(gc, a[i]);  //求a的最大公约数
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		a[i] /= gc;
		sum += a[i];
	}

	//若sum的值为奇数，则说明原序列是好的
	if (sum % 2 )  {
		cout << "0" << endl;
		return 0;
	}


	//若sum的值为偶数，则先用背包法判断原序列是否可分
	//初始化状态矩阵f
	for (int j = 0; j <= sum / 2; j++)
		f[0][j] = 0;
	for (int i = 0; i <= n; i++)
		f[i][0] = 0;
	//状态转化
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum / 2; j++) {
			if (a[i] > j)
				f[i][j] = f[i - 1][j];
			else {
				f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + a[i]);
			}
		}
	}

//如果f[n][sum/2]刚好可以装满达到sum/2，则说明原序列不好
//此时只要删去原序列中的一个奇数即可
	if (f[n][sum / 2] == sum / 2) {
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2 == 1) {
				cout << "1" << endl << i << endl;
				break;
			}
		}
	}
	//否则，原序列是好的
	else {
		cout << "0" << endl;
	}
	return 0;
}



