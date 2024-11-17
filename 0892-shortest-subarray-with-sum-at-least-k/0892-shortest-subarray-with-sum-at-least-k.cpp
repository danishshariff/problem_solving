class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // Initialize the shortest subarray length to a very large value (infinity).
        int shortest_Subarray_Length = numeric_limits<int>::max();
        
        // Get the size of the input array.
        int n = nums.size();
        
        // Initialize the prefix sum variable (sum of elements up to the current index).
        long long prefix_sum = 0;
        
        // Create a deque to store pairs of (prefix_sum, index).
        // This will help in efficiently finding subarrays whose sum is >= k.
        deque<pair<long long, int>> queue;
        
        // Initially, we add a pair (0, -1) to the deque. This represents the sum before the array starts (prefix sum 0 at index -1).
        queue.push_back({0, -1});

        // Iterate through the array to compute the prefix sums.
        for(int index = 0; index < n; ++index) {
            // Update the current prefix sum by adding the current element of the array.
            prefix_sum += nums[index];
            
            // Check if there exists a subarray with sum >= k.
            // If the current prefix sum minus the front element's prefix sum is greater than or equal to k,
            // we found a valid subarray.
            while(!queue.empty() && prefix_sum - queue.front().first >= k) {
                // Update the shortest subarray length by comparing the current length with the previous shortest length.
                shortest_Subarray_Length = min(shortest_Subarray_Length, index - queue.front().second);
                
                // Remove the front element from the deque since it is no longer needed.
                queue.pop_front();
            }

            // Ensure that the deque is ordered by increasing prefix sum.
            // Remove elements from the back of the deque where the current prefix sum is smaller than the last one.
            while(!queue.empty() && prefix_sum < queue.back().first) {
                queue.pop_back();
            }

            // Add the current prefix sum and its index to the deque.
            queue.push_back({prefix_sum, index});
        }

        // If no valid subarray was found, return -1.
        if(shortest_Subarray_Length == numeric_limits<int>::max()) {
            shortest_Subarray_Length = -1;
        }
        
        // Return the length of the shortest subarray whose sum is >= k.
        return shortest_Subarray_Length;
    }
};