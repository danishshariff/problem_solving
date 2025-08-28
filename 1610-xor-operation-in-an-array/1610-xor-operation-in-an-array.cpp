class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(start+2*i);
        }
        int res=0;
        for(int i=0;i<ans.size();i++){
            res=res^ans[i];
        }
        return res;
    }
};