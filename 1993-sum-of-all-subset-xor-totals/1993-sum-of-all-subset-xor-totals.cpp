class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < (1 << nums.size()); i++) {
            int xorSum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    xorSum ^= nums[j];
                }
            }
            sum += xorSum;
        }
        return sum;
    }
};
