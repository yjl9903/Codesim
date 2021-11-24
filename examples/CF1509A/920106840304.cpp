#include<bits/stdc++.h>
using namespace std;
int arr[2500],b[2500],c[2500];
int count,j,cc;
int main ()
{
	int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	for(int i = 0;i<n;i++)
    	   cin>>arr[i];
    	int r=0,s=0;
        for(int i = 0;i<n;i++)
        {
        	if(arr[i] % 2 == 1) b[r++]=arr[i];
        	if(arr[i] % 2 == 0) c[s++]=arr[i];
		}
		for(int i=0; i<s ;i++)
		{
			b[r++] = c[i];
		}
		for(int i = 0; i<n ;i++)
		{
			if(i == n-1) cout<<b[i]<<endl;
			else cout<<b[i]<<" ";
		}
    	for(int i=0 ;i<n ;i++)
    	 {
    	 	arr[i]=0;
    	 	b[i]=0;
    	 	c[i]=0; 
    	 	
		 }
	}
	return 0;
 } 
