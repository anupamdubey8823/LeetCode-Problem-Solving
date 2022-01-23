class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> lonely;
        for (auto &num: nums) {
            mp[num]++;
        }
        for (auto &num: nums) {
            if (!mp.count(num-1) && !mp.count(num+1) && mp[num] == 1)
                lonely.emplace_back(num);
        }
        return lonely;
    }
};