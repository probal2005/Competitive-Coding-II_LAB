class Solution {
    public int findDuplicate(int[] nums) {
        // Phase 1: Find the intersection point.
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle.
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums = {1, 3, 4, 2, 2};

        int result = solution.findDuplicate(nums);

        System.out.print("Input: [");

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]);

            if (i < nums.length - 1) {
                System.out.print(", ");
            }
        }

        System.out.println("]");
        System.out.println("Duplicate Number: " + result);
    }
}
