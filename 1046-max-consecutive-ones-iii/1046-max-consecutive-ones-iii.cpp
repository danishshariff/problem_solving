class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int maxlen = 0;
        // int l = 0;
        // int zeroes = 0;
        
        // for (int r = 0; r < nums.size(); r++) {
        //     if (nums[r] == 0) {
        //         zeroes++;
        //     }
            
        //     if (zeroes > k) {
        //         if (nums[l] == 0) {
        //             zeroes--;
        //         }
        //         l++;
        //     }
            
        //     maxlen = max(maxlen, r - l + 1);
        // }
        
        // return maxlen;

        int maxlen=0;
        int l=0;
        int r=0;
        int zero=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0){
                zero++;
            }
           
            if(zero>k){
                if(nums[l]==0){
                zero--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
