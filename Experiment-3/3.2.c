#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(const int heights[], int n) {
    if (heights == NULL || n <= 0) {
        return 0;
    }

    int* stack = malloc((size_t)n * sizeof(int));

    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];

        while (top >= 0 &&
               currentHeight < heights[stack[top]]) {
            int height = heights[stack[top--]];

            int width = (top == -1)
                ? i
                : i - stack[top] - 1;

            int area = height * width;

            if (area > maxArea) {
                maxArea = area;
            }
        }

        if (i < n) {
            stack[++top] = i;
        }
    }

    free(stack);
    return maxArea;
}

int main(void) {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = (int)(sizeof(heights) / sizeof(heights[0]));

    int result = largestRectangleArea(heights, n);

    printf("Histogram: [");

    for (int i = 0; i < n; i++) {
        printf("%d", heights[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\n");
    printf("Largest Rectangle Area: %d\n", result);

    return 0;
}
