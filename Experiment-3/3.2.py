class Solution:
    def largestRectangleArea(self, heights):
        st = []
        maxArea = 0
        n = len(heights)

        for i in range(n + 1):
            # Use zero as the final sentinel height
            if i == n:
                currentHeight = 0
            else:
                currentHeight = heights[i]

            # Calculate areas for taller bars
            while st and heights[st[-1]] > currentHeight:
                height = heights[st.pop()]

                if not st:
                    width = i
                else:
                    width = i - st[-1] - 1

                area = height * width
                maxArea = max(maxArea, area)

            # Do not push the sentinel index
            if i < n:
                st.append(i)

        return maxArea


def main():
    solution = Solution()

    heights = [2, 1, 5, 6, 2, 3]

    result = solution.largestRectangleArea(heights)

    print("Largest Rectangle Area:", result)


if __name__ == "__main__":
    main()
