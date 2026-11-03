#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void printCombination(int ds[], int size) {
    printf("[ ");

    for (int i = 0; i < size; i++) {
        printf("%d ", ds[i]);
    }

    printf("]\n");
}

void findCombinations(
    int ind,
    int target,
    int arr[],
    int n,
    int ds[],
    int dsSize,
    int* total
) {
    if (ind == n) {
        if (target == 0) {
            printCombination(ds, dsSize);
            (*total)++;
        }
        return;
    }

    // Include the current element if it does not exceed the target
    if (arr[ind] <= target) {
        ds[dsSize] = arr[ind];

        // Reuse the same element
        findCombinations(
            ind,
            target - arr[ind],
            arr,
            n,
            ds,
            dsSize + 1,
            total
        );

        // Backtracking happens when the recursive call returns
    }

    // Exclude the current element
    findCombinations(
        ind + 1,
        target,
        arr,
        n,
        ds,
        dsSize,
        total
    );
}

int main(void) {
    int candidates[] = {2, 3, 6, 7};
    int target = 7;

    int n = (int)(sizeof(candidates) / sizeof(candidates[0]));
    int ds[MAX_SIZE];
    int total = 0;

    printf("Candidates: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", candidates[i]);
    }

    printf("\nTarget: %d", target);
    printf("\n\nCombination Sum Results:\n");

    findCombinations(
        0,
        target,
        candidates,
        n,
        ds,
        0,
        &total
    );

    printf("\nTotal Combinations: %d\n", total);

    return 0;
}
