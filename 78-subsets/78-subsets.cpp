class Solution {
    void subsetUtil(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& uniqSubsets) {
        int len = nums.size();
        if (index >= len) {
            uniqSubsets.emplace_back(subset);
            return;
        }
        subsetUtil(index+1, nums, subset, uniqSubsets);
        subset.emplace_back(nums[index]);
        subsetUtil(index+1, nums, subset, uniqSubsets);
        subset.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> uniqSubsets;
        subsetUtil(0, nums, subset, uniqSubsets);
        return uniqSubsets;
    }
};