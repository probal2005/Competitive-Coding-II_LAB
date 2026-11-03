#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void findCombinations(
        int ind,
        int target,
        vector<int>& arr,
        vector<vector<int>>& ans,
        vector<int>& ds
    ) {
        if (ind == static_cast<int>(arr.size())) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Include the current element if it does not exceed the target
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);

            // Reuse the same element
            findCombinations(ind, target - arr[ind], arr, ans, ds);

            // Backtrack
            ds.pop_back();
        }

        // Exclude the current element
        findCombinations(ind + 1, target, arr, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(0, target, candidates, ans, ds);

        return ans;
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution solution;
    vector<vector<int>> result =
        solution.combinationSum(candidates, target);

    cout << "Candidates: ";
    for (int num : candidates) {
        cout << num << " ";
    }

    cout << "\nTarget: " << target;
    cout << "\n\nCombination Sum Results:\n";

    for (const vector<int>& combination : result) {
        cout << "[ ";

        for (int num : combination) {
            cout << num << " ";
        }

        cout << "]\n";
    }

    cout << "\nTotal Combinations: " << result.size() << endl;

    return 0;
}
