#include <bits/stdc++.h>
using namespace std;
string str, _str, s[10];
int coun0[10], counbite[10], flag0[10];
int main() {
  cin >> str;
  _str = "";
  int k = -1;
  str += ":";
  memset(counbite, 4, sizeof(counbite));
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == ':') {
      s[++k] = _str;
      _str = "";
      continue;
    }
    _str += str[i];
  }
  int flag = 0;
  //È«Áã
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] != '0') {
        flag = 1;
        break;
      }
      if (i == 7 && j == s[i].size() - 1) {
        cout << "::";
        return 0;
      }
    }
    if (flag == 1) {
      break;
    }
  }

  //Ç°µ¼Áã
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '0') {
        coun0[i]++;
      } else
        break;
    }
    if (coun0[i] > 0 && coun0[i] < 4) {
      for (int j = 0; j < 4; j++) {
        s[i][j] = s[i][j + coun0[i]];
        if (j + 1 > counbite[i] - coun0[i]) {
          counbite[i] = j;
          break;
        }
      }
    }
  }

  int begin = 0, last = 0;
  for (int i = 0; i < 8; i++) {
    // cout << coun0[i] << endl;
    if (coun0[i] == 4) {
      begin = i;
      for (int j = i; j < 8; j++) {
        if (i == 7 && coun0[i] == 4) {
          flag0[i] = 1;
          break;
        }
        if (coun0[j] != 4) {
          flag0[i] = j - i;
          break;
        }
        if (j == 7 && coun0[j] == 4 && i != 7) {
          flag0[i] = j - i + 1;
          break;
        }
      }
    }
  }
  int maxx = 1, kk = 10;
  for (int i = 0; i < 8; i++) {
    if (flag0[i] > maxx) {
      maxx = flag0[i];
      kk = i;
    }
  }
  // for(int j =0;j < 4;j++) cout << s[2][j];

  // cout << s[6] << endl;
  // for(int i =0;i < 8;i++) cout <<flag0[i]<<" " ;

  for (int i = 0; i < 8; i++) {
    if (flag0[i] == 0) {
      if (i != 7) {
        for (int j = 0; j < 4 - coun0[i]; j++) cout << s[i][j];
        cout << ":";

      } else {
        for (int j = 0; j < 4 - coun0[i]; j++) cout << s[i][j];
        return 0;
      }

    } else if (i != kk && flag0[i] != 0) {
      if (i != 7 & i + flag0[i] - 1 != 7) {
        for (int j = 0; j < flag0[i]; j++) {
          cout << "0"
               << ":";
        }

        i += flag0[i] - 1;
      } else if (i != 7 & i + flag0[i] - 1 == 7) {
        for (int j = 0; j < flag0[i] - 1; j++) {
          cout << "0"
               << ":";
        }
        cout << "0";
        return 0;
      } else {
        cout << "0";
        return 0;
      }
    } else if (i == kk) {
      if (i != 7) {
        if (i != 0) {
          cout << ":";
          i += flag0[i] - 1;
        } else {
          cout << "::";
          i += flag0[i] - 1;
        }
      } else {
        cout << ":";
        return 0;
      }
    }
  }
  return 0;
}
