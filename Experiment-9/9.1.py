class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        # dp[i] stores the minimum coins required to make amount i.
        dp = [amount + 1] * (amount + 1)

        # Base case: zero coins are needed to make amount zero.
        dp[0] = 0

        # Build the DP table.
        for i in range(1, amount + 1):
            for coin in coins:
                if 0 < coin <= i:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return -1 if dp[amount] > amount else dp[amount]


if __name__ == "__main__":
    solution = Solution()

    coins = [1, 2, 5]
    amount = 11

    result = solution.coinChange(coins, amount)

    print(f"Coins: {coins}")
    print(f"Amount: {amount}")
    print(f"Minimum Number of Coins: {result}")
