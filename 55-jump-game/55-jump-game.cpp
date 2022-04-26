class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastReachablePosition = nums.size()-1;
        for (int i = lastReachablePosition; i >= 0; i--) {
            if (i+nums[i] >= lastReachablePosition)
                lastReachablePosition = i;
        }
        return lastReachablePosition == 0;
    }
};