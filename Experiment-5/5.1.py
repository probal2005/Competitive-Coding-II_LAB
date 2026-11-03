class Solution:
    def subsets(self, nums):
        result = []
        current = []

        def backtrack(index):
            # Add the current subset
            result.append(current.copy())

            for i in range(index, len(nums)):
                # Include nums[i]
                current.append(nums[i])

                # Generate subsets using remaining elements
                backtrack(i + 1)

                # Backtrack: remove the last element
                current.pop()

        backtrack(0)

        return result


def main():
    nums = [1, 2, 3]

    solution = Solution()
    result = solution.subsets(nums)

    print("Input Array:", *nums)

    print("\nAll Possible Subsets:")

    for subset in result:
        print("{ " + " ".join(map(str, subset)) + " }")

    print("\nTotal Number of Subsets:", len(result))


if __name__ == "__main__":
    main()
