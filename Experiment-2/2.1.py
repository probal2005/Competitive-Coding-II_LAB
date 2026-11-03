class Solution:
    def searchInsert(self, nums, target):
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left


def main():
    solution = Solution()

    nums = [1, 3, 5, 6]
    target = 5

    result = solution.searchInsert(nums, target)

    print("Search Insert Position:", result)


if __name__ == "__main__":
    main()
