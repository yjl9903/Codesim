#include <iostream>

using namespace std;
int t, n, numT, numM, f = 1;
string a;
#define COL 16//宽
#define ROW 30//长
#define MINE_NUM 60//雷数
#define SIZE 25//图片大小
#define IMAGE_NUM 14//图片数量

int map[ROW + 2][COL + 2];//+2是添加了辅助区，用来防止数组越界。
int count = 0;

void blankOpen(int r, int c)
{
	//打开格子
	map[r][c] -= 20;
	//点开后遍历九宫格
	for (int m = r - 1; m <= r + 1; m++)
	{
		for (int n = c - 1; n <= c + 1; n++)
		{
			if (m >= 1 && m <= ROW && n >= 1 && n <= COL)			//保证是游戏区
			{
				if (map[m][n] >= 19 && map[m][n] <= 28)				//必须为空白格
				{
					if (map[m][n] != 20)
					{
						map[m][n] -= 20;
					}
					else
					{
						blankOpen(m, n);
					}
				}
			}
		}
	}
}
//左键点击已经点开的块，遍历周围的块
int open(int r, int c)
{
	int flag = 0;
	for (int m = r - 1; m <= r + 1; m++)
	{
		for (int n = c - 1; n <= c + 1; n++)
		{
			if (m >= 1 && m <= ROW && n >= 1 && n <= COL)			//保证是游戏区
			{
				if (map[m][n] == 19)
				{
					flag = 1;
				}
			}
		}
	}
	if (flag == 0)
	{
		for (int m = r - 1; m <= r + 1; m++)
		{
			for (int n = c - 1; n <= c + 1; n++)
			{
				if (map[m][n] >= 19 && map[m][n] <= 28)
				{
					map[m][n] -= 20;
					blankOpen(r, c);
				}

			}
		}
	}
	else if (flag == 1)
	{
		for (int m = r - 1; m <= r + 1; m++)
		{
			for (int n = c - 1; n <= c + 1; n++)
			{
				if (map[m][n] > 39 && map[m][n] <= 48)
				{
					return -1;
				}
			}
		}
	}
}
//输的时候显示所有雷
void boom()
{
	for (int r = 1; r <= ROW; r++)
	{
		for (int c = 1; c <= COL; c++)
		{
			if (map[r][c] == 19)
			{
				map[r][c] -= 21;
			}
			else if (map[r][c] == -1)
			{
				map[r][c] -= 1;
			}
		}
	}
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> a; a = " " + a;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 'T')numT++;
			if (a[i] == 'M')numM++;
			if (numT < numM) { f = 0; break; }
		}numT = 0, numM = 0;
		for (int i = n; i >= 1; --i) {
			if (a[i] == 'T')numT++;
			if (a[i] == 'M')numM++;
			if (numT < numM) { f = 0; break; }
		}
		if (f == 0 || numT != numM * 2)puts("NO");
		else puts("YES");
		numT = 0, numM = 0, f = 1;
	}
	return 0;
}
