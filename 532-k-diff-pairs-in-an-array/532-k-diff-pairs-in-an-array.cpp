class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto &num: nums) {
            freq[num]++;
        }
        int pairs = 0;
        for (auto &key: freq) {
            if ((k > 0 && freq.count(key.first + k)) || (k == 0 && key.second > 1))
                pairs++;
        }
        return pairs;
    }
};