class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                mx=max(mx,cnt);
            }
            else
            cnt=0;
        }
        return mx;
    }
};