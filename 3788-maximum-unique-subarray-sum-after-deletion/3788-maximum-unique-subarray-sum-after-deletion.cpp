class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        unordered_set<int> st;
        for(int num:nums){
            st.insert(num);
        }
        for(auto & it:st){
            if(it>0){
                sum+=it;
            }
        }
        if(sum==0){
            sum = *max_element(nums.begin(), nums.end());
        }
        
        return sum;
    }
};