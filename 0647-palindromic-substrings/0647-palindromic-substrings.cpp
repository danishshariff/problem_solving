class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(s[i]==s[j]){
                    count++;
                }
            }
        }
        return count;
    }
};