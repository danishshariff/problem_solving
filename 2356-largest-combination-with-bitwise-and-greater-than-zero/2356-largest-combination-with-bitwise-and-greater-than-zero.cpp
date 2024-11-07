
class Solution {
public:
int largestCombination(vector<int>& candidates) {
    int maxCombinationSize = 0;

    
    for (int bit = 0; bit < 32; ++bit) {
        int count = 0;

        
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i] & (1 << bit)) {  
                count++;
            }
        }

       
        maxCombinationSize = max(maxCombinationSize, count);
    }

    return maxCombinationSize;
}
};
