class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       
        unordered_map<int, int> mpp;
        set<pair<int, int>> st;
        
        for (int num : nums) {
            mpp[num]++;
        }

        for (auto& it : mpp) {
            for (auto& it2 : mpp) {
                int x=it.first;
                int y=it2.first;
                if (x != y && abs(x - y) == k) {
                    int a=min(x,y);
                    int b=max(x,y);
                    st.insert({a, b});
                }
                else if(k==0 && x==y && it.second>1){
                    st.insert({x,y});
                }
            }
        }

        return st.size();
    }
};