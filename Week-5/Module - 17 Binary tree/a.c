#include <stdio.h>
int main()
{
    int a, b, c, big;
    scanf("%d %d %d", &a, &b, &c);

    if (a > b && a > c)
    {
        big = a;
    }
    else if (b > a && b > c)
    {
        big = b;
    }
    else if (c > a && c > b)
    {
        big = c;
    }

    printf("%d", big);

    return 0;
}