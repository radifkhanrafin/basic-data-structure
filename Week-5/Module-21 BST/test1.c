#include <stdio.h>
int main()
{
    int n, newValue, location;
    scanf("%d", &n);

    int list[n + 1];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    printf("Previous List :");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }

    scanf("%d %d", &location, &newValue);

    for (int i = n; i >= location; i--)
    {
        list[i] = list[i - 1];
    }

    list[location - 1] = newValue;
    printf("\n");
    printf("After Insert New Value :");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", list[i]);
    }
    return 0;
}
