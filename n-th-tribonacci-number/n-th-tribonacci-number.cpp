class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1;
        if (n == 0) return first;
        else if (n == 1) return second;
        else if (n == 2) return third;
        for (int i = 3; i <= n; i++) {
            int temp = third;
            third += first + second;
            first = second;
            second = temp;
        }
        return third;
    }
};