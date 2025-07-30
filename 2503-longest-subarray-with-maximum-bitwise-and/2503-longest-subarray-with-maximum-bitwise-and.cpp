class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int streak=0;
        int maxstreak=0;
    for(int i=0;i<n;i++){
        if(nums[i]==maxi){
            streak++;
            maxstreak=max(maxstreak,streak);
        }
            else{
                streak=0;
            }
        
    }
    return maxstreak;
    }
};