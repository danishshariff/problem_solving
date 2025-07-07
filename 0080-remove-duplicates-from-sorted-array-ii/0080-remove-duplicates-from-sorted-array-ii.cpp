class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int i = 1; 
        int j = 2;

        while (j < nums.size()) {
            if (nums[j] != nums[i - 1]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }

        return i + 1;
    }
};
