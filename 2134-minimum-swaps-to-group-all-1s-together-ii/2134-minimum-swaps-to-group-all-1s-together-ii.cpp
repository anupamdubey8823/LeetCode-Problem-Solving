class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int numslen = nums.size(), countofOnes = 0, noofHoles = INT_MAX;
        int totalOnes = count(nums.begin(), nums.end(), 1);
        // Sliding window is formed and no of holes/zeroes are counted in the window on every iteration.
        // That is min no of swaps required in that window.
        for (int start = 0, end = 0; start < numslen; start++) {
            while (end - start < totalOnes) {
                int currentIndex = end % numslen;
                countofOnes += nums[currentIndex];
                end++;
            }
            noofHoles = min(noofHoles, totalOnes - countofOnes);
            countofOnes -= nums[start]; // exclude the start index of the window so that it shifts one position to its right
        }
        return noofHoles;
    }
};