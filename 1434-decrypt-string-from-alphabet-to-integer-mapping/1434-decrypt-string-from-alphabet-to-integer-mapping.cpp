class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        int i = s.size() - 1;

        while (i >= 0) {
            if (s[i] == '#') {
                // take 2 digits before '#'
                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                result += ('a' + num - 1);
                i -= 3; // move past these 3 chars
            } else {
                // single digit mapping
                int num = s[i] - '0';
                result += ('a' + num - 1);
                i--;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
