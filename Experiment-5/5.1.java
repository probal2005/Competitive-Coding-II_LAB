import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();

        backtrack(nums, 0, current, result);

        return result;
    }

    private void backtrack(
        int[] nums,
        int index,
        List<Integer> current,
        List<List<Integer>> result
    ) {
        // Add the current subset
        result.add(new ArrayList<>(current));

        for (int i = index; i < nums.length; i++) {
            // Include nums[i]
            current.add(nums[i]);

            // Generate subsets using remaining elements
            backtrack(nums, i + 1, current, result);

            // Backtrack: remove the last element
            current.remove(current.size() - 1);
        }
    }
}

class Main {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3};

        Solution solution = new Solution();
        List<List<Integer>> result = solution.subsets(nums);

        System.out.print("Input Array: ");

        for (int num : nums) {
            System.out.print(num + " ");
        }

        System.out.println("\n\nAll Possible Subsets:");

        for (List<Integer> subset : result) {
            System.out.println("{ " +
                subset.stream()
                      .map(String::valueOf)
                      .reduce((a, b) -> a + " " + b)
                      .orElse("") +
                " }");
        }

        System.out.println("\nTotal Number of Subsets: " + result.size());
    }
}
