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
#define M
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
int dp[100005];
int A[105];
int main() {
    Rd(n);
    int sum=0;
    for(int i=1;i<=n;++i)Rd(A[i]),sum+=A[i];
    dp[0]=1;
    if(sum&1){
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;++i){
        for(int j=sum/2-A[i];j>=0;--j){
            if(dp[j])dp[j+A[i]]=1;
        }
    }
    if(!dp[sum/2]){
        puts("0");
        return 0;
    }
    puts("1");
    int mi=1e9,id=-1;
    for(int i=1;i<=n;++i){
        int x=A[i];
        int c=0;
        while(!(x&1)){
            c++;
            x/=2;
        }
        if(c<mi){
            mi=c;
            id=i;
        }
    }
    printf("%d\n",id);
    return 0;
}
