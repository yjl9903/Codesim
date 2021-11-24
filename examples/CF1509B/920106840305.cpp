#include<iostream>

using namespace std;
int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt1 = 0,cnt2 = 0;
        for(int i = 0; i < n; i++)              // 先遍历一遍 顺便干掉不合理的状态
            if(s[i] == 'M')
                cnt1++;                         //cnt1计数M  cnt2计数T
            else
                cnt2++;
        if(cnt1*2 != cnt2)
            cout << "NO" << endl;
        else
        {
            int cnt = 0;
            int flag = 1;                       //标记
            for(int i = 0; i < n ; i++)
            {
                if(s[i] == 'M')
                    cnt--;                      //记录当前M前面的T数量
                else
                    cnt++;
                if(cnt < 0|| (cnt2 / 2) < cnt)  //不满足此条件则不合理 
                {
                    cout << "NO" << endl;
                    flag = 0;                   //标记一下
                    break;
                }
            }
            if(flag)
                cout << "YES" << endl;
        }
    }
}
