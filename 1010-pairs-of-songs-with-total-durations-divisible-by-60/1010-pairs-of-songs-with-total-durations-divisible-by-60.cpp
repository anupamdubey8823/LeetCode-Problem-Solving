class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> mp;
        int cnt = 0;
        for (auto &tim: time) {
            int num = tim % 60;
            if (num == 0) cnt += mp[0];
            else cnt += mp[60 - num];
            mp[num]++;
        }
        return cnt;
    }
};