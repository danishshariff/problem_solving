class Solution {
public:
 bool func(int ind,int sum,vector<int>& arr,vector<vector<int>>& dp){
      if(sum==0) return true;
      if(ind==0) return arr[0]==sum;
      if(dp[ind][sum]!=-1) return dp[ind][sum];
      bool nottake=func(ind-1,sum,arr,dp);
      bool take=false;
      if(sum>=arr[ind]){
          take=func(ind-1,sum-arr[ind],arr,dp);
      }
      return dp[ind][sum]=take|| nottake;
  }
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }

        if(totalsum%2==1){
            return false;
        }
        else{
            int k=totalsum/2;
            vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));

        return func(nums.size() - 1, k, nums, dp);
        }


    }
};