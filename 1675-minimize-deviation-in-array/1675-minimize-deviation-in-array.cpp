class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int len = nums.size(), smallest = INT_MAX, largest = INT_MIN;
        for (int i = 0; i < len; i++) {
//             Multiplying every odd digit by 2.
            if (nums[i] & 1) nums[i] = nums[i] << 1;
            
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
        }
        int minDeviation = largest - smallest;
        
        priority_queue<int> maxHeap;
        for (auto &num: nums)
            maxHeap.push(num);
        
        while (!(maxHeap.top() & 1)) {
            int largestEven = maxHeap.top();
            maxHeap.pop();
            
            minDeviation = min(minDeviation, largestEven - smallest);
            largestEven = largestEven >> 1;
            smallest = min(smallest, largestEven);
            maxHeap.push(largestEven);
        }
        return minDeviation = min(minDeviation, maxHeap.top() - smallest);
    }
};