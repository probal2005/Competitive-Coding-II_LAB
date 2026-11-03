class Solution:
    def search(self, nums, target):
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            # Target found
            if nums[mid] == target:
                return mid

            # Left half is sorted
            if nums[left] <= nums[mid]:
                # Target is inside the sorted left half
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1

            # Right half is sorted
            else:
                # Target is inside the sorted right half
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1


def main():
    solution = Solution()

    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 0

    result = solution.search(nums, target)

    print("Search in Rotated Sorted Array:", result)


if __name__ == "__main__":
    main()
