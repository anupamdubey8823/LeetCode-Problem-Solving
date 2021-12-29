class Solution {
    int climbUtil(int n, vector<int> &steps) {
        if (n == 0 || n == 1)
            return 1;
        if (steps[n] != -1)
            return steps[n];
        return steps[n] = climbUtil(n-1, steps) + climbUtil(n-2, steps);
    }
public:
    int climbStairs(int n) {
        vector<int> steps(n+1, -1);
        return climbUtil(n, steps);
    }
};