class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i < num.length() - 2; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string curr = string(3, num[i]);
                if (curr > ans) ans = curr;
            }
        }
        return ans;
    }
};
