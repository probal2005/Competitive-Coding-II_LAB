#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find the intersection point.
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
};

int main() {
    Solution solution;

    vector<int> nums = {1, 3, 4, 2, 2};

    int result = solution.findDuplicate(nums);

    cout << "Input: [";

    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];

        if (i + 1 < nums.size()) {
            cout << ", ";
        }
    }

    cout << "]\n";
    cout << "Duplicate Number: " << result << '\n';

    return 0;
}
