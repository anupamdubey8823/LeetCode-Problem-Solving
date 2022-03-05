class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> count(n);
//         Segregating which elements in the array can give max how much points when all duplicates clubbed together
//         Eg - [1, 2, 2, 2, 3, 3]. Here, 1 can give 1 point, 2 can give 6 points, 3 can give 6 points
        for (int &num: nums)
            count[num] += num;
        vector<int> maxPoints(n);
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == 1)
                maxPoints[i] = count[i];
            else
                maxPoints[i] = max(count[i] + maxPoints[i-2], maxPoints[i-1]);
        }
        return maxPoints[n-1];
    }
};