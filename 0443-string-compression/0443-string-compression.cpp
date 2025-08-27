class Solution {
public:
    int compress(vector<char>& chars) {
        int ind = 0;  // write pointer
        for (int i = 0; i < chars.size(); i++) {
            char ch = chars[i];
            int count = 0;

            // Count group length
            while (i < chars.size() && chars[i] == ch) {
                count++;
                i++;
            }

            // Write the character
            chars[ind++] = ch;

            // Write the count if > 1
            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    chars[ind++] = dig;
                }
            }

            i--; // because outer for-loop also increments i
        }
        return ind;
    }
};
