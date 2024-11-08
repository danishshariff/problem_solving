class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k = (1 << maximumBit) - 1;
        int cur_xor = 0;
        
        for (int num : nums) {
            cur_xor ^= num;
        }
        
        vector<int> answer;
        for (int i = nums.size() - 1; i >= 0; --i) {
            answer.push_back(cur_xor ^ k);
            cur_xor ^= nums[i];
        }
        
        return answer;
    }
};
