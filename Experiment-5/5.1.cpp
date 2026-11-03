#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(nums, 0, current, result);

        return result;
    }

private:
    void backtrack(
        vector<int>& nums,
        int index,
        vector<int>& current,
        vector<vector<int>>& result
    ) {
        // Add the current subset
        result.push_back(current);

        for (int i = index; i < static_cast<int>(nums.size()); ++i) {
            // Include nums[i]
            current.push_back(nums[i]);

            // Generate subsets using the remaining elements
            backtrack(nums, i + 1, current, result);

            // Backtrack: remove the last element
            current.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution solution;
    vector<vector<int>> result = solution.subsets(nums);

    cout << "Input Array: ";
    for (int num : nums) {
        cout << num << " ";
    }

    cout << "\n\nAll Possible Subsets:\n";

    for (const vector<int>& subset : result) {
        cout << "{ ";

        for (int num : subset) {
            cout << num << " ";
        }

        cout << "}\n";
    }

    cout << "\nTotal Number of Subsets: " << result.size() << endl;

    return 0;
}
