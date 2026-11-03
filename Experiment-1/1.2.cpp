#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);

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
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = solution.productExceptSelf(nums);

    cout << "Product Except Self: ";

    for (int value : result)
    {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}
