#include<bits/stdc++.h>

using namespace std;

bool JudgeOushu (int x)
{
	if (x%2==0) return true;
	else return false;
}

int Qiuhe (int num[],int len)
{
	int sum=0;
	for (int i=1;i<=len;i++)
	{
		sum+=num[i];
	}
	return sum;
}

bool Shuzujiou (int num[],int len)
{
	bool judge=true;
	for (int i=1;i<=len;i++)
	{
		if (num[i]%2==1) judge=false; //break;
	}
	if (judge==true) return true;
	else return false;
}

/*int SearchJishu (int num[],int len)
{
	int place=0;
	for (int i=1;i<=len;i++)
	{
		if (num[i]%2==1) 
		{
			place=i;
			break;
		}
	}
	return place;
}*/

bool Judgeshuzu (int num[],int len)
{
	bool whether;
	
	if (JudgeOushu(Qiuhe(num,len))==false)
		whether=true;
	else
	{
		while(1)
		{
			if (Shuzujiou(num,len)==false)
			{
				whether=false;
				break;
			} 
			else
			{
				for (int i=1;i<=len;i++)
				{
					num[i]=num[i]/2;
				}
				if (JudgeOushu(Qiuhe(num,len))==false)
				{
					whether=true;
					break;
				}
			}
		}	
	}	
	return whether;
} 
int main()
{
	int n;
	int shuzu[100000];
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>shuzu[i];
	}
	
	bool panduan=Judgeshuzu(shuzu,n);
	if (panduan==true) cout<<"0";
	else
	{
		for (int i=1;i<=n;i++)
		{
			int linshi=shuzu[i];
			shuzu[i]=0;
			panduan=Judgeshuzu(shuzu,n);
			if (panduan==true)
			{
				cout<<"1"<<endl<<i;
				break;
			}
			else shuzu[i]=linshi;
		}
	}
	
	return 0;	
} 
