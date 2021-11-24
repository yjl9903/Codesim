#include <bits/stdc++.h>
using namespace std;
char a[39];
int maxi = -1, maxn = 1;
void find() {
  int i, j, t;
  bool ok;
  for (i = 0, t = 0; i < 8; i++) {
    ok = true;
    for (j = 0; j < 4; j++) {
      if (a[i * 5 + j] != '0') {
        ok = false;
        break;
      }
    }
    if (ok) {
      t++;
      if (t > maxn) {
        maxn = t;
        maxi = i;
      }
    } else
      t = 0;
  }
  if (maxn == 1) maxi = -1;
  maxi = maxi - maxn + 1;
}
int main() {
  cin >> a;
  find();
  int i, j;
  for (i = 0; i < 8; i++) {
    if (maxi == i) {
      cout << ":";
      if (i == 0) cout << ":";
      i = i + maxn;
      if (i > 7) break;
    }
    j = 0;
    while (a[i * 5 + j] == '0' && j < 3) j++;
    for (; j < 4; j++) {
      cout << a[i * 5 + j];
    }
    if (j == 4 && i != 7) cout << ":";
  }
  return 0;
}
