#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdint.h>

struct HashEntry {
    int key;
    size_t last_index;
    int occupied;
};

static uint32_t hashInt(int value) {
    uint32_t x = (uint32_t)value;

    x ^= x >> 16;
    x *= UINT32_C(0x7feb352d);
    x ^= x >> 15;
    x *= UINT32_C(0x846ca68b);
    x ^= x >> 16;

    return x;
}

int containsNearbyDuplicate(const int nums[], size_t n, int k) {
    if (nums == NULL || n < 2 || k <= 0) {
        return 0;
    }

    if (n > (SIZE_MAX - 1) / 2) {
        return 0;
    }

    size_t capacity = (2 * n) + 1;

    if (capacity > SIZE_MAX / sizeof(struct HashEntry)) {
        return 0;
    }

    struct HashEntry* table =
        (struct HashEntry*)calloc(capacity, sizeof(struct HashEntry));

    if (table == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n; i++) {
        size_t slot = (size_t)hashInt(nums[i]) % capacity;

        while (table[slot].occupied &&
               table[slot].key != nums[i]) {
            slot = (slot + 1) % capacity;
        }

        if (table[slot].occupied) {
            if (i - table[slot].last_index <= (size_t)k) {
                free(table);
                return 1;
            }
        } else {
            table[slot].occupied = 1;
            table[slot].key = nums[i];
        }

        table[slot].last_index = i;
    }

    free(table);
    return 0;
}

int main(void) {
    int nums[] = {1, 2, 3, 1};
    int k = 3;

    size_t n = sizeof(nums) / sizeof(nums[0]);

    int result = containsNearbyDuplicate(nums, n, k);

    printf(
        "Contains Nearby Duplicate: %s\n",
        result ? "true" : "false"
    );

    return 0;
}
