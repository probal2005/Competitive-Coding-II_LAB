#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, size_t> lastSeen;

        for (size_t i = 0; i < nums.size(); i++)
        {
            // Check if the number was seen before
            if (lastSeen.find(nums[i]) != lastSeen.end())
            {
                if (i - lastSeen[nums[i]] <= static_cast<size_t>(k))
                {
                    return true;
                }
            }

            // Store or update the latest index
            lastSeen[nums[i]] = i;
        }

        return false;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    bool result = solution.containsNearbyDuplicate(nums, k);

    cout << "Contains Nearby Duplicate: "
         << (result ? "true" : "false") << endl;

    return 0;
}
