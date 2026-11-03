#include <stdio.h>
#include <stdlib.h>

int frogJump(int n, const int height[]) {
    if (n <= 1) {
        return 0;
    }

    int dp[n];

    // Base case: zero energy is needed at the first stair.
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        // Jump one stair.
        int jumpOne = dp[i - 1] +
                      abs(height[i] - height[i - 1]);

        // Jump two stairs, if possible.
        int jumpTwo = 0;

        if (i >= 2) {
            jumpTwo = dp[i - 2] +
                      abs(height[i] - height[i - 2]);
        }

        if (i == 1) {
            dp[i] = jumpOne;
        } else {
            dp[i] = (jumpOne < jumpTwo) ? jumpOne : jumpTwo;
        }
    }

    return dp[n - 1];
}

int main(void) {
    int height[] = {10, 20, 30, 10};
    int n = (int)(sizeof(height) / sizeof(height[0]));

    int result = frogJump(n, height);

    printf("Number of Stairs: %d\n", n);

    printf("Stair Heights: [");
    for (int i = 0; i < n; i++) {
        printf("%d", height[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\n");
    printf("Minimum Energy Required: %d\n", result);

    return 0;
}
