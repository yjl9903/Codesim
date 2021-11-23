#include<bits/stdc++.h>
using namespace std;
char ss[50];
char spart[10][10];
int flag[10]={0},flocation[10]={0},location0[10]={0},sum0[10]={0};
int main()
{
	int i,j,k1=0,k2=0,l=0;
	ss[0]=':';
	for(i=1;i<=39;i++)
	cin>>ss[i];
	ss[i]='\0';
	for(i=0;ss[i]!='\0';i++)
	{
		if(ss[i]==':')
		{
			k2=0;
			k1++;
			for(j=i+1;ss[j]!=':'&&ss[j]!='\0';j++)
			{
				spart[k1][k2++]=ss[j];
				if(spart[k1][k2-1]!='0'&&flag[k1]==0)
				{
					flag[k1]=1;
					flocation[k1]=k2-1;
				}
			}
			spart[k1][k2]='\0';
			i=j-1;
		}
	}
	for(i=1;i<=8;i++)
	{
		if(flag[i]==0)
		{
			location0[++l]=i;
			sum0[l]=1;
			for(j=i+1;flag[j]==0&&j<=8;j++)
			{
				sum0[l]+=1;
			}
		}
	}
	int max=sum0[1],lmax=1;
	for(i=1;i<=l;i++)
	{
		if(sum0[i]>max)
		{
			max=sum0[i];
			lmax=i;
		}
	}
	if(max==8)
	{
		cout<<"::";
		return 0;
	}
	for(i=1;i<=8;i++)
	{
		if(i!=1||flag[1]==0)
		cout<<":";
		if(flag[i]==1)
		{
			for(j=flocation[i];spart[i][j]!='\0';j++)
			cout<<spart[i][j];
		}
		else if(i==location0[lmax])
		{
			i=i+max-1;
		}
		else
		cout<<"0";
	}
}
