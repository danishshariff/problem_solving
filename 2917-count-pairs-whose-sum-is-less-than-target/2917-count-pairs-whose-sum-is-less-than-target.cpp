class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int left=0;
        int right=n-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum<target){
                count+=(right-left);
                left++;
            }
            else{
                right--;
            }
        }
        return count;
    }
};