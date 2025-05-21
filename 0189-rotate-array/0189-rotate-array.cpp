class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k is greater than the size of the array

        if (k == 0) return;  // No rotation needed

        // Step 1: Create a temporary vector to store the rotated elements
        vector<int> temp(n);

        // Step 2: Copy the last `k` elements from `nums` to the beginning of `temp`
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Step 3: Copy the first `n - k` elements from `nums` to the remaining part of `temp`
        for (int i = k; i < n; i++) {
            temp[i] = nums[i - k];
        }

        // Step 4: Copy the temporary array `temp` back to `nums`
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};
