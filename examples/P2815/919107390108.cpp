//ipv6地址压缩    模拟
#include <bits/stdc++.h>
using namespace std;

char str[29];//一串39个字符的字符串，代表一个完全展开的IPv6地址
char ans[29];//答案字符串
int main() {
	cin >> str;
	/*
	分析：对目标串进行检测，
	每次遇到冒号：时flag=true，然后检测后面是否有0，若为0，则删除
	遇到非零数时，将flag=false,再遇到0不删除，直到再次遇到冒号
	*/
	//希望自己能感觉到自己时刻在进步
	bool flag = true;
	int j = 0;
	for (int i = 0; i < 29; i++) {
		if (flag && str[i] == '0') {
			continue;
		} else
			ans[j++] = str[i];
		if (str[i] != '0' && str[i] != ':')
			flag = false;
		if (str[i] = ':')
			flag = true;

	}

	//将多余的0删除完毕后，再遍历ans数组，将多余的冒号不输出
	int count = 0;
	for (int j = 0; j < strlen(str); j++) {
		if (str[j] != ':')  {
			cout << str[j];
			count = 0;  //对冒号计数清零
		} else {
			count++;
			if (count <= 2)
				cout << str[j];
			else
				continue;
		}
	}
	return 0;
}