class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size(), start, end;
        string range = "";
        vector<string> summary;

        for (int i = 0; i < len; ) {
            start = end = i;
            while (end < len-1 && nums[end] + 1 == nums[end+1])
                end++;
            if (start == end) 
                range = to_string(nums[end]);
            else 
                range = to_string(nums[start]) + "->" + to_string(nums[end]);
            summary.emplace_back(range);
            range = "";
            i = end + 1;
        }
        return summary;
    }
};