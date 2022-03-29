class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> findDup;
        int duplicate;
        for (auto &num:nums) {
            if (!findDup.count(num))
                findDup.insert(num);
            else {
                duplicate = num;
                break;
            }
        }
        return duplicate;
    }
};