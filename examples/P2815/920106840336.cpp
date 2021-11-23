#include<bits/stdc++.h> 
using namespace std;
char IP[10][5],zero;
bool eat[10];
int maxlen,maxloc,loc=1;
int main()
{
    for(int i=1;i<=8;i++)
    {
        int z=0;
        for(int j=1;j<=4;j++)
        {
            scanf("%c",&IP[i][j]);
            if(IP[i][j]=='0')z++;              
        }
        if(z==4)
        {    
            zero++;
            eat[i]=true;
        }
        if(z!=4||i==8)            
        {    
            if(zero>maxlen)             
            {    
                maxlen=zero;
                maxloc=loc;
            }
            zero=0;
            loc=i+1;
        }
        getchar();           
    }
    for(int i=1;i<=8;i++)
    {
        if(i==1&&maxloc==1)printf(":");                  
        if(i==maxloc){i+=maxlen-1;if(i==8)printf(":");}         
        else
        {
            for(int j=1;j<=4;j++)
            {
                if(j==1&&IP[i][j]=='0')while(IP[i][j]=='0'&&j<4)j++;        
                printf("%c",IP[i][j]);    
            }
        }
        if(i<8)printf(":");           
    }
    return 0;  
}
