#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d", &a);
    b = 0;
    for(int c = 1; c <= a; ++c)
    {
        int d;
        scanf("%d", &d);
        b = b + d;
    }
    printf("%d\n", b);
    return 0;
}