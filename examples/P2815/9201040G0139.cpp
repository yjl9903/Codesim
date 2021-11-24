#include <iostream>
#include <string>
using namespace std;

void simplePrint(string p) {
  int GudgeIfAllZero(string p);
  int flag = 0;
  if (GudgeIfAllZero(p)) {
    cout << 0;
    return;
  }
  if (p[0] != '0')
    cout << p;
  else {
    for (int i = 0; i < p.length(); i++) {
      while (p[i] == '0' && flag == 0) i++;
      flag = 1;
      cout << p[i];
    }
  }
}
int GudgeIfAllZero(string p) {
  for (int i = 0; i < 4; i++)
    if (p[i] != '0') return 0;
  return 1;
}
int main() {
  string IPV6;
  cin >> IPV6;
  string IPV[8];
  ///*分割为8个字符串*/
  for (int i = 0, j = 0; i < IPV6.length(); i++) {
    if (IPV6[i] == ':') {
      j++;
      continue;
    } else
      IPV[j] += IPV6[i];
  }
  int flag = 9;  //不存在的位置，表示刚开始没有0
  /*判断flag位置*/
  int sum = 0;
  for (int i = 0; i < 8; i++) {
    int sum_temp = 0;
    if (GudgeIfAllZero(IPV[i])) {
      while (GudgeIfAllZero(IPV[i])) {
        sum_temp++;
        i++;
        if (i == 8) break;
      }
      i--;
      if (sum_temp > sum) {
        flag = i + 1 - sum_temp;
        sum = sum_temp;
      }
    }
  }
  if (flag == 0) {
    if (sum == 8) {
      cout << "::";
      return 0;
    } else {
      cout << "::";
      for (int i = sum; i < 8; i++) {
        simplePrint(IPV[i]);
        if (i != 7) cout << ":";
      }
    }
    return 0;
  }
  for (int i = 0; i < 8; i++) {
    if (i != flag) simplePrint(IPV[i]);
    if (i != 7 && i != flag) {
      cout << ":";
    } else if (i == flag) {
      cout << ":";
      i += sum - 1;
    }
  }
}