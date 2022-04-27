class Solution {
    int jumpUtil(int index, vector<int> &nums, vector<int> &jumpsDP) {
        if (index >= nums.size()-1)
            return 0;
        if (jumpsDP[index] != INT_MAX-1)
            return jumpsDP[index];
        int minJumps = INT_MAX-1; // Safety Check for avoiding overflow if due to any condition(eg. nums=[0]) INT_MAX+1 had to be returned;
        for (int i = 1; i <= nums[index]; i++) {
            minJumps = min(jumpUtil(index+i, nums, jumpsDP), minJumps);
        }
        return jumpsDP[index] = minJumps + 1;
    }
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> jumpsDP(len, INT_MAX-1);
        return jumpUtil(0, nums, jumpsDP);
    }
};