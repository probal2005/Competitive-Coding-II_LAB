#include <stdio.h>

#define ROWS 4
#define COLS 5

void dfs(char grid[ROWS][COLS], int i, int j) {
    // Check boundaries and whether the cell is water.
    if (i < 0 || j < 0 || i >= ROWS || j >= COLS ||
        grid[i][j] == '0') {
        return;
    }

    // Mark the visited land cell as water.
    grid[i][j] = '0';

    // Visit all four adjacent directions.
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(char grid[ROWS][COLS]) {
    int count = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main(void) {
    char grid[ROWS][COLS] = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    printf("Number of Islands: %d\n", numIslands(grid));

    return 0;
}
