#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = solution.coinChange(coins, amount);

    cout << "Coins: [";
    for (size_t i = 0; i < coins.size(); i++) {
        cout << coins[i];
        if (i + 1 < coins.size()) {
            cout << ", ";
        }
    }

    cout << "]\n";
    cout << "Amount: " << amount << '\n';
    cout << "Minimum Number of Coins: " << result << '\n';

    return 0;
}
