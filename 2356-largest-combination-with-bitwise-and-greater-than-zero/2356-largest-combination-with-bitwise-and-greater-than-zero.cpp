
class Solution {
public:
int largestCombination(vector<int>& candidates) {
    int maxCombinationSize = 0;

    // Loop over each bit position (from 0 to 31 for 32-bit numbers)
    for (int bit = 0; bit < 32; ++bit) {
        int count = 0;

        // Count how many numbers have the current bit set
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i] & (1 << bit)) {  // Check if the current bit is set in candidates[i]
                count++;
            }
        }

        // Update the maximum size of the combination
        maxCombinationSize = max(maxCombinationSize, count);
    }

    return maxCombinationSize;
}
};
