class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) // If x is negative, it can't be a palindrome
            return false;

        int original_x = x; // Store the original value of x

        int rev = 0;
        int lastd;
        while (x != 0) {
            lastd = x % 10;
            if ((rev > INT_MAX / 10) || (rev == INT_MAX / 10 && lastd > 7))
                return false; // Overflow check

            x = x / 10;
            rev = (rev * 10) + lastd;
        }

        return rev == original_x;
    }
};
