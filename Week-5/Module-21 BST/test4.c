#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("User Input : a = %d, b = %d\n", a, b);

    a = a + b;

    b = a - b;

    a = a - b;

    printf("After swap Value :a = %d, b = %d\n", a, b);

    return 0;
}
