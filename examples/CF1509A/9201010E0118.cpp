#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<assert.h>
#include<set>
#include<ctime>
#include<queue>

using namespace std;
#define M 2005
#define N
#define MP make_pair
#define debug() cerr<<"Why So Serious?"
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

template<class T>
void Rd(T &x) {
    x = 0;
    char c;
    while (c = getchar(), c < 48);
    do x = (x << 1) + (x << 3) + (c ^ 48);
    while (c = getchar(), c > 47);
}
int n;
int A[M];
int main() {
    int _;
    for(Rd(_);_;_--) {
        Rd(n);
        for(int i=1;i<=n;++i)Rd(A[i]);
        for(int i=1;i<=n;++i)if(A[i]&1)printf("%d ",A[i]);
        for(int i=1;i<=n;++i)if(!(A[i]&1))printf("%d ",A[i]);
        puts("");
    }
    return 0;
}
