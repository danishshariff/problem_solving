class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string to easily access each digit
        string numStr = to_string(num);
        
        // Loop through each digit
        for (int i = 0; i < numStr.size(); i++) {
            // Find the largest digit after the current one
            char maxDigit = numStr[i];
            int maxIndex = i;
            
            // Search for a larger digit in the rest of the number
            for (int j = i + 1; j < numStr.size(); j++) {
                // We want the largest digit that's further in the number
                if (numStr[j] >= maxDigit) {
                    maxDigit = numStr[j];
                    maxIndex = j;
                }
            }
            
            // If we found a larger digit, swap it with the current one
            if (maxIndex != i && numStr[maxIndex] > numStr[i]) {
                swap(numStr[i], numStr[maxIndex]);
                break;  // We can stop after one swap
            }
        }

        // Convert the string back to an integer and return it
        return stoi(numStr);
    }
};
