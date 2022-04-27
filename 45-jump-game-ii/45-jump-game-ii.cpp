class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, left = 0, right = 0, minJumps = 0, len = nums.size();
        while (right < len - 1) {
            for (int i = left; i <= right; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            left = right+1;
            right = farthest;
            minJumps++;
        }
        return minJumps;
    }
};