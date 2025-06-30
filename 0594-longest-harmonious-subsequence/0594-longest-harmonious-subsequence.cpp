class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxlen = 0;
        int i = 0, j = 0;
        int n = nums.size();

        while (j < n) {
            if (abs(nums[j] - nums[i])> 1) {
                i++;
            } else {
                if (abs(nums[j] - nums[i]) == 1) {
                    maxlen = max(maxlen, j - i + 1);
                }
                j++;
            }
        }

        return maxlen;
    }
};
