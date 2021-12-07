#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        int b;
        scanf("%d", &b);
        ans += b;
    }
    printf("%d\n", ans);
    return 0;
}
