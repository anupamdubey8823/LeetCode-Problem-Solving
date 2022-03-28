class Solution {
    bool binSearch(int low, int high, vector<int> &nums, int target) {
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) {
                cout << nums[mid] << " ";
                return true;
            }
            else if (target > nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, numLen = nums.size();
        while (i+1 < numLen && nums[i] <= nums[i+1])
            i++;
//         Now we got [0,i] and [i+1, numLen) sorted search spaces. Hence, we apply Binary Search on both of 'em.
        if (binSearch(0, i, nums, target) || binSearch(i+1, numLen-1, nums, target))
            return true;
        return false;
    }
};