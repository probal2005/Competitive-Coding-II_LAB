import java.util.Stack;

class Solution
{
    public int largestRectangleArea(int[] heights)
    {
        Stack<Integer> st = new Stack<>();
        int maxArea = 0;
        int n = heights.length;

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

            while (!st.empty() && heights[st.peek()] > currentHeight)
            {
                int height = heights[st.pop()];
                int width;

                if (st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - st.peek() - 1;
                }

                int area = height * width;
                maxArea = Math.max(maxArea, area);
            }

            if (i < n)
            {
                st.push(i);
            }
        }

        return maxArea;
    }
}

class Main
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();

        int[] heights = {2, 1, 5, 6, 2, 3};

        int result = solution.largestRectangleArea(heights);

        System.out.println("Largest Rectangle Area: " + result);
    }
}
