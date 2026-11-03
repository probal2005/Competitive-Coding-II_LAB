class Solution
{
    public int search(int[] nums, int target)
    {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // Target found
            if (nums[mid] == target)
            {
                return mid;
            }

            // Left half is sorted
            if (nums[left] <= nums[mid])
            {
                // Target is inside the sorted left half
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else
            {
                // Target is inside the sorted right half
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
}

class Main
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();

        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;

        int result = solution.search(nums, target);

        System.out.println("Search in Rotated Sorted Array: " + result);
    }
}
