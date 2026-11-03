class Solution {
    public int frogJump(int n, int[] height) {
        if (n <= 1) {
            return 0;
        }

        int[] dp = new int[n];

        // Base case: zero energy is needed at the first stair.
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            // Jump one stair.
            int jumpOne = dp[i - 1]
                    + Math.abs(height[i] - height[i - 1]);

            // Jump two stairs, if possible.
            int jumpTwo = Integer.MAX_VALUE;

            if (i >= 2) {
                jumpTwo = dp[i - 2]
                        + Math.abs(height[i] - height[i - 2]);
            }

            dp[i] = Math.min(jumpOne, jumpTwo);
        }

        return dp[n - 1];
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] height = {10, 20, 30, 10};
        int n = height.length;

        int result = solution.frogJump(n, height);

        System.out.println("Number of Stairs: " + n);

        System.out.print("Stair Heights: [");
        for (int i = 0; i < n; i++) {
            System.out.print(height[i]);

            if (i < n - 1) {
                System.out.print(", ");
            }
        }

        System.out.println("]");
        System.out.println("Minimum Energy Required: " + result);
    }
}
