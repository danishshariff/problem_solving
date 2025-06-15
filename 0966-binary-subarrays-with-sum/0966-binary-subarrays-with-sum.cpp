class Solution {
public:
 int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0, r = 0, sum = 0, count = 0;
        int n = nums.size();
        
        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);  
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==goal){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};