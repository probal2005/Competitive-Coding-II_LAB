import java.util.HashMap;
import java.util.Map;

class Solution
{
    public boolean containsNearbyDuplicate(int[] nums, int k)
    {
        Map<Integer, Integer> lastSeen = new HashMap<>();

        for (int i = 0; i < nums.length; i++)
        {
            // Check if the number was seen before
            if (lastSeen.containsKey(nums[i]))
            {
                if (i - lastSeen.get(nums[i]) <= k)
                {
                    return true;
                }
            }

            // Store or update the latest index
            lastSeen.put(nums[i], i);
        }

        return false;
    }
}

class Main
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();

        int[] nums = {1, 2, 3, 1};
        int k = 3;

        boolean result = solution.containsNearbyDuplicate(nums, k);

        System.out.println("Contains Nearby Duplicate: " + result);
    }
}
