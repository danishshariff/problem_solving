class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[n-1];
        for(int i=0;i<first.length();i++){
            if(first[i]!=last[i]){
                break;
            }
            res+=first[i];
        }
        return res;
    }
};