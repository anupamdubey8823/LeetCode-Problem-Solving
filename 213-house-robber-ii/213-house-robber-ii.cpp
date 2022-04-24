class Solution {
    int robUtil(vector<int> &nums, int robIndex, int endIndex, vector<vector<int>> &maxRobDP, int firstOrLast) {
        if (robIndex > endIndex)
            return 0;
        
        if (robIndex == endIndex)
            return nums[robIndex];
        
        if (maxRobDP[firstOrLast][robIndex] != -1)
            return maxRobDP[firstOrLast][robIndex];
        
        return maxRobDP[firstOrLast][robIndex] = max(nums[robIndex] + robUtil(nums, robIndex+2, endIndex, maxRobDP, firstOrLast), robUtil(nums, robIndex+1, endIndex, maxRobDP, firstOrLast));
    }
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        vector<vector<int>> maxRobDP(2, vector<int>(len, -1));
        return max(robUtil(nums, 0, len-2, maxRobDP, 0), robUtil(nums, 1, len-1, maxRobDP, 1));
    }
};