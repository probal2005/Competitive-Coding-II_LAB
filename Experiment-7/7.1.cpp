#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            num = sum;
        }

        return num;
    }
};

int main() {
    Solution solution;

    int num = 38;
    int result = solution.addDigits(num);

    cout << "Input: " << num << '\n';
    cout << "Add Digits: " << result << '\n';

    return 0;
}
