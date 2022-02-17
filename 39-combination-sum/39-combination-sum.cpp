class Solution {
    void combinationUtil(int index, vector<int> &candidates, int target, vector<int> &subArr, vector<vector<int>> &subArrWrapper) {
        int len = candidates.size();

        if (target == 0) {
            subArrWrapper.emplace_back(subArr);
            // subArr.clear();
            return;
        }
        
        if (index >= len)
            return;
        
        for (int i = index; i < len; i++) {
            if (candidates[i] <= target) {
                subArr.emplace_back(candidates[i]);
                combinationUtil(i, candidates, target-candidates[i], subArr, subArrWrapper);
                subArr.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> subArrWrapper;
        vector<int> subArr;
        combinationUtil(0, candidates, target, subArr, subArrWrapper);
        return subArrWrapper;
    }
};