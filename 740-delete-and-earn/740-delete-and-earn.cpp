class Solution {
    int maxPoints(vector<int> &nums, int index, vector<int> &count, vector<int> &maxPointsDP) {
        if (index >= count.size())
            return 0;
        
        if (maxPointsDP[index] != -1)
            return maxPointsDP[index];
        
        return maxPointsDP[index] = max(maxPoints(nums, index+2, count, maxPointsDP) + count[index], maxPoints(nums, index+1, count, maxPointsDP));
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int maxIndex = maxNum + 1;
        vector<int> count(maxIndex, 0);
        for (auto &num: nums)
            count[num]++;
        for (int i = 0; i < maxIndex; i++) {
            count[i] = count[i] * i;
        }
        vector<int> maxPointsDP(maxIndex, -1);
        return maxPoints(nums, 0, count, maxPointsDP);
    }
};