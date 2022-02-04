class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> targetPair;
        map<int, int> mp;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (mp.count(target-nums[i])) {
                targetPair.emplace_back(i);
                targetPair.emplace_back(mp[target-nums[i]]);
                break;
            }
            else
                mp[nums[i]] = i;
        }
        return targetPair;
    }
};