class Solution {
public:
    // int func(int ind, vector<int>& nums, vector<int>& dp){
    //     if (ind < 0) return 0;
    //     if (ind == 0) return nums[0];
    //     if (dp[ind] != -1) return dp[ind];

    //     int pick = nums[ind] + func(ind - 2, nums, dp);
    //     int notpick = func(ind - 1, nums, dp);

    //     return dp[ind] = max(pick, notpick);
    // }
//         int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1); 
//         return func(n - 1, nums, dp);
//     }
// };

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1); 
//         dp[0]=nums[0];
//         for(int i=1;i<nums.size();i++){
//             int pick=nums[i];
//              int notpick=0;
//             if(i>1){
//               pick += dp[i-2];
//             }
//         notpick = dp[i - 1];

//          dp[i] = max(pick, notpick);
//         }
//         return dp[n-1];
//     }
// };

  int rob(vector<int>& nums) {
        int n = nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
             int notpick=0;
            if(i>1){
              pick += prev2;
            }
        notpick = prev;

         int cur = max(pick, notpick);
         prev2=prev;
         prev=cur;
        }
        return prev;
    }
};