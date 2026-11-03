#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestCommonSubsequence(const char *text1, const char *text2) {
    int m = (int)strlen(text1);
    int n = (int)strlen(text2);

    // Allocate the DP table.
    int **dp = malloc((size_t)(m + 1) * sizeof(int *));

    if (dp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= m; i++) {
        dp[i] = calloc((size_t)(n + 1), sizeof(int));

        if (dp[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(dp[j]);
            }

            free(dp);
            exit(EXIT_FAILURE);
        }
    }

    // Build the DP table.
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                int top = dp[i - 1][j];
                int left = dp[i][j - 1];

                dp[i][j] = (top > left) ? top : left;
            }
        }
    }

    int result = dp[m][n];

    // Release allocated memory.
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }

    free(dp);

    return result;
}

int main(void) {
    const char *text1 = "abcde";
    const char *text2 = "ace";

    int result = longestCommonSubsequence(text1, text2);

    printf("First String: %s\n", text1);
    printf("Second String: %s\n", text2);
    printf("Longest Common Subsequence Length: %d\n", result);

    return 0;
}
