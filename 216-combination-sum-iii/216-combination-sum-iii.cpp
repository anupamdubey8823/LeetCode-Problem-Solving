class Solution {
    void combinationUtil(int index, vector<int> &numsPool, int k, int target, vector<int> &subArr, vector<vector<int>> &subArrWrapper) {
        int len = numsPool.size();
        if (index > len || subArr.size() > k)
            return;
        if (target == 0 && subArr.size() == k) {
            subArrWrapper.emplace_back(subArr);
            return;
        }
        for (int i = index; i < len; i++) {
            if (numsPool[i] <= target) {
                subArr.emplace_back(numsPool[i]);
                combinationUtil(i+1, numsPool, k, target-numsPool[i], subArr, subArrWrapper);
                subArr.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> numsPool, subArr;
        for (int i = 1; i <= 9; i++) 
            numsPool.emplace_back(i);
        vector<vector<int>> subArrWrapper;
        combinationUtil(0, numsPool, k, n, subArr, subArrWrapper);
        return subArrWrapper;
    }
};