#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());

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

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
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
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    Solution solution;

    cout << "Number of Islands: "
         << solution.numIslands(grid) << '\n';

    return 0;
}
