class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while (sum > 9) {
            int digitSum = 0;
            int n = sum;
            while (n != 0) {
                int d = n % 10;
                digitSum += d;
                n /= 10;
            }
            sum = digitSum;
        }
        return sum;
    }
};