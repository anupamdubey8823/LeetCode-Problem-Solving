class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> unique;
        for (auto &num: nums) {
            if (unique.count(num))
                unique.erase(unique.find(num));
            else 
                unique.insert(num);
        }
        int singleNum;
        for (auto &uniqueNum: unique) singleNum = uniqueNum;
        return singleNum;
    }
};