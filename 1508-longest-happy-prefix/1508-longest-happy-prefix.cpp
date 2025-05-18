// class Solution {
// public:
//     string longestPrefix(string s) {
//         string longest="";
//         int n=s.length();
//         for(int i=0;i<n;i++){
//             if(s.substr(0,i)==s.substr(n-i,i)){
//                 longest=s.substr(0,i);
//             }
//         }
//         return longest;
//     }
// };

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);  // LPS array
        int len = 0;  // length of the previous longest prefix suffix

        // Build the LPS array
        for (int i = 1; i < n; ) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // lps[n-1] tells us the length of longest prefix which is also suffix
        return s.substr(0, lps[n - 1]);
    }
};
