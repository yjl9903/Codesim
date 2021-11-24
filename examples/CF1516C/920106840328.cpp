#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int Maxn = 110;
const int Maxm = 200010;
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>

#define COL 16//宽
#define ROW 30//长
#define MINE_NUM 60//雷数
#define SIZE 25//图片大小
#define IMAGE_NUM 14//图片数量

int map[ROW+2][COL+2];//+2是添加了辅助区，用来防止数组越界。
int count = 0;
IMAGE img[IMAGE_NUM];

bool f[Maxm];
int a[Maxn];
int n, m;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], m += a[i];
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= a[i]; --j)
			f[j] |= f[j - a[i]];
	if ((m & 1) || !f[m >> 1])
	{
		puts("0"); return 0;
	}
	int ans = 60, pos;
	for (int i = 1; i <= n; ++i)
	{
		int tmp = 0;
		for (int j = 30; j >= 0; --j)
			if (a[i] % (1 << j) == 0) { tmp = j; break; }
		if (tmp < ans)ans = tmp, pos = i;
	}
	cout << "1" << "/n" << pos;
	return 0;
}
