#include <iostream>   
using namespace std;
char a[39];
int maxi=-1,maxn=1;
void find ()          
{
    int x,y,t;
    bool ok;
    for (x=0,t=0;x<8;x++)
    {
        ok=true;
        for (y=0;y<4;y++)
        {
            if (a[x*5+y]!='0')
            {
                ok=false;    
                break;
            }
        }
        if (ok) 
        {
        	t++;          
            if (t>maxn) 
            {
                maxn=t;
                maxi=x;
            }
        }
        else t=0;           
    }
    if (maxn==1)
		maxi=-1;    
    maxi=maxi-maxn+1;
} 
int main ()
{
    scanf("%s",a);
    find();
    int i1,i2;
    for (i1=0;i1<8;i1++)
    {
        if (maxi==i1)        
        {
            cout<<":";
            if (i1==0) cout<<":";
            i1=i1+maxn;
            if (i1>7) 
				break;
        }
        i2=0;
        while (a[i1*5+i2]=='0'&&i2<3)
			    i2++;  
        for (;i2<4;i2++)
        { 
            cout<<a[i1*5+i2];
        }
        if (i2==4&&i1!=7)
			cout<<":";   
    }
	cout<<endl;
	system("pause");
    return 0;
}