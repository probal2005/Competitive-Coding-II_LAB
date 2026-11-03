#include <stdio.h>

int findDuplicate(const int nums[], int n) {
    if (nums == NULL || n < 2) {
        return -1;
    }

    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Find the intersection point.
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find the entrance to the cycle.
    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main(void) {
    int nums[] = {1, 3, 4, 2, 2};
    int n = (int)(sizeof(nums) / sizeof(nums[0]));

    int result = findDuplicate(nums, n);

    printf("Input: [");

    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\n");
    printf("Duplicate Number: %d\n", result);

    return 0;
}
