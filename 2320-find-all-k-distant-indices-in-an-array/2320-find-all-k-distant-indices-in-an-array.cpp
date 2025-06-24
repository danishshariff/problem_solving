class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
       int n=nums.size();
       vector<int> idx;
       vector<int> ans;

       for(int i=0;i<n;i++){
        if(nums[i]==key){
            idx.push_back(i);
        }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<idx.size();j++){
            if(abs(i-idx[j])<=k){
                ans.push_back(i);
                break;
            }
        }
       }
       return ans;
    }
};