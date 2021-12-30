class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 0, sizeofSmallest = 1;
        while (sizeofSmallest <= k) {
            remainder = (remainder*10 + 1) % k;
            if (remainder % k == 0)
                return sizeofSmallest;
            sizeofSmallest++;
        }
        return -1;
    }
};