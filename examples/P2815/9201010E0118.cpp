#include <assert.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
#define M
#define N
#define MP make_pair
#define debug() cerr << "Why So Serious?"
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

template <class T>
void Rd(T &x) {
  x = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do x = (x << 1) + (x << 3) + (c ^ 48);
  while (c = getchar(), c > 47);
}
char A[45];
bool check_zero(char *a) {
  for (int i = 0; i < 4; ++i)
    if (a[i] != '0') return 0;
  return 1;
}
int main() {
  scanf("%s", A);
  int len = 0;
  int nowlen = 0;
  int rpos = -1;
  for (int i = 0, j = 0; i < 39; i += 5, ++j) {
    if (check_zero(A + i)) {
      nowlen++;
    } else {
      if (nowlen > len) {
        rpos = j - 1;
        len = nowlen;
      }
      nowlen = 0;
    }
  }
  if (nowlen > len) {
    len = nowlen;
    rpos = 7;
  }
  for (int i = 0, j = 0; i < 39; i += 5, j++) {
    if (j > rpos - len && j <= rpos) {
      if (!j) printf(":");
      if (j == rpos) printf(":");
      continue;
    }
    int st = 0;
    while (st < 3 && A[i + st] == '0') st++;
    for (int k = st; k < 4; ++k) printf("%c", A[i + k]);
    printf("%c", j == 7 ? '\n' : ':');
  }
  return 0;
}
