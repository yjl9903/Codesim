#include <iostream>

using namespace std;

int main() 
{
	int t,n;
	int num[100000];
	int sum=0,chance=0;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		cin>>n;
		for (int j=0;j<n;j++)
		{
			cin>>num[j];
			sum+=num[j];
		}
		
		if ((n-sum)>0) chance=1;
		else chance=sum-n;
		
		cout<<chance<<endl;
		
		chance=0;sum=0; 
	}
	return 0;
}
