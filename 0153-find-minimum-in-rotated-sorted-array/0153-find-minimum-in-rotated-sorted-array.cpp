// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n=nums.size();
//         int low=0,high=n-1,ans=INT_MAX;
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(nums[low]<=nums[mid]){
//                 ans=min(ans,nums[low]);
//                 low=mid+1;
//             }
//             else{
//                 ans=min(ans,nums[mid]);
//                 high=mid-1;

//             }
        
//         if(nums[low]<=nums[high]){
//             ans=min(ans,nums[low]);
//             break;
//         }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, ans = INT_MAX;
        
        while (low <= high) {
            // If the array portion is already sorted, return the leftmost element
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;  // No need to search further
            }

            int mid = low + (high - low) / 2;

            // Update the answer with the minimum of the current window
            ans = min(ans, nums[mid]);

            // If the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Move to the right half
                low = mid + 1;
            } 
            // If the right half is sorted
            else {
                // Move to the left half
                high = mid - 1;
            }
        }
        return ans;
    }
};
