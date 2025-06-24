class Solution {
public:

    // int myAtoi(string s) {
    //    int i=0;
    //    long ans=0;
    //    int sign=1;
    //    int n=s.size();
    //    while(i<s.size()&&s[i]==' '){
    //     i++;
    //    }
    //  if (i < n && (s[i] == '-' || s[i] == '+')) {
    //         sign = (s[i] == '-') ? -1 : 1;
    //         i++;
    //     }
    //    while(i<s.size()){
    //     if(s[i]==' '|| !isdigit(s[i])) break;
    //     ans=ans*10+s[i]-'0';
    //     if(sign==-1&& -1*ans<INT_MIN) return INT_MIN;
    //     if(sign==1&& sign*ans>INT_MAX) return INT_MAX;
    //     i++;

    //    }
    //    return (int)(sign*ans);
    // }

//recursive
    int helper(string &s, int i, long ans, int sign) {
        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(sign * ans);
        }

        ans = ans * 10 + (s[i] - '0');
        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -1 * ans < INT_MIN) return INT_MIN;

        return helper(s, i + 1, ans, sign);
    }
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Start recursion
        return helper(s, i, 0, sign);
    }

};