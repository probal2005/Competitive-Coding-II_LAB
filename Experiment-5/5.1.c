#include <stdio.h>

#define MAX_SIZE 100

void printSubset(int subset[], int size) {
    printf("{ ");

    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }

    printf("}\n");
}

void backtrack(
    int nums[],
    int n,
    int index,
    int current[],
    int currentSize,
    int* total
) {
    // Add the current subset to the result
    printSubset(current, currentSize);
    (*total)++;

    for (int i = index; i < n; i++) {
        // Include nums[i]
        current[currentSize] = nums[i];

        // Generate subsets using remaining elements
        backtrack(
            nums,
            n,
            i + 1,
            current,
            currentSize + 1,
            total
        );

        // Backtracking happens when the recursive call returns
    }
}

int main(void) {
    int nums[] = {1, 2, 3};
    int n = (int)(sizeof(nums) / sizeof(nums[0]));

    int current[MAX_SIZE];
    int total = 0;

    printf("Input Array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n\nAll Possible Subsets:\n");

    backtrack(nums, n, 0, current, 0, &total);

    printf("\nTotal Number of Subsets: %d\n", total);

    return 0;
}
