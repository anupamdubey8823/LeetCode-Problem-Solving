class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int minOps = 0;
//         Since, we are dividing target each time it is odd by two, therefore, complexity ~ O(log n).
        while (target > startValue) {
            if (target % 2 == 0)
                target /= 2;
            else
                target += 1;
            minOps++;
        }
//         Since, now target <= startValue because while has terminated due to that itself, therefore,
//         we can add 1s to target to reach startValue;
        return minOps + startValue - target;
    }
};