class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int prev=INT_MIN;
        int longest=1;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]-1==prev){
                count+=1;
                prev=nums[i];
            }
            else if(prev!=nums[i]){
                count=1;
              prev=nums[i];
            }

            longest=max(longest,count);
        }
        return longest;
    }
};