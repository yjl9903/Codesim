#include <iostream >
#include <memory.h>
using namespace std;



	int T;
int n;
int main ()
{

	cin>>T;
	char str[T][100];
	for(int i = 0 ;i<T;i++)
	{
		str[i][100]={0};
		cin>>n;
		for(int j = 0;j<n;j++)
		{
			cin>>str[i][j];
		}
		
	}
	
	return 0;
}
/*void show (char a[][100])
{
	for(int i = 0 ;i<T;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
}*/
 
