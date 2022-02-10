class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixSum;
        int len = nums.size(), cumulativeSum = 0, subarrays = 0;
        prefixSum[0]++;
        for (int i = 0; i < len; i++) {
            cumulativeSum += nums[i];
            subarrays += prefixSum[cumulativeSum - k];
            prefixSum[cumulativeSum]++;
        }
        return subarrays;
    }
};