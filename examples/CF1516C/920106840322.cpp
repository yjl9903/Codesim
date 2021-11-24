#include<iostream>
using namespace std;

int main(){
	int n,sum=0,a[105];
    bool b[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
        cin>>a[i];
		sum+=a[i];
	}
	if(sum&1){
		cout<<"0";
		return 0;
	}
	sum/=2;
	b[0]=1;
	for(int i=1;i<=n;i++)
	{
	    for(int j=sum;j>=a[i];j--)
        {
			b[j]|=b[j-a[i]];
		}
	}
	if(!b[sum])
	{
		cout<<"0";
		return 0;
	}
	int l=1e5,tmp=0;
	for(int i=1;i<=n;i++)
	{
		int f=a[i],h=0;
		while(!(f&1))
		{
			f>>=1;
			h++;
		}
		if(h<l) l=h,tmp=i;
	}
	cout<<1<<endl<<tmp;
	return 0;
}
