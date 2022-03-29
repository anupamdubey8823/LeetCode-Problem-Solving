class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
//         fast = 4, slow = 3;
//         slow = 2, fast = 4;
//         slow = 4, fast = 4;
        
//         slow = 3, fast = 4;
//         slow = 4, fast = 3;
//         slow = 2, fast = 2;
        
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
//         fast = 0, slow = 4;
//         fast = 1, slow = 2;
//         fast = 3, slow = 4;
//         fast = 2, slow = 2;
        
//         fast = 0, slow = 2;
//         fast = 3, slow = 3;
        return slow;
    }
};