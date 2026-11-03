#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxArea = 0;
        int n = static_cast<int>(heights.size());

        for (int i = 0; i <= n; i++)
        {
            int currentHeight;

            if (i == n)
            {
                currentHeight = 0;
            }
            else
            {
                currentHeight = heights[i];
            }

            while (!st.empty() && heights[st.top()] > currentHeight)
            {
                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - st.top() - 1;
                }

                int area = height * width;
                maxArea = max(maxArea, area);
            }

            if (i < n)
            {
                st.push(i);
            }
        }

        return maxArea;
    }
};

int main()
{
    Solution solution;

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = solution.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}
