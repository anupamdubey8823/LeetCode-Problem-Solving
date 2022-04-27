class Solution {
public:
    int jump(vector<int>& nums) {
        // Greedy Approach - O(N) time and O(1) space.
        int maxReachable = 0, left = 0, right = 0, minJumps = 0, len = nums.size();
        while (right < len - 1) {
            for (int i = left; i <= right; i++) {
                maxReachable = max(maxReachable, i + nums[i]);
            }
            left = right+1;
            right = maxReachable;
            minJumps++; // Each time we are updating our range i.e. jump from one range to the next. Hence increasing minJumps;
        }
        return minJumps;
    }
};