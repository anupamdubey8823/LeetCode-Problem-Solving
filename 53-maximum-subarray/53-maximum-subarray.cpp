class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN, len = nums.size();
        // [-3,-2,-1]
        for (int i = 0; i < len; i++) {
            currSum += nums[i];
            // if (currSum > 0)
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};