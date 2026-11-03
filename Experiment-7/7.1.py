class Solution:
    def addDigits(self, num: int) -> int:
        while num >= 10:
            digit_sum = 0

            while num > 0:
                digit_sum += num % 10
                num //= 10

            num = digit_sum

        return num


if __name__ == "__main__":
    solution = Solution()

    num = 38
    result = solution.addDigits(num)

    print(f"Input: {num}")
    print(f"Add Digits: {result}")
