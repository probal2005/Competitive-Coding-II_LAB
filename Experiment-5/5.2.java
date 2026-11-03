import java.util.ArrayList;
import java.util.List;

class Solution {
    private void findCombinations(
        int ind,
        int target,
        int[] arr,
        List<List<Integer>> ans,
        List<Integer> ds
    ) {
        if (ind == arr.length) {
            if (target == 0) {
                ans.add(new ArrayList<>(ds));
            }
            return;
        }

        // Include the current element if it does not exceed the target
        if (arr[ind] <= target) {
            ds.add(arr[ind]);

            // Reuse the same element
            findCombinations(
                ind,
                target - arr[ind],
                arr,
                ans,
                ds
            );

            // Backtrack
            ds.remove(ds.size() - 1);
        }

        // Exclude the current element
        findCombinations(
            ind + 1,
            target,
            arr,
            ans,
            ds
        );
    }

    public List<List<Integer>> combinationSum(
        int[] candidates,
        int target
    ) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();

        findCombinations(0, target, candidates, ans, ds);

        return ans;
    }
}

class Main {
    public static void main(String[] args) {
        int[] candidates = {2, 3, 6, 7};
        int target = 7;

        Solution solution = new Solution();
        List<List<Integer>> result =
            solution.combinationSum(candidates, target);

        System.out.print("Candidates: ");

        for (int num : candidates) {
            System.out.print(num + " ");
        }

        System.out.println("\nTarget: " + target);
        System.out.println("\nCombination Sum Results:");

        for (List<Integer> combination : result) {
            System.out.println(combination);
        }

        System.out.println(
            "\nTotal Combinations: " + result.size()
        );
    }
}
