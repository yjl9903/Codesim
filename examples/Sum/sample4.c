#include <stdio.h>

int main()
{
    int n, c;
    scanf("%d", &n);
    c = 0;
    for(int i = 1; i <= n; ++i)
    {
        int b;
        scanf("%d", &b);
        c += b;
    }
    printf("%d\n", c);
    return 0;
}