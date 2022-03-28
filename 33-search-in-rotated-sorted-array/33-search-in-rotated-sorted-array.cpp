class Solution {
    int binSearch(int low, int high, vector<int> &nums, int target) {
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target)
                return mid;
            else if (target > nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int i = 0, numLen = nums.size();
        while (i+1 < numLen && nums[i] < nums[i+1])
            i++;
        // if (target <= numLen - 1)
        //     return binSearch(i+1, numLen-1, nums, target);
        return max(binSearch(0, i, nums, target), binSearch(i+1, numLen-1, nums, target));
    }
};