#include <bits/stdc++.h>   //传说神奇的万能头文件
using namespace std;
char a[39];
int maxi=-1,maxn=1;
void find ()          //寻找最长"0000"字段函数 
{
    int i1,i2,t;
    bool ok;
    for (i1=0,t=0;i1<8;i1++)
    {
        ok=true;
        for (i2=0;i2<4;i2++)
        {
            if (a[i1*5+i2]!='0')
            {
                ok=false;    //如果有一个非0字符则跳出循环 
                break;
            }
        }
        if (ok) 
        {
        	t++;          //计数器 
            if (t>maxn) 
            {
                maxn=t;
                maxi=i1;
            }
        }
        else t=0;           
    }
    if (maxn==1) maxi=-1;    //windows和mac os压缩规则不一致 
    maxi=maxi-maxn+1;
} 
int main ()
{
    scanf("%s",a);
    find();
    int i1,i2;
    for (i1=0;i1<8;i1++)
    {
        if (maxi==i1)        //将最长字段压缩成“::” 
        {
            cout<<":";
            if (i1==0) cout<<":";
            i1=i1+maxn;
            if (i1>7) break;
        }
        i2=0;
        while (a[i1*5+i2]=='0'&&i2<3) i2++;  //处理全“0”字段
        for (;i2<4;i2++)
        { 
            cout<<a[i1*5+i2];
        }
        if (i2==4&&i1!=7) cout<<":";  //最后一个字段无需“：” 
    }
    return 0;
}