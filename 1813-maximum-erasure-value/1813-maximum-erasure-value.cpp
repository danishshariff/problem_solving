class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int j=0;
        int sum=0;
        int n=nums.size();
        int i=0;
        int maxi=0;
        while(j<n){
            mpp[nums[j]]++;
            sum+=nums[j];
            while(i<n && mpp[nums[j]]>1){
                sum-=nums[i];
                mpp[nums[i]]--;
                i++;

            }
         maxi=max(maxi,sum);
            j++;
        }
        return maxi;
    }
};