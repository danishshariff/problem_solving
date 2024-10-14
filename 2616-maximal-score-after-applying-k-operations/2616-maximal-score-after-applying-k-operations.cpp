
class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Step 1: Create a max-heap (priority queue)
        std::priority_queue<int> pq(nums.begin(), nums.end());  // This automatically orders the nums as a heap.

        long long total_sum = 0;  // To store the total sum

        // Step 2: Perform k operations
        for (int i = 0; i < k; ++i) {
            // Step 3: Get the largest element (top of the heap)
            int max_val = pq.top();
            pq.pop();  // Remove it from the heap
            
            // Step 4: Add the maximum element to the total sum
            total_sum += max_val;
            
            // Step 5: Modify the maximum element (replace with ceil(max_val / 3))
            pq.push((max_val + 2) / 3);  // This is ceil(max_val / 3) without using the math library
        }

        return total_sum;  // Final result after k operations
    }
};
