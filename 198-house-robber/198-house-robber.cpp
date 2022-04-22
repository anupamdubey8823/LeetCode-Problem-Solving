class Solution {
    int robUtil(vector<int> &nums, int robIndex, int len, vector<int> &maxMoney) {
        if (robIndex >= len)
            return 0;
        else if (robIndex == len-1)
            return nums[robIndex];
        if (maxMoney[robIndex] != -1)
            return maxMoney[robIndex];
        return maxMoney[robIndex] = max(nums[robIndex] + robUtil(nums, robIndex+2, len, maxMoney), robUtil(nums, robIndex+1, len, maxMoney));
    }
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> maxMoney(len, -1);
        return robUtil(nums, 0, len, maxMoney);
    }
};