class Solution {
    public int coinChange(int[] coins, int amount) {
        // dp[i] stores the minimum coins required to make amount i.
        int[] dp = new int[amount + 1];

        // Initialize all states as unreachable.
        for (int i = 0; i <= amount; i++) {
            dp[i] = amount + 1;
        }

        // Base case: zero coins are needed to make amount zero.
        dp[0] = 0;

        // Build the DP table.
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin > 0 && coin <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] coins = {1, 2, 5};
        int amount = 11;

        int result = solution.coinChange(coins, amount);

        System.out.print("Coins: [");

        for (int i = 0; i < coins.length; i++) {
            System.out.print(coins[i]);

            if (i + 1 < coins.length) {
                System.out.print(", ");
            }
        }

        System.out.println("]");
        System.out.println("Amount: " + amount);
        System.out.println("Minimum Number of Coins: " + result);
    }
}
