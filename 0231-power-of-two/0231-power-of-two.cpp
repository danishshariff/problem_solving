class Solution {
public:
    bool isPowerOfTwo(int n) {
        // First check if n is greater than 0
        if (n > 0 && (n & (n - 1)) == 0) {
            return true;
        } else {
            return false;
        }
    }
};
