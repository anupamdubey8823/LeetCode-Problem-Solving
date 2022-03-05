class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n+1, 0);
        for (int i = 0; i <= n; i++) {
            if (i == 0 || i == 1)
                stairs[i] = 1;
            else
                stairs[i] = stairs[i-1] + stairs[i-2];
        }
        return stairs[n];
    }
};