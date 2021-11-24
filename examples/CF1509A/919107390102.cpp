#include<iostream>
using namespace std;
int main()
{
    int t,n,a[200000];
    cin>>t;
    int i,j;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        cin>>a[j];
        for(j=0;j<n;j++)
        {
            if(a[j]%2!=0) cout<<a[j]<<" ";
        }
         for(j=0;j<n;j++)
        {
            if(a[j]%2==0) cout<<a[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
