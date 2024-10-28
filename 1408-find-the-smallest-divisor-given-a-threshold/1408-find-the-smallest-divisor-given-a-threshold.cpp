class Solution {
public:
    int sumofd(vector<int>& arr, int divisor){
        int n=arr.size();
            int sum=0;
       
            for(int i=0;i<=n-1;i++){
                sum+= ceil((double)arr[i]/(double)divisor);
            }
        
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        if(n>threshold){
            return -1;

        }
        while(low<=high){
            int mid=(low+high)/2;
            if(sumofd(nums,mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};