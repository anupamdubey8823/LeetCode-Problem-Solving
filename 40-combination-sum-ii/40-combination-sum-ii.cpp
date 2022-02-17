class Solution {
    void combination2Util(int index, vector<int> &candidates, int target, vector<int> &subArr, vector<vector<int>> &subArrWrapper) {
        int len = candidates.size();
        if (index > len) 
            return;
        if (target == 0) {
            subArrWrapper.emplace_back(subArr);
            return;
        }
        for (int i = index; i < len; i++) {
            if (candidates[i] <= target) {
//                 Below statement takes care of avoiding duplicates as we are receiving a sorted array and in the same recursion call if there are duplicate elements, they can be avoided while iterating through the loop
                if (i > index && candidates[i] == candidates[i-1]) 
                    continue;
                subArr.emplace_back(candidates[i]);
                combination2Util(i+1, candidates, target-candidates[i], subArr, subArrWrapper);
                subArr.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> subArrWrapper;
        sort(candidates.begin(), candidates.end());
        vector<int> subArr;
        combination2Util(0, candidates, target, subArr, subArrWrapper);
        return subArrWrapper;
    }
};