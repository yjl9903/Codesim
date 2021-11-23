#include <bits/stdc++.h>

using namespace std;

int main() 
{
	char dizhi[39];
	
	for (int k=0;k<39;k++)
	{
		cin>>dizhi[k];
	} //完成初始地址的输入
	
	int sum;//全零字段计数器
	bool judge=true;//判断全零字段
	int maxzero=1;
	int place=-1;
	int i,j;
	
	for (i=0,sum=0;i<8;i++)
	{
		judge=true;
		for (j=0;j<4;j++)
		{
			if (dizhi[i*5+j] != '0')
			{
				judge=false;
				break;//已然不满足全零字段的条件，直接跳出此段循环 
			}
		}
		if (judge==true)//全零字段被计数
		{
			sum++;
			if (sum>maxzero)
			{
				maxzero=sum;
				place=i;
			} 
		}
		else sum=0;	
	}
	
	if (maxzero==1) place=-1;//此时没有可以压缩成“：：”的字段 
	place=place-maxzero+1;
	
	for (i=0;i<8;i++)
	{
		if (place==i)
		{
			cout<<":";
			if (i==0) cout<<":";
			i+=maxzero;
			if (i>7) break;
		}
		
		j=0;
		while (dizhi[i*5+j]=='0' && j<3)
		{
			j++;
		}
		
		while (j<4)//完成其余字段的输出 
		{
			cout<<dizhi[i*5+j];
			j++;
		}
		if (j==4 && i!=7) cout<<":";
	}
	return 0;
}
