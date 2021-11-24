#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[101],n,sum=0,k=-1;
	bool f[200006];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(k==-1&&a[i]%2==1)
		k=i+1;
	}
	if(sum%2==1)				//如果和为奇数，则无须删除 
	cout<<"0"<<endl;
	else						//如果和为偶数
	{
		f[0]=1;						//背包判断(表示看不懂) 
		for(int i=1;i<=n;i++)
		for(int j=sum/2;j>=a[i];j--)
		f[j]|=f[j-a[i]];
		if(!f[sum/2])
		{
			cout<<"0"<<endl;
			return 0;
		}
		if(k!=-1)					//不全为偶数情况
		cout<<"1"<<endl<<k<<endl;
		else
		{
			int j=1024;
			for(;j>2;j=j/2)
			{
				for(int i=0;i<n;i++)
				{
					if(a[i]/j==0||a[i]%j!=0)
					break;
					else if(i==n-1)
					goto next;
				}
			}
			next:
				if((sum/j)%2==1)
				cout<<"0"<<endl;
				else
				{
					for(int i=0;i<n;i++)
					{
						a[i]/=j;
						if(a[i]%2==1)
						{
							k=i+1;
							break;
						}
					}
					cout<<"1"<<endl<<k<<endl;
				}	
		}
	}
	return 0; 
}
