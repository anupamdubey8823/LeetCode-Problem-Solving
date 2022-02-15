class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> freq;
        for (auto &num:nums) {
            freq[num]++;
        }
        int singleNum = 0;
        for (auto &it: freq) {
            if (it.second == 1) singleNum = it.first;
        }
        return singleNum;
    }
};