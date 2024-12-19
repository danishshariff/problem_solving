class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ls;
        map<int,int> mpp;
        int mini=(int)(nums.size()/3)+1;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==mini){
                ls.push_back(nums[i]);
            }
        }
        return ls;
    }
};