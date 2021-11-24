#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>

#define int long long

const int MAXN = 2005;

using namespace std;

int n, a[MAXN], b[MAXN], c[MAXN], t;
#define COL 16//宽
#define ROW 30//长
#define MINE_NUM 60//雷数
#define SIZE 25//图片大小
#define IMAGE_NUM 14//图片数量

int map[ROW + 2][COL + 2];//+2是添加了辅助区，用来防止数组越界。
int count = 0;
IMAGE img[IMAGE_NUM];


//生成雷
int gameInit()
{
	srand((unsigned)time(NULL));
	//初始化格子
	for (int row = 0; row < ROW + 2; row++)
	{
		for (int col = 0; col < COL + 2; col++)
		{
			map[row][col] = 0;
		}
	}
	//生成雷
	for (int n = 0; n < MINE_NUM;)
	{
		int row = rand() % ROW + 1;
		int col = rand() % COL + 1;
		if (map[row][col] == 0)
		{
			map[row][col] = -1;
			n++;
		}
	}
	//遍历数组，找空格
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			if (map[i][j] != -1)
			{
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] == -1)
						{
							map[i][j]++;
						}
					}
				}
			}
		}
	}
	//加密
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			map[i][j] += 20;
		}
	}
}
//打印游戏区
void gameDraw()
{
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			printf("%3d", map[i][j]);
			//贴雷
			if (map[i][j] == -1)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[11]);
			}
			//贴数字
			else if (map[i][j] >= 0 && map[i][j] <= 8)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[map[i][j]]);
			}
			//贴空白
			else if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[9]);
			}
			//标记
			else if (map[i][j] >= 39 && map[i][j] <= 48)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[10]);
			}
			//贴问号
			else if (map[i][j] >= 59 && map[i][j] <= 68)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[12]);
			}
			//贴炸雷
			else if (map[i][j] == -2)
			{
				putimage((i - 1) * SIZE, (j - 1) * SIZE, &img[13]);
			}
		}
		printf("\n");
	}
}
//加载图片
void image()
{
	for (int i = 0; i < IMAGE_NUM; i++)
	{
		char fileName[20] = "";
		sprintf(fileName, "./image/%d.gif", i);
		loadimage(&img[i], fileName, SIZE, SIZE);
	}
}

signed main(void) {

    cin >> t;
    while (t--) {
        cin >> n;
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0)b[++x] = a[i];
            else c[++y] = a[i];
        }
        for (int i = 1; i <= x; i++)cout << b[i] << " ";
        for (int i = 1; i <= y; i++)cout << c[i] << " ";
        puts("");
    }

    return 0;
}
