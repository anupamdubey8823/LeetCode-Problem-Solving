class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int k = 0, len = intervals.size();
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] <= merged[k][1])
                merged[k][1] = max(intervals[i][1], merged[k][1]);
            else {
                merged.push_back(intervals[i]);
                k++;
            }
        }
        return merged;
    }
};