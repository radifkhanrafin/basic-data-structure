#include <stdio.h>

int main()
{
    int n1 = 0, n2 = 1, next, terms, i;
    next = n1 + n2;
    printf("Enter the value of terms : ");
    scanf("%d", &terms);
    printf("Fibonacci Sequence  : %d %d ", n1, n2);
    for (i = 3; i <= terms; i++)
    {
        printf("%d ", next);
        n1 = n2;
        n2 = next;
        next = n1 + n2;
    }
    return 0;
}
