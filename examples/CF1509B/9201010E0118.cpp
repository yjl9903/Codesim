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
#define M 100005
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
char str[M];
int n;
bool Check(){
    int sum=0;
    int s=0;
    for(int i=0;i<n;++i){
        s+=(str[i]=='T')?1:-1;
        if(s<0)return 0;
        sum+=str[i]=='M';
    }
    if(sum!=n/3)return 0;
    s=0;
    for(int i=n-1;~i;--i){
        s+=(str[i]=='T')?1:-1;
        if(s<0)return 0;
    }
    return 1;
}
int main() {
    int _;
    for(Rd(_);_;_--){
        Rd(n);
        scanf("%s",str);
        puts(Check()?"YES":"NO");
    }
    return 0;
}
