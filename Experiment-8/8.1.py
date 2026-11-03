class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        a = 1
        b = 2

        for i in range(3, n + 1):
            c = a + b
            a = b
            b = c

        return b


if __name__ == "__main__":
    solution = Solution()

    n = 5
    result = solution.climbStairs(n)

    print(f"Number of Stairs: {n}")
    print(f"Distinct Ways: {result}")
