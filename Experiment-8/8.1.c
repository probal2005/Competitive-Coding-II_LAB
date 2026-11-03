#include <stdio.h>

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }

    int a = 1;
    int b = 2;

    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main(void) {
    int n = 5;
    int result = climbStairs(n);

    printf("Number of Stairs: %d\n", n);
    printf("Distinct Ways: %d\n", result);

    return 0;
}
