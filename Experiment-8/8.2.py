class Solution:
    def frogJump(self, n: int, height: list[int]) -> int:
        if n <= 1:
            return 0

        # dp[i] stores the minimum energy to reach stair i.
        dp = [0] * n

        # Base case: zero energy is needed at the first stair.
        dp[0] = 0

        for i in range(1, n):
            # Jump one stair.
            jump_one = dp[i - 1] + abs(height[i] - height[i - 1])

            # Jump two stairs, if possible.
            jump_two = float("inf")

            if i >= 2:
                jump_two = dp[i - 2] + abs(height[i] - height[i - 2])

            dp[i] = min(jump_one, jump_two)

        return dp[n - 1]


if __name__ == "__main__":
    solution = Solution()

    height = [10, 20, 30, 10]
    n = len(height)

    result = solution.frogJump(n, height)

    print(f"Number of Stairs: {n}")
    print(f"Stair Heights: {height}")
    print(f"Minimum Energy Required: {result}")
