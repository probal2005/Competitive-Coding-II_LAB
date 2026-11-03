class Solution {
    public int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int a = 1;
        int b = 2;

        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int n = 5;
        int result = solution.climbStairs(n);

        System.out.println("Number of Stairs: " + n);
        System.out.println("Distinct Ways: " + result);
    }
}
