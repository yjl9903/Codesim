#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int a[100]={0};
	int length=0; cin>>length;
	int sum=0;
	for(int i=0; i<length; i++)
	{
		cin>>a[i]; 
		sum+=a[i];	
	}
	if(sum%2) {cout<<"0"; return 0;}//第一种情况，数列有奇数个奇数，和为奇 
	
	int ans=0;
	for(int i=0; i<length; i++)
	{
		if(a[i]%2) 
		{
		    ans=i+1; 
			cout<<"1"<<endl<<ans; 
			return 0;
		}//第二种情况，数列有偶数个奇数，和为偶，直接删去一个奇数 
	}

	while(sum%2==0)	
	{
		sum=0;
		for(int i=0; i<length; i++)
		{
			a[i]/=2;
			sum+=a[i];
		} 
	}
	for(int i=0; i<length; i++)
	{
		if(a[i]%2) {ans=i+1; break;}
	}
	cout<<"1"<<endl<<ans; return 0;//第三种情况，数列无奇数，和为偶，连续除以2再删去奇数 
}
