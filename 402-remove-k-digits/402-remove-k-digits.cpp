class Solution {
public:
    string removeKdigits(string nums, int k) {
        string afterRemoval = "";
        int len = nums.size(), digitsToKeep = len - k;
        // afterRemoval.push_back(nums[0]);
        for (int i = 0; i < len; i++) {
//             Keep popping the elems until ascending order is established again or k removals get exhausted
            while (afterRemoval.size() > 0 && k > 0 && nums[i] < afterRemoval.back()) {
                afterRemoval.pop_back();
                k--;
            }
            afterRemoval += nums[i];
        }
//         After removal of peaks, we are left with a number where each next digit is <= prev digit.
//         Hence, it makes sense to trim out the last digits of afterRemoval since we are only allowed to keep len() - k digits. And in the loop all the digits are processed as there is no constraint added for stopping after k removals. 
//         As per last line, we keep on adding digits.
//         So next line is for triming those last extra digits.
        afterRemoval.erase(afterRemoval.begin() + digitsToKeep, afterRemoval.end());
    
        int removalIndex = 0, postRemovalSize = afterRemoval.size();
//         Triming leading zeros
        while (removalIndex < postRemovalSize - 1 && afterRemoval[removalIndex] == '0') removalIndex++;
//         removalIndex < postRemovalSize - 1 ensures that atleast one digit is left after triming down zeros.
//         This ensures that in an answer such as "000", atleast "0" is preserved after triming down leading 2 zeros.
        afterRemoval.erase(0, removalIndex);
        return afterRemoval == "" ? "0" : afterRemoval;
//         We consider the "" case because if k == size of nums, then all digits are removed. But we need to return "0" in that case.
    }
};