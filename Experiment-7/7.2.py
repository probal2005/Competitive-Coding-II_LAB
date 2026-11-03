class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        # Phase 1: Find the intersection point.
        slow = nums[0]
        fast = nums[0]

        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]

            if slow == fast:
                break

        # Phase 2: Find the entrance to the cycle.
        slow = nums[0]

        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]

        return slow


if __name__ == "__main__":
    solution = Solution()

    nums = [1, 3, 4, 2, 2]
    result = solution.findDuplicate(nums)

    print(f"Input: {nums}")
    print(f"Duplicate Number: {result}")
