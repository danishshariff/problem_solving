class Solution {
public:

    //optimal is bs lb and ub functions

    int lb(vector<int>& nums){
        int l=0;
        int n=nums.size();
        int r=n-1;
        int ind=nums.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<0){
                l=mid+1;
            }
            else if(nums[mid]>=0){
                r=mid-1;
                ind=mid;
            }
        }
        return ind;
    }

    
    int ub(vector<int>& nums){
        int l=0;
        int n=nums.size();
        int r=n-1;
        int ind=nums.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<=0){
                l=mid+1;
            }
            else if(nums[mid]>0){
                r=mid-1;
                ind=mid;
            }
        }
        return ind;
    }
    int maximumCount(vector<int>& nums) {
        // int neg=0;
        // int pos=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]<0){
        //         neg++;
        //     }
        //     else if(nums[i]>0){ 
        //         pos++;
        //     }
        //     else{
        //         continue;
        //     }
            
        // }
        // return max(neg,pos);
        int pos=nums.size()-ub(nums);
        int neg=lb(nums);
        return max(pos,neg);
    }
};