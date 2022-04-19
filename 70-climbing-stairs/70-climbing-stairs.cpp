class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 1, currentStep = second;
        for (int i = 2; i <= n; i++) {
            currentStep = first + second;
            int temp = second;
            second = currentStep;
            first = temp;
        }
        return second;
    }
};