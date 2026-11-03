#include <stdio.h>
#include <stdlib.h>

int coinChange(const int coins[], int coinCount, int amount) {
    if (amount < 0 || coinCount < 0) {
        return -1;
    }

    // dp[i] stores the minimum coins required to make amount i.
    int *dp = malloc(((size_t)amount + 1) * sizeof(int));

    if (dp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize all states as unreachable.
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    // Base case: zero coins are needed to make amount zero.
    dp[0] = 0;

    // Build the DP table.
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinCount; j++) {
            int coin = coins[j];

            if (coin > 0 && coin <= i) {
                int candidate = dp[i - coin] + 1;

                if (candidate < dp[i]) {
                    dp[i] = candidate;
                }
            }
        }
    }

    int result = (dp[amount] > amount) ? -1 : dp[amount];

    free(dp);
    return result;
}

int main(void) {
    int coins[] = {1, 2, 5};
    int coinCount = (int)(sizeof(coins) / sizeof(coins[0]));
    int amount = 11;

    int result = coinChange(coins, coinCount, amount);

    printf("Coins: [");
    for (int i = 0; i < coinCount; i++) {
        printf("%d", coins[i]);

        if (i + 1 < coinCount) {
            printf(", ");
        }
    }

    printf("]\n");
    printf("Amount: %d\n", amount);
    printf("Minimum Number of Coins: %d\n", result);

    return 0;
}
