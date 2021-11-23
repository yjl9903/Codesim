#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char IP;
char ip[50];
int num[10];
int p1=0,p2=0,pp2,pp1;
void work(int x)
{
    if(num[x]==0&&x!=8)
    {
        printf("0:");return;
    }
    else if(num[x]==0&&x==8)
    {
        printf("0");return;
    }
    int cnt=1;
    while(num[x]<1000)
    {
        num[x]*=10;
        cnt++;
    }
    for(int i=cnt;i<=4;++i)
    printf("%c",ip[(x-1)*5+i]);
    if(x!=8&&x+1!=pp1)
    {
        printf(":");
    }
}
int main()
{
    int sum=0,t=0;
    for(int i=1;i<=39;++i)
    {
        IP=getchar();
        ip[i]=IP;
        if(IP==':')
        {
            num[++t]=sum;
            sum=0;
            continue;
        }
        if(IP<='z'&&IP>='a')
        sum=sum*10+IP-'a'+1;
        else
        sum=sum*10+IP-'0';
    }
    num[++t]=sum;
    int maxlen=0;
    for(int i=1;i<=8;++i)
    {
        if(num[i]==0)
        {
            if(p1==0)
            p1=p2=i;
            else
            p2=i;
            if(p2-p1+1>maxlen)
            {
                maxlen=p2-p1+1;
                pp1=p1;
                pp2=p2;
            }
        }
        else
        p1=p2=0;
    }
    for(int i=1;i<=8;++i)
    {
        if(i==pp1)
        {
            printf("::");i=pp2;
            continue;
        }
        if(num[i]<1000)
        {
            work(i);continue;
        }
        for(int j=(i-1)*5+1;j<=(i-1)*5+4;j++)
        printf("%c",ip[j]);
        if(i!=8&&i+1!=pp1)
        printf(":");
    }
}
