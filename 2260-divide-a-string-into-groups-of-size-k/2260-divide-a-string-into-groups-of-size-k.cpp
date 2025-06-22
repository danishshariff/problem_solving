class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n=s.length();
        for(int i=0;i<n;i+=k){
            string res=s.substr(i,k);
            if(res.length()<k){
                res.append(k-res.length(),fill);
            }
            ans.push_back(res);
        }
        
        return ans;
    }
};