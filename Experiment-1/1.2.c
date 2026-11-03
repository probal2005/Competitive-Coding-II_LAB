#include <stdio.h>
#include <stdlib.h>

void productExceptSelf(
    const int nums[],
    int result[],
    int n
) {
    int prefix = 1;

    // Calculate prefix products.
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Calculate suffix products.
    int suffix = 1;

    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
}

int main(void) {
    int nums[] = {1, 2, 3, 4};
    int n = (int)(sizeof(nums) / sizeof(nums[0]));

    int* result = malloc((size_t)n * sizeof(int));

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    productExceptSelf(nums, result, n);

    printf("Input:  [");

    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\nOutput: [");

    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\n");

    free(result);

    return EXIT_SUCCESS;
}
