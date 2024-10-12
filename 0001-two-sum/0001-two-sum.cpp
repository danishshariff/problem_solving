class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int moreNeeded=target-num;
            if(mpp.find(moreNeeded)!=mpp.end()){
                return{mpp[moreNeeded],i};
            }
             mpp[num]=i;
        }
       return{-1,-1};
    }
};