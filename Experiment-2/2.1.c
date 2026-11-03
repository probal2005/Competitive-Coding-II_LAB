#include <stdio.h>

int searchInsert(const int nums[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main(void) {
    int nums[] = {1, 3, 5, 6};
    int n = (int)(sizeof(nums) / sizeof(nums[0]));
    int target = 5;

    int result = searchInsert(nums, n, target);

    printf("Input: [");

    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\n");
    printf("Target: %d\n", target);
    printf("Search Insert Position: %d\n", result);

    return 0;
}
