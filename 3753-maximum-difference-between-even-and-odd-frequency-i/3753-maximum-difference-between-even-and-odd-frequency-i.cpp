#include <cmath> 
class Solution {
public:
    int maxDifference(string s) {
     map<char, int> mpp;
        int maxodd = INT_MIN;
        int mineven = INT_MAX;

        for (char c : s) {
          mpp[c]++;
        }
        for(auto it: mpp){
            if(it.second % 2 ==0){
               mineven=min(it.second,mineven);
            }
            else{
             maxodd=max(it.second,maxodd);

            }
        }
        return maxodd-mineven;
    }
};