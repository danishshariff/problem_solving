class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool sign = true;
        //taking care of sign
        if(divisor < 0 && dividend >= 0) sign = false;
        else if(divisor > 0 && dividend <= 0) sign = false;
        long p = abs(dividend);
        long q = abs(divisor);
        long quotient = 0;
        while(p >= q) {
            int count = 0;
            //divisor << count+1 means divisor * 2^(count+1)
            while(p >= (q << (count+1)))
                count++;
            quotient += (1 << count); //2^count
            p -= (q << count);
        }
        //handling overflows
        if(quotient == (1 << 31) && sign)
            return INT_MAX;
        if(quotient == (1 << 31) && !sign)
            return INT_MIN;

        return sign? quotient : -quotient;
    }
};