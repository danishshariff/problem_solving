class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
     vector<int> resul(n);
     int posi=0;
     int negi=1;
     for(int i=0;i<n;i++){
        if(nums[i]>0){
            resul[posi]=nums[i];
            posi+=2;
        }
        else{
            resul[negi]=nums[i];
            negi+=2;
        }
     }
     return resul;
    }
};