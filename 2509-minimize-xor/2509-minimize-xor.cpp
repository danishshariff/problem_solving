class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int onesInNum1 = __builtin_popcount(num1);
        int onesInNum2 = __builtin_popcount(num2);
        int result = num1;

        for (int bit = 0; bit < 32; bit++) {
            if (onesInNum1 > onesInNum2 && ((1 << bit) & num1)) {
                result ^= (1 << bit);
                onesInNum1--;
            }
            if (onesInNum1 < onesInNum2 && !((1 << bit) & num1)) {
                result ^= (1 << bit);
                onesInNum1++;
            }
        }
        return result;
    }
};
