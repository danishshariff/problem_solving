// class Solution {
// public:
//  bool func(int ind,int sum,vector<int>& arr,vector<vector<int>>& dp){
//       if(sum==0) return true;
//       if(ind==0) return arr[0]==sum;
//       if(dp[ind][sum]!=-1) return dp[ind][sum];
//       bool nottake=func(ind-1,sum,arr,dp);
//       bool take=false;
//       if(sum>=arr[ind]){
//           take=func(ind-1,sum-arr[ind],arr,dp);
//       }
//       return dp[ind][sum]=take|| nottake;
//   }
//     bool canPartition(vector<int>& nums) {
//         int totalsum=0;
//         for(int i=0;i<nums.size();i++){
//             totalsum+=nums[i];
//         }

//         if(totalsum%2==1){
//             return false;
//         }
//         else{
//             int k=totalsum/2;
//             vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));

//         return func(nums.size() - 1, k, nums, dp);
//         }


//     }
// };


//tab
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

       
        if (totalSum % 2 == 1) {
            return false;
        }

        int k = totalSum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

       
        if (nums[0] <= k)
            dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTaken = dp[ind - 1][target];
                bool taken = false;
                if (nums[ind] <= target)
                    taken = dp[ind - 1][target - nums[ind]];

                dp[ind][target] = notTaken || taken;
            }
        }

        return dp[n - 1][k];
    }
};
