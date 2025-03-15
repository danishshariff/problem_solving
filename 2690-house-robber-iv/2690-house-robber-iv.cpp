class Solution {
public:
    bool canRobKWithCap(int cap, vector<int>& nums, int k) {
        int robbed = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= cap) {
                robbed++;
                i++;
            }
            if (robbed >= k) return true; 
        }
        return false; 
    }

    int minCapability(vector<int>& nums, int k) {
        
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int l = mini;
        int r = maxi;
        int ans = -1; 

      
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canRobKWithCap(mid, nums, k)) {
                ans = mid; 
                r = mid - 1; 
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
