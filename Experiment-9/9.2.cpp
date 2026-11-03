#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = static_cast<int>(text1.size());
        int n = static_cast<int>(text2.size());

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;

    string text1 = "abcde";
    string text2 = "ace";

    int result = solution.longestCommonSubsequence(text1, text2);

    cout << "First String: " << text1 << '\n';
    cout << "Second String: " << text2 << '\n';
    cout << "Longest Common Subsequence Length: " << result << '\n';

    return 0;
}
