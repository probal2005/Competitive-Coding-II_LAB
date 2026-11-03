class Solution {
    public int addDigits(int num) {
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
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int num = 38;
        int result = solution.addDigits(num);

        System.out.println("Input: " + num);
        System.out.println("Add Digits: " + result);
    }
}
