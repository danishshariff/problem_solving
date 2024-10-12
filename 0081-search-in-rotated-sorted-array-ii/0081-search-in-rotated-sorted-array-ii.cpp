class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Prevents overflow
            
            // Check if the middle element is the target
            if (nums[mid] == target) {
                return true;
            }

            // If we encounter duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Left side is sorted
            else if (nums[low] <= nums[mid]) {
                // Check if the target is in the left sorted part
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right side is sorted
            else {
                // Check if the target is in the right sorted part
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};
