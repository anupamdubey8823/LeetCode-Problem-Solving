class Solution {
public:
    int findNthDigit(int n) {
        int digits = 1, index;
        long int base = 9;
//         Finding the no. of digits
        while (n - (base*digits) > 0) {
            n = n - (base*digits);
            base *= 10;
            digits++;
        }
//         Finding the number itself
        index = n % digits;
        if (index == 0)
            index = digits;
        long int baseNum = 1;
        for (int i = 1; i < digits; i++) {
            baseNum *= 10;
        }
        baseNum += (index == digits) ? (n/digits) - 1 : (n / digits);
//         Finding the digit we wanted from the above found number
        for (int i = index; i < digits; i++) {
            baseNum /= 10;
        }
        return baseNum % 10;
    }
};