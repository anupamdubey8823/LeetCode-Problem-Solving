class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, numLen = nums.size();
        while (i+1 < numLen && nums[i] < nums[i+1])
            i++;
        if (i == numLen-1)
            return nums[0];
        return min(nums[0], nums[i+1]);
    }
};