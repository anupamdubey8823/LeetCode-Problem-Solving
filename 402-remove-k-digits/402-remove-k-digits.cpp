class Solution {
public:
    string removeKdigits(string nums, int k) {
        int numLen = nums.size();
        if (k >= numLen) 
            return "0";
        for (int j = 0; j < k; j++) {
            int i = 0;
            while (i < numLen-1 && nums[i] <= nums[i+1])
                i++;
            nums.erase(nums.begin() + i);
        }
        int i = 0;
        while (i < numLen && nums[i] == '0')
            i++;
        nums.erase(nums.begin(), nums.begin() + i);
        
        return nums == "" ? "0" : nums;
    }
};