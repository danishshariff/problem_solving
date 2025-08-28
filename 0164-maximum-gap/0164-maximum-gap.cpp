class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        if(nums.size()<2) return 0;
        for(int i=1;i<nums.size();i++){
            int diff=abs(nums[i-1]-nums[i]);
            if(diff>maxi){
                maxi=diff;
            }
        }
        return maxi;
    }
};