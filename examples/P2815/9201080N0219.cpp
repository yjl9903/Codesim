#include <iostream>
using namespace std;
int main() 
{
    string IPv6, result;
    cin >> IPv6;
    IPv6 = ':' + IPv6;
    for (int i = 0; i < IPv6.length() - 2; i++)
        if (IPv6[i] == ':' && IPv6[i + 1] == '0' && IPv6[i + 2] != ':')
        {
            IPv6.erase(i + 1, 1);
            i--;
        }
    int count = 0, max = 0, maxIndex = 0, flag = 0;
    for (int i = 0; i < IPv6.length() - 1; i++)
    {
        if (IPv6[i] == ':' && IPv6[i + 1] == '0')
        {
            count++;
            i++;
        }
        else
        {
            count = 0;
        }
        if (max < count)
        {
            max = count;
            maxIndex = i - 2 * max + 2;
        }
    }
    if (max != 0)
        IPv6.replace(maxIndex, max * 2, ":");
    IPv6.erase(0,1);
    if (maxIndex == 1)
        IPv6 = ':' + IPv6;
    cout << IPv6 << endl;
    return 0;
}