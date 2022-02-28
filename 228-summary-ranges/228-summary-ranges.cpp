class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return {};
        string range = "";
        vector<string> summary;
        int start, end;
        for (int i = 0; i < len; i++) {
            start = end = i;
            while (end < len-1 && nums[end] + 1 == nums[end+1])
                end++;
            if (start == end) 
                range = to_string(nums[end]);
            else 
                range = to_string(nums[start]) + "->" + to_string(nums[end]);
            summary.emplace_back(range);
            range = "";
            i = end;
        }
        return summary;
    }
};