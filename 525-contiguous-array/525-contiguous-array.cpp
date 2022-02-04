class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0, sum = 0;
        int len = nums.size();
        unordered_map<int, int> seen = {{0, -1}};
        for (int i = 0; i < len; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (seen.count(sum))
                maxLength = max(maxLength, i - seen[sum]);
            else
                seen[sum] = i;
        }
        return maxLength;
    }
};