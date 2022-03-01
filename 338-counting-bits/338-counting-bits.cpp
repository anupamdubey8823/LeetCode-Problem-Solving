class Solution {
    int findOnesCount(int num) {
        int ones = 0;
        while (num != 0 && num != 1) {
            if (num % 2 == 1)
                ones++;
            num /= 2;
        }
        if (num == 1) return ones + 1;
        return ones;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int ones = findOnesCount(i);
            ans.emplace_back(ones);
        }
        return ans;
    }
};