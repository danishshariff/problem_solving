class Solution {
public:

        string largestOddNumber(string num) {
    int e = num.size() - 1;
    for (int i = e; i >= 0; i--) {
        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}


};