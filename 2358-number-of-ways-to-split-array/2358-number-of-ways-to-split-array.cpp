class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0, leftSum = 0;
        int res = 0;

        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }

        for (int i = 0; i < nums.size()-1; i++) {
            leftSum += nums[i];
            if (leftSum >= totalSum - leftSum) {
                res++;
            }
        }
        
        return res;
    }
};