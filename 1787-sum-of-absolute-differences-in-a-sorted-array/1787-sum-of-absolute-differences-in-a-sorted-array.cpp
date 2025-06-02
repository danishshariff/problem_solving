class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // vector<int> ans;
        // for(int i=0;i<nums.size();i++){
        //       int sum=0;
        //     for(int j=0;j<nums.size();j++){
        //         sum+=(abs(nums[i]-nums[j]));
        //     }
        //         ans.push_back(sum);
        // }
        // return ans;

        int totals=0;
        int n=nums.size();
        int lsum=0;
        vector<int> ans;
        for(auto a:nums){
            totals+=a;
        }

        for(int i=0;i<n;i++){
            int valleft=((nums[i]*i) - lsum);
            int valright=(totals-lsum - (nums[i]*(n-i)));
            lsum+=nums[i];
            ans.push_back(valleft+valright);
        }
        return ans;
    }
};