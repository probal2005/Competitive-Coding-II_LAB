class Solution:
    def findCombinations(self, ind, target, arr, ans, ds):
        if ind == len(arr):
            if target == 0:
                ans.append(ds.copy())
            return

        # Include the current element if it does not exceed the target
        if arr[ind] <= target:
            ds.append(arr[ind])

            # Reuse the same element
            self.findCombinations(
                ind,
                target - arr[ind],
                arr,
                ans,
                ds
            )

            # Backtrack
            ds.pop()

        # Exclude the current element
        self.findCombinations(
            ind + 1,
            target,
            arr,
            ans,
            ds
        )

    def combinationSum(self, candidates, target):
        ans = []
        ds = []

        self.findCombinations(0, target, candidates, ans, ds)

        return ans


def main():
    candidates = [2, 3, 6, 7]
    target = 7

    solution = Solution()
    result = solution.combinationSum(candidates, target)

    print("Candidates:", *candidates)
    print("Target:", target)

    print("\nCombination Sum Results:")

    for combination in result:
        print(combination)

    print("\nTotal Combinations:", len(result))


if __name__ == "__main__":
    main()
