class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int diff=0;
        int maxi=0;
        for(int i=1;i<n;i++){
            diff=abs(nums[i-1]-nums[i]);
            maxi=max(maxi,diff);
        }
        diff=abs(nums[0]-nums[n-1]);
        maxi=max(maxi,diff);

        return maxi;
    }
};