class Solution {
    private void dfs(char[][] grid, int i, int j) {
        int m = grid.length;
        int n = grid[0].length;

        // Check boundaries and whether the cell is water.
        if (i < 0 || j < 0 || i >= m || j >= n ||
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

    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }

        int m = grid.length;
        int n = grid[0].length;
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
}

class Main {
    public static void main(String[] args) {
        char[][] grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        };

        Solution solution = new Solution();

        System.out.println(
            "Number of Islands: " + solution.numIslands(grid)
        );
    }
}
