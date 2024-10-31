class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N=nums.size();
        // int sum= N*(N+1)/2;
        // int actuals=0;
        // for(int i=0;i<N;i++){
        //     actuals+=nums[i];
        // }
        // int res= sum-actuals;
        // return res;
        int xor1=0;
        int xor2=0;
        for(int i=0;i<N;i++){
            xor1=xor1^i;
            xor2=xor2^nums[i];
        }
       xor1=xor1^N;
        return xor1^xor2;
    }
};