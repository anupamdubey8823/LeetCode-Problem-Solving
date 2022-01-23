class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> rearrangedArr(len);
        int positiveIdx = 0, negativeIdx = 1;
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) {
                rearrangedArr[positiveIdx] = nums[i];
                positiveIdx += 2;
            }
            else {
                rearrangedArr[negativeIdx] = nums[i];
                negativeIdx += 2;
            }
        }
        return rearrangedArr;
    }
};