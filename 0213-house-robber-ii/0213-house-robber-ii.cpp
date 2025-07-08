class Solution {
public:
  int robber(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
         vector<int> arr1;
    vector<int> arr2;
    int n=nums.size();
    
    if(n==1)
       return nums[0];
    
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(nums[i]);
        if(i!=n-1) arr2.push_back(nums[i]);
    }
    
    long long int ans1 = robber(arr1);
    long long int ans2 = robber(arr2);
    
    return max(ans1,ans2);

    }
};