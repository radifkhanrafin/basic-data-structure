#include <stdio.h>

void fibonacci_Number(int n) {
    int start = 0, end = 1, next;

    printf("Fibonacci Series: ");
    
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            printf("%d ", start);
            continue;
        }
        if (i == 2) {
            printf("%d ", end);
            continue;
        }
        next = start + end;
        start = end;
        end = next;

        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        fibonacci_Number(n);
    }
    
    return 0;
}
