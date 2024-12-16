class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) { // Perform k operations
            int minValue = INT_MAX;
            int minIndex = -1;

            // Find the first occurrence of the minimum value
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < minValue) {
                    minValue = nums[i];
                    minIndex = i;
                }
            }

            // Replace the minimum value with minValue * multiplier
            nums[minIndex] = minValue * multiplier;
        }

        return nums;
    }
};
