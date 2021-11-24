#include <iostream>
using namespace std;
#define N 2005
int n;
int count,num,num1[N],num2[N];
int main()
{
	int i,j,k=0,h=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>count;
		{
			for(j=1;j<=count;j++)
			{
				cin>>num;
				if(num%2==0)
				num1[++k]=num;
				else
				num2[++h]=num;
			}
			for(j=1;j<=h;j++)
			cout<<num2[j]<<" ";
			for(j=1;j<=k;j++)
			cout<<num1[j]<<" ";
			cout<<endl;
			h=0,k=0;
		}
	}
	
 } 
