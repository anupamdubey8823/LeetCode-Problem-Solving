class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN, currMin = 0, minSum = INT_MAX;
        int numsLen = nums.size(), arrSum = 0;
        for (int i = 0; i < numsLen; i++) {
            // No-Wrap around case: Answer lies in [0, numsLen-1]. This is normal case of Kadane's Algo.
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0) currSum = 0;
            
            // Wrap Around case: Answer lies in circular subarray. We apply reverse Kadane's. Where we find out minSum in the array. Eg. [1,2,-4,-8,9]. Here answer is [1,2][9] which is circular subarray. Here, minSum = [-4,-8]. So to get [1,2][9] as answer we subtract [-4,-8] from total array thus getting our answer.
            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(minSum, currMin);
            
            arrSum += nums[i];
        }
        return (maxSum > 0 )? max(maxSum, arrSum - minSum) : maxSum;
        // Return maxSum itself if its < 0 because it means that all elements are negative in the array. 
        // Above holds true because if there's is even one positive element in the array, our maxSum would detect it.
    }
};