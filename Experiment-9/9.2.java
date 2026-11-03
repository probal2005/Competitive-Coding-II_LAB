class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        // dp[i][j] stores the LCS length of the first i and j characters.
        int[][] dp = new int[m + 1][n + 1];

        // Build the DP table.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(
                            dp[i - 1][j],
                            dp[i][j - 1]
                    );
                }
            }
        }

        return dp[m][n];
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        String text1 = "abcde";
        String text2 = "ace";

        int result = solution.longestCommonSubsequence(text1, text2);

        System.out.println("First String: " + text1);
        System.out.println("Second String: " + text2);
        System.out.println("Longest Common Subsequence Length: " + result);
    }
}
