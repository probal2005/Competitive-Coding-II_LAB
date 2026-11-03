#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int a = 1, b = 2;

        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

int main() {
    Solution solution;

    int n = 5;
    int result = solution.climbStairs(n);

    cout << "Number of Stairs: " << n << '\n';
    cout << "Distinct Ways: " << result << '\n';

    return 0;
}
