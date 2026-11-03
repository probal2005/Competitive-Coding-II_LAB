class Solution:
    def dfs(self, grid, i, j):
        m = len(grid)
        n = len(grid[0])

        # Check boundaries and whether the cell is water.
        if (i < 0 or j < 0 or i >= m or j >= n
                or grid[i][j] == '0'):
            return

        # Mark the visited land cell as water.
        grid[i][j] = '0'

        # Visit all four adjacent directions.
        self.dfs(grid, i + 1, j)
        self.dfs(grid, i - 1, j)
        self.dfs(grid, i, j + 1)
        self.dfs(grid, i, j - 1)

    def numIslands(self, grid):
        if not grid or not grid[0]:
            return 0

        m = len(grid)
        n = len(grid[0])
        count = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    count += 1
                    self.dfs(grid, i, j)

        return count


if __name__ == "__main__":
    grid = [
        ['1', '1', '1', '1', '0'],
        ['1', '1', '0', '1', '0'],
        ['1', '1', '0', '0', '0'],
        ['0', '0', '0', '0', '0']
    ]

    solution = Solution()
    result = solution.numIslands(grid)

    print(f"Number of Islands: {result}")
