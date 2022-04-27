class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size(), lastReachable = len-1;
        for (int i = len-1; i >= 0; i--) {
            if (i + nums[i] >= lastReachable)
                lastReachable = i;
        }
        return lastReachable == 0;
    }
};