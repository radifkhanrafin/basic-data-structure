#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("User Input : a = %d, b = %d\n", a, b);

    a = a + b;

    b = a - b;

    a = a - b;

    // with 3rd variable 
    // int tmp=a;
    // a=b;
    // b=tmp;

    printf("After swap Value :a = %d, b = %d\n", a, b);

    return 0;
}
