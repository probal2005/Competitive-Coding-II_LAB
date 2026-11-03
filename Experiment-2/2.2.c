#include <stdio.h>

int search(const int nums[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main(void) {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int n = (int)(sizeof(nums) / sizeof(nums[0]));
    int target = 0;

    int result = search(nums, n, target);

    printf("Input: [");

    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\n");
    printf("Target: %d\n", target);
    printf("Search in Rotated Sorted Array: %d\n", result);

    return 0;
}
