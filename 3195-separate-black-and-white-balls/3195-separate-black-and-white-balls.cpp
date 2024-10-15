class Solution {
public:
    long long minimumSteps(string s) {
        long long n = s.size();
        long long countOnes = 0, swapCount = 0, position = 0;
        
        // Traverse the string
        for (char c : s) {
            if (c == '1') {
                countOnes++;  // Count the number of black balls (1s)
            } else if (c == '0') {
                // For every '0' encountered, we count how many '1's are left of it
                // Those '1's should have been to the right, and thus need to be swapped
                swapCount += countOnes;
            }
        }
        
        return swapCount;
    }
};
