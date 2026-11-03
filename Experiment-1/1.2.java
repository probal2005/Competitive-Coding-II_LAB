import java.util.Arrays;

class Solution
{
    public int[] productExceptSelf(int[] nums)
    {
        int n = nums.length;
        int[] answer = new int[n];

        // Prefix product
        int prefix = 1;

        for (int i = 0; i < n; i++)
        {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Suffix product
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
}

class Main
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();

        int[] nums = {1, 2, 3, 4};

        int[] result = solution.productExceptSelf(nums);

        System.out.println("Product Except Self: " + Arrays.toString(result));
    }
}
