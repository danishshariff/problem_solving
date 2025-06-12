class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         int maxans = 0;
//   unordered_set < int > set;
//   int l = 0;
//   for (int r = 0; r < s.length(); r++) 
//   {
//     if (set.find(s[r]) != set.end()) 
//     {
//       while (l < r && set.find(s[r]) != set.end()) {
//         set.erase(s[l]);

//         l++;
//       }
//     }
//     set.insert(s[r]);
//     maxans = max(maxans, r - l + 1);
//   }
//   return maxans;

  vector<int> mpp(256, -1);
    int l = 0;
    int maxl = 0;

    for (int r = 0; r < s.length(); r++) {
        if (mpp[s[r]] != -1) {
            l = max(mpp[s[r]] + 1, l);  // Move left if we see a repeating character
        }
        mpp[s[r]] = r;  // Mark the last seen index of character
        maxl = max(maxl, r - l + 1);  // Update max length
    }
    return maxl;
    }
};