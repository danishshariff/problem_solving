class Solution {
public:
    int findMaxLength(vector<int>& nums) {
          unordered_map<int, int> prefixSumIndex;
        int maxlen = 0;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
         
            if (nums[i] == 0) {
                prefixSum += -1;
            } else {
                prefixSum += 1;
            }

            
            if (prefixSum == 0) {
                maxlen = i + 1;
            }

           
            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                
                maxlen = max(maxlen, i - prefixSumIndex[prefixSum]);
            } else {
                
                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxlen;
    }
};