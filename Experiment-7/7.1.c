#include <stdio.h>

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

int main(void) {
    int num = 38;
    int result = addDigits(num);

    printf("Input: %d\n", num);
    printf("Add Digits: %d\n", result);

    return 0;
}
