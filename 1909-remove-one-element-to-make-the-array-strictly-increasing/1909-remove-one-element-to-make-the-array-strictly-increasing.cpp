class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int numsLen = nums.size(), decreasingFreq = 0, arrChanges = 0;
        for (int i = 1; i < numsLen; i++) {
            if (nums[i-1] >= nums[i]) {
                if (decreasingFreq == 1)
                    return false;
                decreasingFreq++;
                // Next step is to replace the ith element if it is even smaller than i-2th element.
                // Because it would be no point in keeping the ith element.
                // Rather keep the i-1 th to increase the possibility of the array being strictly increasing.
                if (i > 1 && nums[i-2] >= nums[i])
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};