#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int countT1 = 0, countM1 = 0, countT2 = 0, countM2 = 0, countT3 = 0, countM3 = 0;
        int  n, x1 = 0;
        cin >> n;
        char a[100005];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 'T')
            {
                countT1++;
            }
            else
            {
                countM1++;
            }
            if (countT1 < countM1)
            {
                cout << "no" << endl;
                x1 = 1;
                break;
            }
        }
        if (x1 == 1)
        {
            continue;
        }
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] == 'T')
            {
                countT2++;
            }
            else
            {
                countM2++;
            }
            if (countT2 < countM2)
            {
                cout << "no" << endl;
                x1 = 1;
                break;
            }
        }
        if (x1 == 1)
        {
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 'T')
            {
                countT3++;
            }
            else
            {
                countM3++;
            }
        }
        if (countT3 == 2 * countM3)
        {
            cout << "yes" << endl;
            continue;
        }
        else
        {
            cout << "no" << endl;
            continue;
        }
    }

    return 0;
}