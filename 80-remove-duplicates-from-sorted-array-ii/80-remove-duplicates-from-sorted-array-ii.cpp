class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int replaceIndex = 0;
        for (auto &num: nums) {
            if (replaceIndex < 2 || num > nums[replaceIndex-2])
                nums[replaceIndex++] = num;
        }
        return replaceIndex;
    }
};