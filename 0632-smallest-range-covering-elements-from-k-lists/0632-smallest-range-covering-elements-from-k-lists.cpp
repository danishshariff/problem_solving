#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to keep track of the minimum value and its corresponding list and index
        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b); // Min-heap based on the first element
        };
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> minHeap(cmp);
        
        int currentMax = numeric_limits<int>::min();
        int start = 0, end = numeric_limits<int>::max();
        
        // Initialize the heap with the first elements of each list
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.emplace(nums[i][0], i, 0); // (value, list index, element index)
            currentMax = max(currentMax, nums[i][0]);
        }
        
        // While we can extract from all lists
        while (minHeap.size() == nums.size()) {
            auto [currentMin, listIndex, elementIndex] = minHeap.top();
            minHeap.pop();
            
            // Update the range
            if (currentMax - currentMin < end - start) {
                start = currentMin;
                end = currentMax;
            }
            
            // Move to the next element in the same list
            if (elementIndex + 1 < nums[listIndex].size()) {
                int nextValue = nums[listIndex][elementIndex + 1];
                minHeap.emplace(nextValue, listIndex, elementIndex + 1);
                currentMax = max(currentMax, nextValue); // Update the currentMax
            }
        }
        
        return {start, end};
    }
};
