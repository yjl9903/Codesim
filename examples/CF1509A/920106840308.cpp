#include <iostream>
using namespace std;
int main()
{
	int t,n,a[3000],b[3000],c[3000];
	cin>>t;
	for(int j=0,b1=0,c1=0;j<t;j++,b1=0,c1=0)
	{
		cin>>n; 
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0)
			{
				b[b1]=a[i];
				b1++;
			}
			else
			{
				c[c1]=a[i];
				c1++;
			}
		}
		for(int i=0;i<b1;i++)
		cout<<b[i]<<" ";
		for(int i=0;i<c1;i++)
		cout<<c[i]<<" ";
		cout<<endl;
	}
	// 
//   你再干嘛 xunhuan  哦哦 那也得循环两遍嘛  wodongle
//	这不就是二维数组？
//	二维数组占空间啊，你就一个一维数组不就节省空间了 
//  你说的很有道理不过。。给我整不会了。。。。我想想冥想会。 就这？。。。？？？？/ 
//  我可以用奇数和偶数判断吗？  对呀 还挺难小东C 为啥编译不了  算了   暴跳如雷了xdm 

	return 0;
	
} 
