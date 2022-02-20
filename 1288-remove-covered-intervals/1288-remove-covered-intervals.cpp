class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        int lower = intervals[0][0], upper = intervals[0][1];
        int remIntervals = 1;
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] > lower && intervals[i][1] > upper) 
                remIntervals++;
            if (intervals[i][1] > upper) {
                lower = intervals[i][0];
                upper = intervals[i][1];
            }
        }
        return remIntervals;
    }
};