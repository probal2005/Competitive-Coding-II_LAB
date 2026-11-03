#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int frogJump(int n, vector<int>& height) {
    if (n <= 1) {
        return 0;
    }

    vector<int> dp(n, 0);

    // Base case: zero energy is needed at the first stair.
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        // Jump one stair.
        int jumpOne = dp[i - 1] +
                      abs(height[i] - height[i - 1]);

        // Jump two stairs, if possible.
        int jumpTwo = 0;

        if (i >= 2) {
            jumpTwo = dp[i - 2] +
                      abs(height[i] - height[i - 2]);
        }

        if (i == 1) {
            dp[i] = jumpOne;
        } else {
            dp[i] = min(jumpOne, jumpTwo);
        }
    }

    return dp[n - 1];
}

int main() {
    vector<int> height = {10, 20, 30, 10};
    int n = static_cast<int>(height.size());

    int result = frogJump(n, height);

    cout << "Number of Stairs: " << n << '\n';

    cout << "Stair Heights: [";
    for (int i = 0; i < n; i++) {
        cout << height[i];

        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    cout << "Minimum Energy Required: " << result << '\n';

    return 0;
}
