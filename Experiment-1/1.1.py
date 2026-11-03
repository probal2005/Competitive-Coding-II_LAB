class Solution:
    def containsNearbyDuplicate(self, nums, k):
        lastSeen = {}

        for i in range(len(nums)):
            # Check if the number was seen before
            if nums[i] in lastSeen:
                if i - lastSeen[nums[i]] <= k:
                    return True

            # Store or update the latest index
            lastSeen[nums[i]] = i

        return False


def main():
    solution = Solution()

    nums = [1, 2, 3, 1]
    k = 3

    result = solution.containsNearbyDuplicate(nums, k)

    print("Contains Nearby Duplicate:", str(result).lower())


if __name__ == "__main__":
    main()
