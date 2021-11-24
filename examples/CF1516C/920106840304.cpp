#include<bits/stdc++.h>
using namespace std;
bool p[200010];
int arr[150];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie();
	int n , sum = 0;
	cin >> n;
	p[0] = 1; 
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> arr[i];
		sum += arr[i];
		
	}
	for(int i = 0;i < n;i++)
	for(int j = sum ; j >= arr[i] ; j-- )
	    {
		     p[j] |= p[j - arr[i]];
	    }
	if(sum&1 || p[sum / 2] != 1)
	{
		cout << "0" << endl;
		return 0;
	}
	else cout << "1" << endl;
	int tt = 0;
    for(int i = 0; i<n;i++)
    {
    	if(arr[i] & 1) {cout << i + 1 <<endl; return 0;}
    	if( i == n - 1)
    	{
    		while(1)
    		{
    			for(int j = 0;j < n;j++)arr[j] /=2;
    			for(int j = 0;j < n;j++)
    			{
    				if(arr[j] & 1){cout << j + 1 <<endl; return 0;}
				}
			}
		}
	 } 
}
